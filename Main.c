#include<stdlib.h>
#include<stdio.h>
#include "Forme/Forme.c"
#include "Viewbox/ViewBox.c"

int main (void)
{
    FILE* Pointeur_File;
    Pointeur_File = fopen("Html_File/Projet_1.html","a");
    Forme F ;
    int C = 0;
    int Ch = 0;
    while (1)
    {
        printf("1- Create Project\n");
        printf("2- Edit Project\n");
        printf("3- View Project\n");
        printf("4- Quit\n");
        printf(" : ");
        scanf("%d", &C);    
        switch (C)
        {
        case 1 :
            Create_ViewBox();
            Ch +=1;
            while (Ch != 0)
            {
                printf("1-Add Shape\n");
                printf("2-leave\n");
                printf(" : ");
                scanf("%d", &Ch);
                if (Ch == 1)
                {
                    Pointeur_File = fopen("Html_File/Projet_1.html","a");
                    Add_Form(F);
                    fclose(Pointeur_File);
                }
                else if (Ch ==2)
                    Ch = 0;
                else 
                    printf("\nInvalid Sythax\n");  
            }
            break;
        case 2 :
            break;
        case 3 :
            break;
        case 4:
            return 0 ;
            break;
        default:
            printf("\n Invalid Command \n");
        }
        
    }

    return EXIT_SUCCESS;
}