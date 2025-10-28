#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    int i = 0;
    int s_i = 0;
    while (i < 10)
    {
        scanf("%d", &a);
        if (a > b)
        {
            b = a;
            s_i = i;
        }
        i++;
    }
    printf("%d\n%d\n", b, s_i+1);
    return (0);
    
}