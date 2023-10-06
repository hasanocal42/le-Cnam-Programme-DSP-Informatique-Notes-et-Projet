#include <stdio.h>

int main()
{
    int number = 0;

    while (number >= 0)
    {
        printf("Donner un entier : \n");
        scanf("%d", &number);
    }
    printf("STOP - PROBLEM - DATA\n");
    return (0);
}