
#include <stddef.h> 

#define FALSE 0
#define TRUE 1

//implémentaion de la structure du tas binaire min 
typedef struct tas2{
    size_t capacity;
    size_t size;
    int *tab;
}tas;


//initialisation et création de la structure
tas * createTas();

void tas_destroy(tas * a);

//Fonction qui insère un entier dans le tas min
char tas_insert(tas* tas, int x);

//Fonction qui extrait le min du tas
char extract_min(tas* tas);

//renvoie la position de l'enfant gauche d'un élément donné 
int enfant_gauche(int i);


//renvoie la position de l'enfant droit d'un élément donné 
int enfant_droit(int i);


//renvoie la position du parent d'un élément donné 
int parent(int i);

//teste si l'arbre donné en paramètre est un tas, sinon elle le réorganise en un tas min
void reorganise_tas(tas* t); 

//renvoie la position du fils gauche à partir de la position d'un élément donné 
int enfant_gauche(int i);

//renvoie la position du fils droit à partir de la position d'un élément donné 
int enfant_droit(int i);

//renvoie la position du parent à partir de la position d'un élément donné 
int parent(int i);

//
void Entasser(tas* t, int i);

/**
   Cette fonction détermine la règle selon laquelle un espace mémoire plus grand sera alloué ou non.
   @param tas est un pointeur vers un tas.
   @returns VRAI si le tas doit être agrandi, FAUX sinon.
*/
char tas_do_we_need_to_enlarge_capacity(tas * tas);

/**
   Cette fonction augmente la capacité du tas.
   @param tas est un pointeur vers un tas.
*/
void tas_enlarge_capacity(tas * tas);


/**
   Cette fonction détermine la règle selon laquelle un espace mémoire plus petit sera alloué ou non.
   @param tas est un pointeur vers un tas.
   @returns VRAI si le tas doit être réduit, FAUX sinon.
*/

char tas_do_we_need_to_reduce_capacity(tas * tas);

/**
   Cette fonction réduit la capacité du tas.
   @param tas est un pointeur vers un tas.
*/
void tas_reduce_capacity(tas * tas);



size_t tas_size(tas * tas);


size_t tas_capacity(tas * tas);





