#include<stdlib.h>
#include<stdio.h>

int Create_ViewBox(void)
{
    FILE* Pointeur_File;
    Pointeur_File = fopen("Html_File/Projet_1.html","w");
    fprintf(Pointeur_File,"<svg viewBox=\"0 0 500 500\" xmlns=\"http://www.w3.org/2000/svg\"> \n");
    fclose(Pointeur_File);
    return 0;
}