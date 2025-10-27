#include <stdio.h>

int sum(char str[])
{
    int i = 0;
    int res = 0;
    int plus = 0;
    while (str[i])
    {
        if(str[i] == 'O')
            plus++;
        else
            plus = 0;
        res += plus;
        i++;
    }
    return (res);
}

int main()
{
    int a = 0;
    char str[81] = "";
    
    scanf("%d", &a);
    int i = 0;
    while (i < a)
    {
        scanf("%s", str);
        printf("%d\n", sum(str));
        i++;
    }
    return (0);
}