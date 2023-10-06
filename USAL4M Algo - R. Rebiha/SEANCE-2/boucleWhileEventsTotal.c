#include <stdio.h>

int main()
{
    int number = 0;
    int total = 0;
    
    while (number >= 0)
    {
        total = total + number;

        printf("Donner un entier : \n");
        scanf("%d", &number);
    }
    printf("Voici le total : %d\n", total);
    return (0);
}