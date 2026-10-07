#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/*
** [tsp] 주어진 뼈대에 함수 3개(+ swap 1개)를 채우는 문제
**       main은 [변경 없음]
**       컴파일: gcc ... tsp.c -lm   (sqrtf 때문에 -lm 필수)
**
** 핵심 아이디어: 도시 방문 순서를 "전부" 만들어 보고 가장 짧은 것 고르기
**   - path = 방문 순서 (예: {0, 2, 1, 3})
**   - 순서 만들기 = permutations와 똑같은 백트래킹 (여기선 swap 방식)
**   - 첫 도시(0)는 고정: 원형 경로라 어디서 출발하든 길이가 같음
**     -> main이 solve(..., pos = 1)로 부르는 이유
**
**   순열 swap 방식 (pos 자리에 i번째를 데려오기):
**     path = {0, 1, 2, 3}, pos = 1
**       i=1: {0, 1, 2, 3} -> pos 2로 ...
**       i=2: {0, 2, 1, 3} -> pos 2로 ...   (1과 2를 swap)
**       i=3: {0, 3, 2, 1} -> pos 2로 ...   (1과 3을 swap)
**     돌아올 때마다 다시 swap해서 원상복구
*/

typedef struct s_city
{
	float x;
	float y;
}	t_city;

/* ============================================================
** distance
** [추가] 두 점 사이 거리 = sqrt(dx^2 + dy^2)  (피타고라스)
** ============================================================ */
float	distance(t_city a, t_city b)
{
	float	dx = a.x - b.x;	// [추가]
	float	dy = a.y - b.y;	// [추가]

	return (sqrtf(dx * dx + dy * dy));	// [추가]
}

/* ============================================================
** total_distance
** [추가] path 순서대로 이웃끼리 거리를 더하고
**        마지막 도시 -> 첫 도시로 "돌아오는 거리"까지 더함
**        (원형 경로! 이걸 빼먹으면 답이 틀림)
** ============================================================ */
float	total_distance(t_city *cities, int *path, int n)
{
	float	sum = 0;	// [추가]
	int		i = 0;	// [추가]

	while (i < n - 1)	// [추가] 0->1, 1->2, ..., (n-2)->(n-1)
	{
		sum += distance(cities[path[i]], cities[path[i + 1]]);	// [추가]
		i++;	// [추가]
	}
	sum += distance(cities[path[n - 1]], cities[path[0]]);	// [추가] 마지막 -> 처음
	return (sum);	// [추가]
}

/* ============================================================
** swap
** [추가] 뼈대에 없는 보조 함수 (solve에서 사용)
** ============================================================ */
void	swap(int *a, int *b)
{
	int	tmp = *a;	// [추가]

	*a = *b;	// [추가]
	*b = tmp;	// [추가]
}

/* ============================================================
** solve
** [추가] pos == n 이면 순서 하나 완성 -> 길이 재서 최솟값 갱신
**        아니면 pos 자리에 pos..n-1 번째를 하나씩 swap해서 넣어 보고
**        재귀 후 swap으로 되돌리기
** ============================================================ */
void	solve(t_city *cities, int *path, int n, int pos, float *min)
{
	float	d;	// [추가]
	int		i;	// [추가]

	if (pos == n)	// [추가] 순서 하나 완성
	{
		d = total_distance(cities, path, n);	// [추가]
		if (d < *min)	// [추가]
			*min = d;	// [추가] 더 짧으면 갱신
		return ;	// [추가]
	}
	i = pos;	// [추가]
	while (i < n)	// [추가]
	{
		swap(&path[pos], &path[i]);	// [추가] i번째를 pos 자리로
		solve(cities, path, n, pos + 1, min);	// [추가] 다음 자리
		swap(&path[pos], &path[i]);	// [추가] 되돌리기
		i++;	// [추가]
	}
}

/* ============================================================
** main
** [변경 없음] 주어진 그대로
** ============================================================ */
int	main(void)
{
	t_city	cities[11];
	int		n = 0;

	// Read input from stdin
	while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;

	// If less than 2 cities → distance = 0
	if (n < 2)
	{
		printf("0.00\n");
		return (0);
	}

	// Initialize path: [0,1,2,...]
	int path[11];
	for (int i = 0; i < n; i++)
		path[i] = i;

	float min = FLT_MAX;

	/*
	** Optimization:
	** Fix first city → start from pos = 1
	*/
	solve(cities, path, n, 1, &min);

	printf("%.2f\n", min);
	return (0);
}
