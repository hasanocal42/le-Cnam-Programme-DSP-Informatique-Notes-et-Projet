#include <stdio.h>

int main()
{
    int number = 0;
    int total = 0;
    int counter = 0;
    float moyenne = 0;

    while (number >= 0)
    {
        total = total + number;

        printf("Donner un entier : \n");
        scanf("%d", &number);
        counter++;
    }
    moyenne = total / (counter - 1);
    printf("Voici votre moyenne %.1f\n", moyenne);

    return (0);
}