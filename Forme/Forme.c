#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

//==========Enumeration==========
// faire une enumeration de toute les forme

typedef enum Forme_E
{
    Rectangle,
    Ellipse,
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
    int Stroke_Width;
    char Fill[7];
    char Stroke[7];
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
        printf("1-Rectangle/square      3-line/Polygon/Polyline\n");
        printf("2-Ellipse/Circle\n");
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

int Add_Form (Forme Fo)
{
    Fo.Forme = Choice();
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
        printf("Color Hexa RGB : ");
        scanf("%6s",Fo.Fill);
        printf("Stroke width : " );
        scanf("%d",&Fo.Stroke_Width);
        printf("Stroke Color Hexa RGB : ");
        scanf("%6s",Fo.Stroke);
        fprintf(Pointeur_File,"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"#%6s\" stroke-width=\"%d\" stroke=\"#%s\" />\n", Fo.X, Fo.Y, Fo.Width ,Fo.Height,Fo.Fill,Fo.Stroke_Width,Fo.Stroke);
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
        fprintf(Pointeur_File,"<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" y=\"%d\" fill=\"#%6s\" stroke-width=\"%d\" stroke=\"#%s\"/>\n", Fo.X, Fo.Y, Fo.Xr ,Fo.Yr,Fo.Fill,Fo.Stroke_Width,Fo.Stroke);
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
            fprintf(Pointeur_File,"<polyline points=\"%d,%d %d,%d\" stroke=\"#%s\" stroke-width=\"%d\" />\n", Fo.Points[0].A, Fo.Points[1].B, Fo.Points[2].A ,Fo.Points[3].B,Fo.Stroke,Fo.Stroke_Width);
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