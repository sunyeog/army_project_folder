#include <stdio.h>
#include <stdbool.h>

int cal(bool arr[])
{
    int res = 0;
    for(int i = 0; i < 42; i++)
    {
        if (arr[i] == true)
            res++;
    }
    return (res);
}

int res(bool arr[], int num[])
{
    int i = 0;
    while(i < 10)
    {
        arr[num[i] % 42] = true;
        i++;
    }
    return (cal(arr));
}

int main()
{
    bool arr[42] = {false};
    int i = 0;
    int num[10] = {0};
    while (i < 10)
    {
        scanf("%d", &num[i]);
        i++;
    }
    printf("%d\n", res(arr, num));
    return (0);
}