#include <stdio.h>
#include <stdlib.h>
#include "tas_binomial.h"


// initialise le noeud avec les valeurs par défaut
// tous les pointeurs sont initialisés à null


void initialise_Node(Noeud* Noeud, int key, int degree){ 
	Noeud-> key = key; 
	Noeud->degree = degree; 
	Noeud-> enfant= NULL;
	Noeud->parent =NULL; 
	Noeud->frere = NULL; 
	//Noeud->Tete = NULL;

  
} 
//--------------------------------------------------------------------//
// creation d'un nouveau noued


Noeud* Create_noeud(int k){
	Noeud* p;
	p = (struct Noeud*) malloc (sizeof(struct Noeud));
	p->key = k;
	return p;
}  



void tas_destroy(Noeud * a){
  if( a != NULL ){
    free( a );
  }
}

//--------------------------------------------------------------------//


// Tete pointe vers la racine de l'arbre binomial le plus à gauche
struct Noeud * Bin_HEAP() {

    struct Noeud* Tete;

    Tete = NULL;

return Tete;

}

//--------------------------------------------------------------------//


struct Noeud* Renvoyer_Min(struct Noeud * heap){
	
	struct Noeud* y = NULL;
	struct Noeud* x = heap;
	//struct Noeud*p;
    	int min = 1000;
        
	/*if (x == NULL) {
		printf("\nRien a extraire");
		return x;
	}*/
	//p = x;
	while (x != NULL){
        	if ( x->key < min){
      			min = x->key;
         		y = x;
	 	}
       		x = x->frere;
	}
	return y;
}


/*struct Noeud* Extract_Min(struct * Noeud H1){
	struct * Noeud x;
	struct * Noeud p;
	x = 	Renvoyer_Min(H1);
	
	p = x;*/
	
	
  

void REVERT_LIST(struct Noeud* y) {
    struct Noeud * Hr;

    if (y->frere != NULL) {

        REVERT_LIST(y->frere);

        (y->frere)->frere = y;

    } else {

        Hr = y;

    }

}


struct Noeud* Extract_Min(struct Noeud * H1){

    struct Noeud* t = NULL;

    struct Noeud* x = H1;

    struct Noeud *Hr;

    struct Noeud* p;
    struct Noeud* H;

    Hr = NULL;

    if (x == NULL) {

        printf("\nNOTHING TO EXTRACT");

        return x;

    }

    int min=x->key;

    p = x;

    while (p->frere != NULL) {

        if ((p->frere)->key < min) {

            min = (p->frere)->key;

            t = p;

            x = p->frere;

        }

        p = p->frere;

    }

    if (t == NULL && x->frere == NULL)

        H1 = NULL;

    else if (t == NULL)

        H1 = x->frere;

    else if (t->frere == NULL)

        t = NULL;

    else

        t->frere = x->frere;

    if (x->enfant != NULL) {

        REVERT_LIST(x->enfant);

        (x->enfant)->frere = NULL;

    }

    H = Union_Binomial(H1, Hr);

    return x;

}

//--------------------------------------------------------------------//

// fusionner deux arbres binomiaux du même degré
void  Lien_Binomial(Noeud* y, Noeud* z){

	// z doit être le parent de y
	y->parent = z;
	y->frere = z->enfant;
	z->enfant = y;
	// incrémenter le degree de z
	z->degree = z->degree +1;

}

//--------------------------------------------------------------------//
// fusionne deux tas sans s'occuper des arbres avec le même degré
// fusionne les listes de racines deT1 et T2 pour en faire une seule liste chaînée, triée par ordre de degrés croissant

struct Noeud* Fusion_Listes_Tas(struct Noeud* H1, struct Noeud* H2) {
	//int key;
	struct Noeud* H = Bin_HEAP();
	struct Noeud* y;
	struct Noeud* z;
	struct Noeud* a = NULL;
	struct Noeud* b = NULL ;
	y = H1;
	z = H2;

	if (y == NULL) {
		return z;
	}

     	if (z == NULL) {
		return y;
   	}
	// Vérifiez le degré des deux nœuds, c.-à-d: qui est plus grand ou plus petit

	if (y->degree <= z->degree)
		H = y;
	else if (y->degree > z->degree)
		H = z;

	// parcourir jusqu'à ce que l'un des tas soit vide 

	 while (y != NULL && z != NULL) {

        	if (y->degree < z->degree) {
			y = y->frere;
		} 
		// lier h1 avec h2 en cas d'égalité de degré
		else if (y->degree == z->degree) {
			a = y->frere;
			y->frere = z;
			y = a;
		} 
		// si h2 est supérieur
		else {
			b = z->frere;
			z->frere = y;
			z = b;
		}
	}

    	return H;

}


//---------------------------------------------------------------------------
// Cette fonction effectue l'opération d'union sur deux tas binomial c'est-à-dire h1 & h2

struct Noeud * Union_Binomial(struct Noeud* H1, struct Noeud* H2) {

	struct Noeud* avant_x = NULL;
	struct Noeud* apres_x = NULL;
	struct Noeud* x = NULL;
	struct Noeud* H = Bin_HEAP();
	H = Fusion_Listes_Tas(H1, H2);

  if (H == NULL)
		return H;
		
		
	avant_x = NULL;
	x = H;
	apres_x = x->frere;

	while (apres_x != NULL) {

		// si deux racines d'arbres adjacentes ont un degré différent ou si 3 racines consécutives ont le même degré passe à l'arbre suivant
		if ((x->degree != apres_x->degree) || ((apres_x->frere != NULL)&& (apres_x->frere)->degree == x->degree)) {

			avant_x = x;
			x = apres_x;
		}
	// sinon fusionne plusieurs fois des arbres binomiaux avec le même degré
		else {
			if (x->key <= apres_x->key) {
				x->frere = apres_x->frere;
				Lien_Binomial(apres_x, x);
			} 
			else {
				if (avant_x == NULL){
					H = apres_x;
				}
				else{
					avant_x->frere = apres_x;
				}

			Lien_Binomial(x, apres_x);
			x = apres_x;

            		}
		}

        	apres_x = x->frere;

   	}
	return H;

}


//---------------------------------------------------------------------------
// insère un noeud dans le tas binomial
struct Noeud* Inserer_Binomial(struct Noeud* H,int val) {
    struct Noeud* x;
    struct Noeud * H1 = Bin_HEAP();
    x = Create_noeud(val);

    x->parent = NULL;

    x->enfant = NULL;

    x->frere = NULL;

    x->degree = 0;

    H1 = x;

    H = Union_Binomial(H, H1);

    return H;

}


int DISPLAY(struct Noeud* H) {

    struct Noeud* p;

    if (H == NULL) {

        printf("\nHEAP EMPTY");

        return 0;

    }

    printf("\nTHE ROOT NODES ARE:-\n");

    p = H;

    while (p != NULL) {

        printf("%d", p->key);

        if (p->frere != NULL)

            printf("-->");

        p = p->frere;

    }
	
	return 1;
    printf("\n");
}

 
 















































