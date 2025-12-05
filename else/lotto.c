#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	find_equal(int *a)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	while (i<6)
	{
		j = 0;
		cnt = 0;
		while (j<6)
		{
			if(*(a + i) == *(a + j))
				cnt++;
			j++;
		}
		if (cnt >= 2)
			return (0);
		i++;
	}
	return (1);
}

void sort(int *arr)
{
	int	temp;
    for (int i = 0; i < 6 - 1; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
	int rnd;
	int a[6];
	int	res;

	retry:
	srand(time(NULL));
	for(int i = 0; i < 6;i++)
	{
		rnd = (rand() % 45) + 1;
		a[i] = rnd;
	}
	res = find_equal(a);
	if (res == 0)
		goto retry;
	int	i = 0;
	sort(a);
	while (i < 6)
	{
		printf("[%d]\n", a[i]);
		i++;
	}
	return (0);
}