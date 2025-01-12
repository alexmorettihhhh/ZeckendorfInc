#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void normalize(char *fib)
{
    int len = strlen(fib);
    for (int i = len - 1; i >= 2; i--)
    {
        if (fib[i] == '1' && fib[i - 1] == '1' && fib[i - 2] == '0')
        {
            fib[i] = '0';
            fib[i - 1] = '0';
            fib[i - 2] = '1';
        }
    }
}

void increment(char *fib)
{
    int len = strlen(fib);

    if (fib[len - 1] == '1' && len > 1 && fib[len - 2] == '0')
    {
        fib[len - 1] = '0';
        fib[len - 2] = '1';
    }
    else if (fib[len - 1] == '0')
    {
        fib[len - 1] = '1';
    }
    else
    {
        strcat(fib, "0");
        fib[len] = '1';
    }

    normalize(fib);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <fibinary_number>\n", argv[0]);
        return 1;
    }

    char fib[MAX_LEN];
    snprintf(fib, sizeof(fib), "%s", argv[1]);

    for (int i = 0; fib[i] != '\0'; i++)
    {
        if (fib[i] != '0' && fib[i] != '1')
        {
            fprintf(stderr, "Error: Input must be a binary number in Fibonacci representation.\n");
            return 1;
        }
    }

    increment(fib);

    printf("%s\n", fib);
    return 0;
}
