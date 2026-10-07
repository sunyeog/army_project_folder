#include <stdio.h>	// printf
#include <stdlib.h>	// atoi, malloc, free

/*
** [powerset] 처음부터 작성
**
** 핵심 아이디어: 원소마다 "뺀다 / 넣는다" 두 갈래로 나눈다
**   원소가 k개면 갈래 끝(잎)이 2^k개 = 모든 부분집합
**   잎에 도착했을 때 합이 target이면 출력
**
**   원소를 앞에서부터 순서대로 결정하므로
**   출력되는 부분집합 안의 순서도 자동으로 원래 순서와 같다
**
**   예) set = {1, 2}, target = 3
**               시작
**            /        \
**        1 뺌          1 넣음
**        /   \         /    \
**     2 뺌  2 넣음   2 뺌   2 넣음
**      {}    {2}     {1}    {1 2}  <- 합 3! 출력
*/

/* ============================================================
** print_subset: "1 0 2\n" 형식, 빈 부분집합은 빈 줄 "\n"
** ============================================================ */
void	print_subset(int *sub, int size)
{
	int	i = 0;

	while (i < size)
	{
		printf("%d", sub[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

/* ============================================================
** solve
**   set  : 원래 집합 / n : 원소 개수
**   idx  : 지금 결정할 원소 번호
**   sub  : 지금까지 넣은 원소들 / size : 그 개수
**   sum  : sub의 합 / target : 목표 합
** ============================================================ */
void	solve(int *set, int n, int idx, int *sub, int size, int sum, int target)
{
	if (idx == n)	// 모든 원소를 다 결정함 = 잎
	{
		if (sum == target)
			print_subset(sub, size);
		return ;
	}
	// 갈래 1: set[idx]를 뺀다 -> 아무것도 안 바꾸고 다음 원소로
	solve(set, n, idx + 1, sub, size, sum, target);
	// 갈래 2: set[idx]를 넣는다 -> sub 끝에 추가, 합에 더하기
	sub[size] = set[idx];
	solve(set, n, idx + 1, sub, size + 1, sum + set[idx], target);
	// 되돌리기 불필요: size를 값으로 넘기므로 돌아오면 원래 size 그대로
}

int	main(int ac, char **av)
{
	int	n;
	int	i;
	int	*set;
	int	*sub;

	if (ac < 3)	// target + 원소 최소 1개
		return (1);
	n = ac - 2;	// av[0]=프로그램, av[1]=target, 나머지가 집합
	set = malloc(sizeof(int) * n);
	sub = malloc(sizeof(int) * n);
	if (!set || !sub)
	{
		free(set);
		free(sub);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
	solve(set, n, 0, sub, 0, 0, atoi(av[1]));
	free(set);
	free(sub);
	return (0);
}
