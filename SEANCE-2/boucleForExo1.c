#include <stdio.h>

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        printf("\n");
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
    }
    return (0);
}