/*
 * filter — 정답본
 *
 * 하는 일: stdin을 끝까지 읽어서, 인자 문자열이 나올 때마다
 *          그 길이만큼 '*'로 바꿔 stdout에 출력 (예: abc → ***, sed와 동일)
 *
 * 외우기: "다 모으고 → 손가락 두 개로 훑으며 [앞부분 · 별표 · 점프] → 꼬리 출력"
 */

/* memmem은 GNU 확장 함수 → 반드시 모든 #include보다 위에! (없으면 -Werror로 컴파일 실패) */
#define _GNU_SOURCE
#include <unistd.h>    /* read, write */
#include <stdlib.h>    /* realloc, free */
#include <string.h>    /* memmem, memmove, strlen */
#include <stdio.h>     /* perror */
#include <errno.h>     /* perror가 읽는 errno */

/*
 * read 한 번에 받을 "최대" 글자 수.
 * 채점기는 가짜 read로 매번 랜덤한 개수만 주므로 값은 아무거나 괜찮다.
 */
#define BUFSIZE 1024

/*
 * 에러 처리 3종 세트: 메시지 → 정리 → 반환값 1
 * perror("Error") 는 stderr에 "Error: <이유>\n" 을 찍어 준다.
 *   → "Error\n" 처럼 개행을 넣으면 "Error\n: <이유>" 가 되니 주의!
 * perror를 먼저 부르는 이유: 다른 함수가 errno를 덮어쓰기 전에 출력하려고.
 * free(NULL)은 아무 일도 안 하므로 buf가 NULL이어도 안전하다.
 */
static int	error(char *buf)
{
	perror("Error");
	free(buf);
	return (1);
}

int	main(int ac, char **av)
{
	char	tmp[BUFSIZE];   /* 택배 상자: read가 매번 새로 채움 */
	char	*buf = NULL;    /* 창고: 지금까지 읽은 전부 (처음엔 없음) */
	char	*new;           /* realloc 결과를 먼저 받아 둘 임시 변수 */
	size_t	total = 0;      /* 창고에 쌓인 글자 수 */
	ssize_t	n;              /* read 반환값. -1이 올 수 있어서 ssize_t */

	/*
	 * 인자 검사: 정확히 1개 + 빈 문자열 아님
	 * ac != 2 가 먼저라서, 인자가 없을 때 av[1]을 건드리지 않는다. (|| 단축평가)
	 */
	if (ac != 2 || av[1][0] == '\0')
		return (1);

	/* ================= 1단계: 모으기 ================= */
	/*
	 * 왜 전부 모으나?
	 *   read가 "bon" + "jour" 처럼 쪼개서 줄 수 있어서,
	 *   조각마다 찾으면 경계에 걸친 단어를 놓친다.
	 *
	 * n > 0  : 받은 조각을 창고 뒤에 붙이고 계속
	 * n == 0 : EOF (정상 종료 신호) → 루프 탈출
	 * n < 0  : 에러 → 루프 탈출 후 아래에서 처리
	 */
	while ((n = read(0, tmp, BUFSIZE)) > 0)
	{
		/*
		 * 창고 크기 = 기존 짐(total) + 새 상자(n)
		 * 첫 바퀴엔 buf == NULL → realloc(NULL, n) == malloc(n)
		 * '\0'을 안 붙이므로 +1 없음 (길이 total로만 다룬다)
		 */
		new = realloc(buf, total + n);
		/*
		 * realloc 실패: NULL 반환, 옛 buf는 그대로 살아 있음 → 반납해야 함
		 * buf = realloc(buf, ...) 로 바로 받으면 옛 주소를 잃어 누수!
		 */
		if (!new)
			return (error(buf));
		/*
		 * realloc 성공: 옛 buf는 이미 반납됨 → 절대 free 금지
		 * 새 주소로 갈아타기 (이 줄이 없으면 반납된 메모리에 쓰게 된다)
		 */
		buf = new;
		/*
		 * 기존 짐 바로 뒤(buf + total)에 새 상자를 푼다
		 *   buf: [b o n _ _ _ _]   total = 3
		 *               ↑ buf + 3
		 * memcpy는 허용 목록에 없어서 memmove 사용 (사용법 동일)
		 */
		memmove(buf + total, tmp, n);
		total += n;
	}
	/* 루프가 끝난 이유 구분 */
	if (n < 0)                  /* read 에러 */
		return (error(buf));
	if (!buf)                   /* 입력 0글자 (printf '' | ./filter abc) */
		return (0);             /* 주의: echo '' 는 "\n" 1글자라 여기 안 걸림 */

	/* ================= 2단계: 찾아서 가리기 ================= */
	size_t	len = strlen(av[1]);   /* 금지어 길이 = 찍을 별표 개수 */
	char	*start = buf;          /* 손가락 1: 아직 출력 안 한 부분의 시작 */
	size_t	rest = total;          /* start부터 남은 글자 수 (start와 한 세트) */
	char	*p;                    /* 손가락 2: memmem이 찾은 금지어 위치 */
	size_t	i;

	/*
	 * memmem(찾을 곳, 그 길이, 찾는 것, 그 길이)
	 *   → 찾으면 그 위치 주소, 못 찾으면 NULL
	 *   → strstr과 달리 길이를 받아서 입력 중간의 '\0'에도 안 멈춘다
	 *
	 * 예) buf = "123abc456", 금지어 "abc"
	 *       1 2 3 a b c 4 5 6
	 *       ↑     ↑
	 *     start   p          p - start = 3 = 금지어 앞 글자 수
	 */
	while ((p = memmem(start, rest, av[1], len)))
	{
		/* ① 금지어 앞부분 출력: "123" */
		write(1, start, p - start);
		/* ② 별표 len개 출력: "***" */
		i = 0;
		while (i++ < len)
			write(1, "*", 1);
		/*
		 * ③ 남은 양 줄이기: (앞부분 3) + (금지어 3) = 6 차감 → rest = 3
		 *    반드시 start를 옮기기 "전에" 계산!
		 *    순서를 바꾸면 p - start = -len 이 되어 rest가 안 줄고,
		 *    마지막 write가 창고 밖을 읽는다.
		 */
		rest -= (p - start) + len;
		/*
		 * ④ 금지어 뒤로 점프 → start는 '4'를 가리킴
		 *    len만큼 건너뛰므로 이미 가린 부분을 다시 찾지 않는다
		 *    ("ababcabababc" → "*****ab*****")
		 */
		start = p + len;
	}
	/*
	 * 더 못 찾음 → 남은 꼬리 출력: "456"
	 * 금지어가 한 번도 없었으면 start = buf, rest = total 이라 전체가 출력된다.
	 */
	write(1, start, rest);
	free(buf);
	return (0);
}
