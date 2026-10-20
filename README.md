# Projet_C_SVG

Le projet à été coder sur c99 dans le cadre d'un projet de cours. Il est composée de plusieurs fichier 3 en C, 1 html qui sert à accueillir la partie svg, et d'un Makefile

## Code :
Le code est divisée en 3 Fichier :
### - Main :
le Main est le code qui sert a exécuter et à créer le fichier html ajout des formes.
Il est composé de plusieurs option :
1-Create File
2-Edit File :
- Modifier les lignes
- supprimer les lignes
3-View File
### - Forme :
Le fichier Forme sert à initialiser les formes via des structures et des fonctions . J'ai décider de réunir toute les formes en une structure qui est composée 
#### Structure :
```c
typedef struct Forme_S
{
Forme_T Forme; /**< Type de la forme géométrique. */
int Id; /**< Identifiant unique de la forme dans le SVG. */
int X; /**< Coordonnée horizontale ou centre horizontal. */
int Y; /**< Coordonnée verticale ou centre vertical. */
int Width; /**< Largeur de la forme. */
int Height; /**< Hauteur de la forme. */
int Stroke_Width; /**< Épaisseur du contour de la forme. */
char Fill[7]; /**< Couleur de remplissage au format hexadécimal RGB. */
char Stroke[7]; /**< Couleur du contour au format hexadécimal RGB. */
int R; /**< Rayon d'un cercle. */
int Xr; /**< Rayon horizontal d'une ellipse. */
int Yr; /**< Rayon vertical d'une ellipse. */
Point_T Points[MAX_POINTS];/**< Tableau contenant les points de la forme. */
} Forme; 
```
Le fichier est composé de fonctions Choice et Add_form
#### Fonction :
##### Choice :
La fonction va demander va demander à l'utilisateur quelle forme il choisi et assigne se choix dans forme_T
```c
Forme_T Choice(void)
{
	int Choice = 0;
	Forme_T F ;
	while (Choice == 0)
	{
		printf("Which form do you want to create ?\n");
		printf("1-Rectangle/square\n");
		printf("2-Ellipse/Circle\n");
		printf("3-line/Polygon/Polyline\n")
		printf(" : ");
		scanf("%d", &Choice);
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
```
##### Add_Form :
La fonction Add_Form est comme son nom l'indique ajouter les formes au SVG

### - Viewbox :
La Viewbox  va être l'endroit ou toutes les formes vont être ajouter et afficher elle à pour origine -250 -250 et elle est de taille 500 500 cela veut dire quelle va de -250 -250 à 250 250 
Elle composé aussi de  3 Fonctions :
#### Delete_Form :
La fonction va prendre chaque ligne grâce à leur ID et afficher toutes les ligne qu'on a et l'utilisateur doit taper l'id de la ligne qu'il veut supprimer
#### Modify_Form :
Il fonctionne comme le delete mais si l'utilisateur veut modifier sa ligne il doit retaper toute la ligne
#### View_File :
ouvre le fichier Html dans Firefox