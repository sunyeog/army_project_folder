#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int main(int ac, char **av)
{
    char buf[BUFFER_SIZE];
    char *res = NULL;
    char *tmp;
    char *p;
    size_t total = 0;
    size_t len;
    size_t i;
    size_t r;

    if (ac != 2 || av[1][0] == '\0')
        return (1);
    len = strlen(av[1]);

    while ((r = read(0, buf, BUFFER_SIZE)) > 0)
    {
        tmp = realloc(res, total + r);
        if (!tmp)
        {
            free(res);
            perror("Error");
            return (1);
        }
        res = tmp;
        memmove(res + total, buf, r);
        total += r;
    }
    if (r < 0)
    {
        free(res);
        perror("Error");
        return (1);
    }
    
    p = res;
    while (p && (p = memmem(p, total - (p-res), av[1], len)))
    {
        i = 0;
        while (i <len)
            p[i++] = '*';
        p += len;
    }

    if (total > 0)
        write(1, res, total);
    free(res);
    return (0);
}