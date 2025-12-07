#include <stdio.h>
#include <stdlib.h>


int if_W(char **chess, int x, int y)
{
    char num1[9] = "WBWBWBWB";
    char num2[9] = "BWBWBWBW";
    
    int i = 0, j = 0;
    int cnt = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            if (chess[y + 2*i][x + j] != num1[j])
                cnt++;
            if (chess[y + (2 * i + 1)][x + j] != num2[j])
                cnt++;    
            j++;
        }
        i++;
    }
    return (cnt);
}

int if_B(char **chess, int x, int y)
{
    char num1[9] = "BWBWBWBW";
    char num2[9] = "WBWBWBWB";
    int i = 0, j = 0;
    int cnt = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            if (chess[y + 2*i][x + j] != num1[j])
                cnt++;
            if (chess[y + (2 * i + 1)][x + j] != num2[j])
                cnt++;    
            j++;
        }
        i++;
    }
    return (cnt);
}

int mv_start(char **chess, int a, int b)
{
    int x = 0, y = 0;
    int lowest = 64;
    int W_cnt, B_cnt;
    int check;
    while (y + 7 < b)
    {
        //핵심 로직, 항상 시작이 W,B일때를 둘다 비교해야한다.
        x = 0;
        while (x + 7 < a)
        {
            W_cnt = if_W(chess, x, y);
            B_cnt = if_B(chess, x, y);
            if (W_cnt < B_cnt)
                check = W_cnt;
            else
                check = B_cnt;
            if (lowest > check)
                lowest = check;
            x++;
        }
        y++;
    }
    return (lowest);
}

int main()
{
    int a = 0, b = 0;
    int i = 0;
    
    scanf("%d %d", &a, &b);
    char **chess = (char **)malloc(sizeof(char *) * (a + 1));
    chess[a] = NULL;
    char *str;
    while (i < a)
    {
        str = (char *)malloc(sizeof(char) * (b + 1));
        str[b] = '\0';
        scanf("%s", str);
        chess[i] = str;
        i++;
    }
    printf("%d\n", mv_start(chess, b, a));
    i = 0;
    while (i < a)
    {
        free(chess[i]);
        i++;
    }
    free(chess);
    return (0);
}