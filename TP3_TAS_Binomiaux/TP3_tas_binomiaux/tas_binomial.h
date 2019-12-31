#define FALSE 0
#define TRUE 1

#include <stddef.h>

//implémentaion de la structure du tas binomial min
typedef struct Noeud {
	int key;// contient la clé
	int degree;// Nombre d'enfants
	struct  Noeud* parent;// pointeur sur le parent
	struct  Noeud* enfant;// pointeur sur l'enfant le plus à gauche
	struct  Noeud* frere;// pointeur vers le frère droit
	//struct  Noeud* Tete; 
	
}Noeud;


// creation d'un nouveau noued
void initialise_Node(Noeud*node, int n, int degree);

Noeud* Create_noeud(int k);

void tas_destroy(Noeud * a);

Noeud* Bin_HEAP();

void  Lien_Binomial(Noeud* y, Noeud* z);

Noeud* Renvoyer_Min(Noeud * heap);

struct Noeud* Extract_Min(struct  Noeud * H1);

struct Noeud* Fusion_Listes_Tas(struct Noeud* H1, struct Noeud* H2);

struct Noeud* Union_Binomial(struct Noeud* H1, struct Noeud* H2);

struct Noeud* Inserer_Binomial(struct Noeud* H, int val);

int DISPLAY(struct Noeud* H);
