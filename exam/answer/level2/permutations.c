#include <stdio.h>	// puts
#include <stdlib.h>	// malloc, calloc, free

/*
** [permutations] 처음부터 작성
**
** 핵심 아이디어 (2단계):
**   1) 입력을 먼저 알파벳순으로 정렬한다     "bca" -> "abc"
**   2) 자리(pos)마다 "아직 안 쓴 글자"를 앞에서부터 하나씩 넣어 본다
**      -> 앞 글자부터 차례로 시도하니 출력이 자동으로 알파벳순!
**
**   재귀 한 단계 = "pos번째 자리에 어떤 글자를 둘지" 정하기
**
**   pos0   pos1   pos2      출력
**    a  ->  b  ->  c        abc
**           c  ->  b        acb
**    b  ->  a  ->  c        bac
**           c  ->  a        bca
**    c  ->  a  ->  b        cab
**           b  ->  a        cba
*/

int	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return (i);
}

/* ============================================================
** sort_str: 버블 정렬 (옆 글자와 비교해서 크면 자리 바꾸기)
** ============================================================ */
void	sort_str(char *s, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (s[j] > s[j + 1])
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/* ============================================================
** solve: res의 pos번째 자리를 채운다
**   src  : 정렬된 원본
**   used : used[i] == 1 이면 src[i]는 이미 사용 중
**   res  : 만들고 있는 결과 문자열
** ============================================================ */
void	solve(char *src, int *used, char *res, int pos, int len)
{
	int	i = 0;

	if (pos == len)	// 모든 자리를 다 채움
	{
		puts(res);	// puts는 끝에 '\n'을 자동으로 붙여 줌
		return ;
	}
	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;	// 사용 표시
			res[pos] = src[i];	// 이 자리에 놓기
			solve(src, used, res, pos + 1, len);
			used[i] = 0;	// 되돌리기 (다른 글자도 시도할 수 있게)
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		len;
	int		*used;
	char	*res;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	used = calloc(len + 1, sizeof(int));	// 0으로 초기화 = 전부 안 씀
	res = calloc(len + 1, sizeof(char));	// 끝에 '\0'이 이미 들어 있음
	if (!used || !res)
	{
		free(used);
		free(res);
		return (1);
	}
	sort_str(av[1], len);	// 1) 정렬
	solve(av[1], used, res, 0, len);	// 2) 생성
	free(used);
	free(res);
	return (0);
}
