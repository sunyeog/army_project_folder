#define _GNU_SOURCE	// memmem을 쓰려면 include보다 먼저!
#include <string.h>	// strlen, memmem, memmove
#include <stdlib.h>	// realloc, free
#include <unistd.h>	// read, write
#include <stdio.h>	// perror
#include <errno.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/*
** 전체 흐름 (3단계만 기억):
**   1) stdin을 끝까지 다 읽어서 하나의 큰 버퍼(res)에 모은다
**   2) memmem으로 패턴을 찾을 때마다 그 자리를 '*'로 덮는다
**   3) res를 통째로 write 한다
**
** 왜 "다 읽고 나서" 처리하나?
**   read는 매번 몇 글자 올지 모름 (예: "ab" + "c")
**   조각마다 처리하면 경계에 걸친 "abc"를 놓친다.
**   -> 다 모은 뒤 처리하면 경계 문제가 아예 없다.
*/

int	main(int ac, char **av)
{
	char	buf[BUFFER_SIZE];	// read 한 번에 받는 임시 그릇
	char	*res = NULL;	// 지금까지 읽은 전체 내용
	char	*tmp;
	char	*p;
	size_t	total = 0;	// res에 들어있는 바이트 수
	size_t	len;	// 패턴 길이
	size_t	i;
	ssize_t	r;

	// 인자는 정확히 1개, 빈 문자열이면 안 됨
	if (ac != 2 || av[1][0] == '\0')
		return (1);
	len = strlen(av[1]);

	// ---------- 1) 끝까지 읽어서 res에 이어 붙이기 ----------
	while ((r = read(0, buf, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(res, total + r);	// 늘린 만큼 새 공간
		if (!tmp)
		{
			free(res);	// realloc 실패해도 기존 res는 살아있음 -> 해제
			perror("Error");	// 출력: "Error: Cannot allocate memory"
			return (1);
		}
		res = tmp;
		memmove(res + total, buf, r);	// 기존 내용 뒤에 붙이기
		total += r;
	}
	if (r < 0)	// read 에러
	{
		free(res);
		perror("Error");
		return (1);
	}

	// ---------- 2) 패턴을 찾아서 '*'로 덮기 ----------
	// memmem(어디서, 남은길이, 무엇을, 그길이) -> 찾은 위치 or NULL
	p = res;
	while (p && (p = memmem(p, total - (p - res), av[1], len)))
	{
		i = 0;
		while (i < len)
			p[i++] = '*';
		p += len;	// 덮은 부분 다음부터 다시 찾기 (sed와 동일)
	}

	// ---------- 3) 출력 ----------
	if (total > 0)
		write(1, res, total);
	free(res);
	return (0);
}
