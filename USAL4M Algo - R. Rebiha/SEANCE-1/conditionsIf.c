#include <stdio.h>
#include <stdbool.h>

int main() 
{
    printf("La note ?\n");

    int note;
    scanf("%d", &note);

    if(note >= 10) 
    {
        printf("Bravo! \n");
    } 
    else 
    {
        printf("Il faut écouter en cours!\n");
    }
    printf("Au revoir \n");
    
    return (0);
}