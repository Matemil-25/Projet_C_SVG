#include<stdlib.h>
#include<stdio.h>
#include "Forme/Forme.c"
#include "Viewbox/ViewBox.c"

/**
 * @brief Fonction principale du programme.
 *
 * Cette fonction permet à l'utilisateur d'interagir avec le programme
 * à travers un menu principal proposant plusieurs fonctionnalités :
 * - Créer un projet SVG.
 * - Modifier un projet existant.
 * - Visualiser un projet.
 * - Quitter le programme.
 *
 * Lors de la création d'un projet, la fonction initialise la ViewBox,
 * puis permet à l'utilisateur d'ajouter des formes géométriques
 * au fichier Html_File/Projet_1.html.
 *
 * Chaque forme ajoutée reçoit un identifiant incrémenté
 * afin de pouvoir la distinguer des autres formes du projet.
 *
 * @return EXIT_SUCCESS si le programme se termine normalement,
 *         ou 0 lorsque l'utilisateur choisit de quitter le programme.
 */
int main (void)
{
    FILE* Pointeur_File;
    Pointeur_File = fopen("Html_File/Projet_1.html","a");
    Forme F ;
    int C = 0;
    int Ch = 0;
    F.Id = 0 ; 
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
                    F.Id += 1 ;
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