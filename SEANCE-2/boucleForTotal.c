#include <stdio.h>

int main()
{
    int sum = 0;

    for (int i = 0; i <= 100; i = i + 1)
    {
        sum = sum + i;
        printf("Bonjour! %d\n", i);
        printf("Sum = %d\n", sum);
    }
    printf("Sum = %d\n", sum);

    return (0);
}