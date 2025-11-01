#include <stdio.h>
#include <stdlib.h>

int cmp_str(char **chess, int a, int b)
{
    char num1[9] = BW";
    char num2[9] = "WBWBWBWB"BWBWBW";
    int i = 0, j = 0;
    chess[b + i][a + j]
}

int if_B(char *chess, int a, int b)
{
    char num1[9] = "BWBWBWBW";
    char num2[9] = "WBWBWBWB";

    int i = 0;
    while (i < 8)
    {
        chess[i]
    }
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
    char **chess = (char **)malloc(sizeof(char *) * (b + 1));
    chess[b] = NULL;
    char *str;
    while (i < b)
    {
        str = (char *)malloc(sizeof(char) * (a + 1));
        str[a] = '\0';
        scanf("%s", str);
        chess[i] = str;
        i++;
    }
    
}