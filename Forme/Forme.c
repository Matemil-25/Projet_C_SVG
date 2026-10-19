#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @enum Forme_E
 * @brief Énumération des formes géométriques disponibles.
 *
 * Définit les différents types de formes que le programme
 * peut créer dans le fichier SVG.
 */
typedef enum Forme_E
{
    Rectangle,  /**< Rectangle ou carré. */
    Ellipse,    /**< Ellipse ou cercle. */
    Polyline,   /**< Ligne, polygone ou polyligne. */
} Forme_T;

/**
 * @struct Point_S
 * @brief Représente un point en deux dimensions.
 *
 * Un point est défini par deux coordonnées entières A et B.
 */
typedef struct Point_S
{
    int A; /**< Coordonnée horizontale du point. */
    int B; /**< Coordonnée verticale du point. */
} Point_T;

/**
 * @def MAX_POINTS
 * @brief Nombre maximal de points pouvant être stockés pour une forme.
 */
#define MAX_POINTS 100

/**
 * @struct Forme_S
 * @brief Contient les informations nécessaires à la définition d'une forme.
 *
 * Cette structure regroupe le type de forme, son identifiant,
 * ses dimensions, ses coordonnées, ses couleurs et ses points.
 */
typedef struct Forme_S
{
    Forme_T Forme;             /**< Type de la forme géométrique. */
    int Id;                    /**< Identifiant unique de la forme dans le SVG. */
    int X;                     /**< Coordonnée horizontale ou centre horizontal. */
    int Y;                     /**< Coordonnée verticale ou centre vertical. */
    int Width;                 /**< Largeur de la forme. */
    int Height;                /**< Hauteur de la forme. */
    int Stroke_Width;          /**< Épaisseur du contour de la forme. */
    char Fill[7];              /**< Couleur de remplissage au format hexadécimal RGB. */
    char Stroke[7];            /**< Couleur du contour au format hexadécimal RGB. */
    int R;                     /**< Rayon d'un cercle. */
    int Xr;                    /**< Rayon horizontal d'une ellipse. */
    int Yr;                    /**< Rayon vertical d'une ellipse. */
    Point_T Points[MAX_POINTS];/**< Tableau contenant les points de la forme. */
} Forme;

/**
 * @brief Demande à l'utilisateur de choisir une forme géométrique.
 *
 * Affiche un menu permettant de sélectionner un rectangle,
 * une ellipse ou une polyligne.
 *
 * La fonction redemande un choix tant que l'utilisateur
 * ne saisit pas une valeur valide parmi les choix proposés.
 *
 * @return Le type de forme choisi parmi Rectangle, Ellipse et Polyline.
 */
Forme_T Choice(void)
{
    int Choice = 0;             //Initialisation de la variable choix
    Forme_T F ;                 //Initialisation de la variable Forme
    while (Choice == 0)         //Boucle qui demande à l'utilisateur quelle forme veut il créer
    {
        printf("Which form do you want to create ?\n");
        printf("1-Rectangle/square      3-line/Polygon/Polyline\n");
        printf("2-Ellipse/Circle\n");
        printf(" : ");
        scanf("%d", &Choice);   //Choix de l'utilisateur

        switch (Choice)
        {
            case 1:
                F = Rectangle; 
                break;
            case 2:
                F = Ellipse;
                break;
            case 3:
                F = Polyline;
                break;
            default:
                printf("This is not in a choice \n");
                Choice = 0;
                break;
        }
    }
    return F;
}

/**
 * @brief Ajoute une forme géométrique au fichier SVG.
 *
 * Demande à l'utilisateur de choisir une forme et de renseigner
 * ses caractéristiques.
 *
 * Selon le type de forme sélectionné, la fonction récupère les
 * coordonnées, les dimensions, les couleurs et l'épaisseur du
 * contour, puis écrit la représentation SVG correspondante dans
 * le fichier Html_File/Projet_1.html.
 *
 * Les formes prises en charge sont :
 * - Rectangle : crée un élément SVG <rect>.
 * - Ellipse : crée un élément SVG <ellipse>.
 * - Polyline : crée un élément SVG <polyline>.
 *
 * @param Fo Structure contenant les caractéristiques de la forme.
 *           Certaines de ses valeurs sont renseignées par l'utilisateur
 *           au cours de l'exécution de la fonction.
 *
 * @return 0 lorsque la fonction atteint la fin de son exécution.
 */
int Add_Form (Forme Fo)
{
    Fo.Forme = Choice();
    FILE* Pointeur_File = fopen("Html_File/Projet_1.html","a");
    switch (Fo.Forme)
    {
    case Rectangle:
        printf("Set your settings : \n");
        printf("X : ");
        scanf("%d",&Fo.X);
        printf("Y : ");
        scanf("%d",&Fo.Y);
        printf("Width : ");
        scanf("%d",&Fo.Width);
        printf("Height : ");
        scanf("%d",&Fo.Height);
        printf("Color Hexa RGB : ");
        scanf("%6s",Fo.Fill);
        printf("Stroke width : " );
        scanf("%d",&Fo.Stroke_Width);
        printf("Stroke Color Hexa RGB : ");
        scanf("%6s",Fo.Stroke);
        fprintf(Pointeur_File,"<rect id=\"%d\" x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"#%6s\" stroke-width=\"%d\" stroke=\"#%s\" />\n",Fo.Id, Fo.X, Fo.Y, Fo.Width ,Fo.Height,Fo.Fill,Fo.Stroke_Width,Fo.Stroke);
        break;
    case Ellipse :
        printf("Set your settings : \n");
        printf("X : ");
        scanf("%d",&Fo.X);
        printf("Y : ");
        scanf("%d",&Fo.Y);
        printf("Rx : ");
        scanf("%d",&Fo.Xr);
        printf("Ry : ");
        scanf("%d",&Fo.Yr);
        printf("Color Hexa RGB : ");
        scanf("%6s",Fo.Fill);
        printf("Stroke width : " );
        scanf("%d",&Fo.Stroke_Width);
        printf("Stroke Color Hexa RGB : ");
        scanf("%6s",Fo.Stroke);
        fprintf(Pointeur_File,"<ellipse id=\"%d\" cx=\"%d\" cy=\"%d\" rx=\"%d\" y=\"%d\" fill=\"#%6s\" stroke-width=\"%d\" stroke=\"#%s\"/>\n",Fo.Id, Fo.X, Fo.Y, Fo.Xr ,Fo.Yr,Fo.Fill,Fo.Stroke_Width,Fo.Stroke);
        break;
    case Polyline :
        int c ;
        printf("Set your settings : \n");   
        printf("X1 : ");
        scanf("%d",&Fo.Points[0].A);
        printf("Y1 : ");
        scanf("%d",&Fo.Points[1].B);
        printf("X2 : ");
        scanf("%d",&Fo.Points[2].A);
        printf("Y2 : ");
        scanf("%d",&Fo.Points[3].B);
        printf("Stroke width : " );
        scanf("%d",&Fo.Stroke_Width);
        printf("Stroke Color Hexa RGB : ");
        scanf("%6s",Fo.Stroke);
        printf("Do you want another line ?\n");
        printf("1-Yes\n");
        printf("2-No\n");
        scanf("%d",&c);
        if(c==2)
            fprintf(Pointeur_File,"<polyline id=\"%d\" points=\"%d,%d %d,%d\" stroke=\"#%s\" stroke-width=\"%d\" />\n",Fo.Id, Fo.Points[0].A, Fo.Points[1].B, Fo.Points[2].A ,Fo.Points[3].B,Fo.Stroke,Fo.Stroke_Width);
        else if(c==1)
            break;
        else 
            printf("\n Invalid Synthax\n");
        break;
        default : 
        printf("\n Invalid Form \n");
        break;
    }
    return 0;
}