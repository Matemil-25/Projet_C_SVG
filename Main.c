#include<stdlib.h>
#include<stdio.h>
#include "Forme/Forme.c"
#include "Viewbox/ViewBox.c"

int main (void)
{
    FILE* Pointeur_File;
    Pointeur_File = fopen("Html_File/Projet_1.html","w");
    Forme F ;
    int C = 0;
    while (1)
    {
        printf("1- Create Project\n");
        printf("2- Save Project\n");
        printf("3- Open Project\n");
        printf("4- Edit Project\n");
        printf("5- View Project\n");
        printf("6- Quit\n");
        printf(" : ");
        scanf("%d", &C);    
    
        switch (C)
        {
        case 1 :
            Create_ViewBox();
            Add_Form(F);
            break;
        case 2 :
            fprintf(Pointeur_File,"</svg>");
            break;
        case 3 :
            break;
        case 4 :
            break;
        case 5 :
            break;
        case 6 :
            return 0 ;
            break;
        default:
            printf("\n Invalid Command \n");
        }
        
    }
    return EXIT_SUCCESS;
}