#include <stdio.h>

int main()
{
    int sum = 0;

    for (int i = 0; i <= 10; i = i + 1)
    {
        printf("\n*\n");

        for (int j = 0; j <= 5; j = j + 1)
        {
            printf("#");
        }
    }
    return (0);
}