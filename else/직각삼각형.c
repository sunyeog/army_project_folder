#include <stdio.h>

int main()
{
    int a, b, c;

    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        int q, w, e;
        if (a >= b && a >= c)
        {
            q = a;
            w = b;
            e = c;
        }
        else if (b >= a && b >= c)
        {
            q = b;
            w = a;
            e = c;
        }
        else if (c >= b && c >= a)
        {
            q = c;
            w = b;
            e = a;
        }

        if (a == 0 && b == 0 && c == 0)
            break;
        

        if (((w*w) + (e*e)) == (q*q))
            printf("%s\n", "right");
        else
            printf("%s\n", "wrong");
    }
    return (0);
}