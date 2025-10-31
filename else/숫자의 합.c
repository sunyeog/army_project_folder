#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    int i = 0;
    
    scanf("%d", &a);
    
    while (i < a)
    {
        scanf("%d", &b);
        c += b;
        i++;
    }
    printf("%d\n", c);
    return (0);
}