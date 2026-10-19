#include<stdlib.h>
#include<stdio.h>

/**
 * @brief Crée la ViewBox du fichier SVG.
 *
 * Ouvre le fichier Html_File/Projet_1.html en mode écriture,
 * puis écrit la balise d'ouverture SVG avec une ViewBox définie
 * par les coordonnées et dimensions suivantes :
 * - Origine : (-250, -250).
 * - Largeur : 500.
 * - Hauteur : 500.
 *
 * Le mode "w" permet de créer le fichier s'il n'existe pas
 * ou de vider son contenu s'il existe déjà.
 *
 * Après l'écriture de la balise SVG, le fichier est fermé.
 *
 * @return 0 lorsque la fonction termine son exécution.
 */
int Create_ViewBox(void)
{
    FILE* Pointeur_File;
    Pointeur_File = fopen("Html_File/Projet_1.html","w");
    fprintf(Pointeur_File,"<svg viewBox=\"-250 -250 500 500\" xmlns=\"http://www.w3.org/2000/svg\"> \n");
    fclose(Pointeur_File);
    return 0;