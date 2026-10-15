#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

//==========Enumeration==========
// faire une enumeration de toute les forme

typedef enum Forme_E
{
    Rectangle,
    Ellipse,
    Line,
    Polyline,
} Forme_T;

//==========Structure==========
//Structure Point

typedef struct Point_S
{
    int A;
    int B;
} Point_T;

// creer la structure qui va accueilir les formes

#define MAX_POINTS 100

typedef struct Forme_S
{
    Forme_T Forme;
    int X;
    int Y;
    int Width;
    int Height;
    int Stroke_Weidth;
    int fill;
    int Stroke;
    int R;
    int Xr;
    int Yr;
    Point_T Points[MAX_POINTS];
} Forme;

//==========Fonction==========
//Fonction: choice de la forme

Forme_T Choice(void)
{
    int Choice = 0;
    Forme_T F = Rectangle;

    while (Choice == 0)
    {
        printf("Which form do you want to create ?\n");
        printf("1-Rectangle             3-line\n");
        printf("2-Ellipse/Circle        4-Polygon/Polyline\n");
        printf(" : ");

        if (scanf("%d", &Choice) != 1)
        {
            printf("Saisie invalide\n");
            return Rectangle;
        }

        switch (Choice)
        {
            case 1:
                F = Rectangle;
                break;
            case 2:
                F = Ellipse;
                break;
            case 3:
                F = Line;
                break;
            case 4:
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

//Constructeur de forme

Forme Constructeur(Forme_T F)
{
    Forme Fo ;
    Fo.Forme = F;

    switch (F)
    {
        case Rectangle:
            Fo.R = 0;
            Fo.Xr = 0;
            Fo.Yr = 0;
            break;
        case Ellipse:
            Fo.R = 0;
            Fo.Width = 0;
            Fo.Height = 0;
            break;
        case Line:
            Fo.Width = 0;
            Fo.Height = 0;
            Fo.Xr = 0;
            Fo.Yr = 0;
            Fo.R = 0;
            break;
        case Polyline:
            Fo.Width = 0;
            Fo.Height = 0;
            Fo.R = 0;
            Fo.Xr = 0;
            Fo.Yr = 0;
            break;
    }

    return Fo;
}


int Add_Form (Forme Fo)
{
    Fo.Forme = Choice();
    Fo = Constructeur(Fo.Forme);
    FILE* Pointeur_File;
    Pointeur_File = fopen("Html_File/Projet_1.html","a");
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
        fprintf(Pointeur_File,"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"/>\n", Fo.X, Fo.Y, Fo.Width ,Fo.Height);
        break;
    case Ellipse :
        printf("Set your settings : \n");
        printf("X : ");
        break;
    default : 
        printf("\n Invalid Form \n");
        break;
    }
    fprintf(Pointeur_File,"</svg>");
    fclose(Pointeur_File);
    return 0;
}