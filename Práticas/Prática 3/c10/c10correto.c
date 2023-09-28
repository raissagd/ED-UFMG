#include <stdlib.h>
#include <stdio.h>

int main(void)
{
        int *p;
        int i = 10;
        for (; i > 0; i--)
        {
                p = malloc(128);
                printf("%ld\n", (long)p);
                free(p);
        }
        return (0);
}
