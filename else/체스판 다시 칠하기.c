#include <stdio.h>
#include <stdlib.h>

int check_col(char **chess)
{
    int i = 0, j = 0;
    
}

int check_row(char **chess)
{
    int i = 0, j = 0;
    
}

int return_lowest(char **chess, int a, int b)
{
    int lowest = 32;
    int i = 0, j = 0;
    while (i + 7 < a)
    {
        while (j + 7 < b)
        {
            chess[i][j]
            j++;
        }
        i++;
    }
    return (lowest);
}

int main()
{
    int a = 0, b = 0;
    int i = 0;
    
    scanf("%d %d", &a, &b);
    char **chess = (char **)malloc(sizeof(char *) * b + 1);
    chess[b + 1] = NULL;
    char *str;
    while (i < b)
    {
        str = (char *)malloc(sizeof(char) * a + 1);
        str[a + 1] = '\0';
        scanf("%s", str);
        chess[i] = str;
        i++;
    }
    
}