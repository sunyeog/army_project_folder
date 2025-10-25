#include <stdio.h>

int find(char str[], int a, int len)
{
    int    i = 0;
    while (i < len)
    {
        if (str[i] == a)
            return (i);
        i++;
    }
    return (-1);
}

int ft_strlen(char *str)
{
    int i = 0;
    
    while (str[i])
       i++;
    return (i);
}

int main()
{
    char str[100] = "";
    scanf("%s", str);
    int len = ft_strlen(str);
    int i = 0;
    while(i < 26)
    {
        printf("%d ", find(str, 'a'+i, len));
        i++;
    }
    return (0);
}