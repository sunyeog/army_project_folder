#include <stdio.h>

int    search(int arr[], int a)
{
    int i = 0;
    while (i < 28)
    {
        if (arr[i] == a)
            return (0);
        i++;
    }
    return (1);
}

int main()
{
    int    a = 0;
    int arr[28] = {0};
    int res = 0;
    for(int i = 0; i < 28; i++)
    {
        scanf("%d", &a);
        arr[i] = a;
    }
    int i = 1;
    while (i < 31)
    {
        if (search(arr, i) == 1)
        {
            printf("%d\n", i);
            res++;
        }
        if (res == 2)
            return (0);
        i++;
    }
    return (0);
}