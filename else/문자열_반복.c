#include <stdio.h>

void prt_res(int b, char str[])
{
    int i = 0;
    int j = 0;
    while(str[i])
    {
        j = 0;
        while(j < b)
        {
            printf("%c", str[i]);
            j++;
        }
        i++;
    }
}

int main()
{
    int a = 0, b = 0;
    int i = 0;
    char str[21];
    scanf("%d", &a);
    while(i < a)
    {
        scanf("%d %s", &b, str);
        prt_res(b, str);
        printf("\n");
        i++;
    }
    return (0);
}