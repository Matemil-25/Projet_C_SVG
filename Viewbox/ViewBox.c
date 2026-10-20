#include<stdlib.h>
#include<stdio.h>
#include <string.h>

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
}
/**
 * @brief Affiche les formes SVG et permet d'en supprimer une par son ID.
 *
 * La fonction lit le fichier SVG ligne par ligne, affiche les formes
 * reconnues et demande à l'utilisateur l'ID de celle à supprimer.
 * Elle recopie ensuite les autres lignes dans un fichier temporaire
 * avant de remplacer le fichier original.
 *
 * @return 0 si la suppression réussit, 1 en cas d'erreur.
 */
int Delete_Form(void)
{
    FILE *Pointeur_File;
    FILE *Fichier_Temporaire;
    char Ligne[1024];
    int Id;
    int Id_Supprimer;
    int Trouve = 0;
    /* Ouvrir le fichier SVG en lecture */
    Pointeur_File = fopen("Html_File/Projet_1.html", "r");
    /* Afficher les formes disponibles */
    printf("\n===== Formes disponibles =====\n");
    while (fgets(Ligne, sizeof(Ligne), Pointeur_File) != NULL)
    {
        if (strstr(Ligne, "<rect") != NULL)
            printf("Rectangle : %s", Ligne);
        else if (strstr(Ligne, "<ellipse") != NULL)
            printf("Ellipse : %s", Ligne);
        else if (strstr(Ligne, "<polyline") != NULL)
            printf("Polyline : %s", Ligne);
    }
    /* Demander l'ID à supprimer */
    printf("\nID de la forme a supprimer : ");
    scanf("%d", &Id_Supprimer);
    /* Revenir au début du fichier */
    rewind(Pointeur_File);
    /* Créer le fichier temporaire */
    Fichier_Temporaire = fopen("Html_File/Projet_1.tmp", "w");
    /* Lire et recopier les lignes */
    while (fgets(Ligne, sizeof(Ligne), Pointeur_File) != NULL)
    {
        char *Position_Id = strstr(Ligne, "id=\"");
        /* Vérifier si la ligne possède un ID */
        if (Position_Id != NULL)
        {
            Position_Id += 4;
            Id = atoi(Position_Id);
            if (Id == Id_Supprimer && (strstr(Ligne, "<rect") != NULL || strstr(Ligne, "<ellipse") != NULL || strstr(Ligne, "<polyline") != NULL))
            {
                Trouve = 1;
                continue;
            }
        }
        fprintf(Fichier_Temporaire, "%s", Ligne);
    }
    fclose(Pointeur_File);
    fclose(Fichier_Temporaire);
    /* Remplacer le fichier original */
    if (Trouve)
    {
        rename("Html_File/Projet_1.tmp","Html_File/Projet_1.html");
        printf("Forme supprimee avec succes !\n");
        return 0;
    }
    remove("Html_File/Projet_1.tmp");
    return 1;
}
/**
 * @brief Modifie une forme SVG existante dans le fichier HTML.
 *
 * Cette fonction affiche les formes SVG disponibles, demande à l'utilisateur
 * l'identifiant de la forme à modifier, puis récupère la nouvelle ligne SVG.
 * Elle lit ensuite le fichier original ligne par ligne et copie son contenu
 * dans un fichier temporaire. Lorsque l'identifiant recherché est trouvé,
 * l'ancienne ligne est remplacée par la nouvelle.
 *
 * Une fois la modification terminée, le fichier temporaire remplace le fichier
 * original.
 *
 * Les formes reconnues sont :
 * - Rectangle : <rect>
 * - Ellipse : <ellipse>
 * - Polyligne : <polyline>
 * - Polygone : <polygon>
 *
 * @return 0 si la modification réussit, 1 en cas d'erreur ou si l'identifiant
 *         demandé n'existe pas.
 *
 * @note La nouvelle ligne SVG doit conserver l'identifiant de la forme
 *       modifiée et respecter la syntaxe SVG.
 * @note Chaque forme doit être écrite sur une seule ligne.
 *
 * @warning Cette fonction remplace la ligne entière et ne vérifie pas
 *          la validité de la nouvelle ligne SVG.
 */
int Modify_Form(void)
{
    FILE *Pointeur_File;
    FILE *Fichier_Temporaire;
    char Ligne[1024];
    char Nouvelle_Ligne[1024];
    char *Position_Id;
    int Id;
    int Id_Modifier;
    int Trouve = 0;
    int Caractere;
    /* Ouverture du fichier SVG */
    Pointeur_File = fopen("Html_File/Projet_1.html", "r");
    /* Affichage des formes disponibles */
    printf("\n===== Formes disponibles =====\n");
    while (fgets(Ligne, sizeof(Ligne), Pointeur_File) != NULL)
    {
        if (strstr(Ligne, "<rect") != NULL || strstr(Ligne, "<ellipse") != NULL || strstr(Ligne, "<polyline") != NULL)
        {
            printf("%s", Ligne);
        }
    }
    /* Demande de l'ID */
    printf("\nID de la forme a modifier : ");
	scanf("%d", &Id_Modifier);
	/* Nettoyage du retour a la ligne */
    while ((Caractere = getchar()) != '\n' && Caractere != EOF)
    {
    }
    /* Demande de la nouvelle ligne SVG */
    printf("Entrez la nouvelle ligne SVG :\n");
    if (fgets(Nouvelle_Ligne, sizeof(Nouvelle_Ligne), stdin) == NULL)
    {
        fclose(Pointeur_File);
        printf("Erreur de lecture\n");
        return 1;
    }
    /* Retour au debut du fichier */
    rewind(Pointeur_File);
    /* Creation du fichier temporaire */
    Fichier_Temporaire = fopen("Html_File/Projet_1.tmp", "w");
    /* Lecture et copie des lignes */
    while (fgets(Ligne, sizeof(Ligne), Pointeur_File) != NULL)
    {
        Position_Id = strstr(Ligne, "id=\"");

        if (Position_Id != NULL)
        {
            Position_Id += 4;
            Id = atoi(Position_Id);

            if (Id == Id_Modifier &&(strstr(Ligne, "<rect") != NULL || strstr(Ligne, "<ellipse") != NULL || strstr(Ligne, "<polyline") != NULL ))
            {
                fprintf(Fichier_Temporaire, "%s", Nouvelle_Ligne);
                Trouve = 1;
                continue;
            }
        }
        fprintf(Fichier_Temporaire, "%s", Ligne);
    }
    /* Fermeture des fichiers */
    fclose(Pointeur_File);
    fclose(Fichier_Temporaire);
    /* Remplacement du fichier original */
    if (Trouve)
    {
        rename("Html_File/Projet_1.tmp","Html_File/Projet_1.html");
        printf("Forme modifiee avec succes !\n");
        return 0;
    }
    /* Suppression du fichier temporaire si l'ID est introuvable */
    remove("Html_File/Projet_1.tmp");
    printf("Aucune forme avec cet ID\n");
    return 1;
}
/**
 * @brief Ouvre le fichier HTML dans le navigateur par défaut.
 */
void View_File(void)
{
    system("firefox Html_File/Projet_1.html");
}
