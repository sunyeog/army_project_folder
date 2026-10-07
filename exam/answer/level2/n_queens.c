#include <stdio.h>	// fprintf, stdout
#include <stdlib.h>	// atoi, malloc, free

/*
** [n_queens] 처음부터 작성
**
** 핵심 아이디어: "열(column)마다 퀸을 딱 하나씩" 놓는다
**   pos[col] = row  ->  col번째 열의 퀸은 row번째 줄에 있다
**   (출력 형식 "p1 p2 p3 ..."이 바로 이 pos 배열 그대로!)
**
** 백트래킹 흐름:
**   solve(col):
**     col == n 이면 다 놓았음 -> 출력
**     row를 0..n-1 다 시도:
**       안전하면 pos[col] = row 놓고 solve(col + 1)
**       (돌아오면 다음 row를 시도 = 자동으로 되돌리기)
**
**   예) n=4                 열: 0 1 2 3
**       pos = {1,3,0,2}     줄0 . . Q .
**                           줄1 Q . . .
**                           줄2 . . . Q
**                           줄3 . Q . .
*/

/* ============================================================
** is_safe: 지금까지 놓은 열(0 ~ col-1)과 부딪히는지 검사
**   같은 줄       : pos[i] == row
**   같은 대각선   : 줄 차이 == 열 차이
**                   |pos[i] - row| == col - i
** (같은 열은 애초에 열마다 하나씩 놓으니 검사 필요 없음)
** ============================================================ */
int	is_safe(int *pos, int col, int row)
{
	int	i = 0;
	int	d;

	while (i < col)
	{
		d = pos[i] - row;
		if (d < 0)
			d = -d;	// 절댓값 (abs는 허용 함수가 아님)
		if (pos[i] == row || d == col - i)
			return (0);
		i++;
	}
	return (1);
}

/* ============================================================
** print_solution: "1 3 0 2\n" 형식 (마지막 숫자 뒤엔 공백 없음)
** ============================================================ */
void	print_solution(int *pos, int n)
{
	int	i = 0;

	while (i < n)
	{
		fprintf(stdout, "%d", pos[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

/* ============================================================
** solve: col번째 열에 퀸 놓기를 시도
** ============================================================ */
void	solve(int *pos, int n, int col)
{
	int	row = 0;

	if (col == n)	// 모든 열에 다 놓음 = 해답 1개
	{
		print_solution(pos, n);
		return ;
	}
	while (row < n)
	{
		if (is_safe(pos, col, row))
		{
			pos[col] = row;	// 놓고
			solve(pos, n, col + 1);	// 다음 열로
		}	// 돌아오면 다음 row로 덮어쓰기 = 되돌리기
		row++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*pos;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n <= 0)
		return (0);
	pos = malloc(sizeof(int) * n);
	if (!pos)
		return (1);
	solve(pos, n, 0);
	free(pos);
	return (0);
}
