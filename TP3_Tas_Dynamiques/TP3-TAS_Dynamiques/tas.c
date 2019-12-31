#include <stdio.h>
#include <stdlib.h>
#include "tas.h"
#include <math.h>
 


tas* createTas(){
	tas *tas = malloc(sizeof(tas));
	tas->tab= malloc(32*sizeof(int));
	tas->capacity=32;
	tas->size=0;
	return tas;
	
}


void tas_destroy(tas * a){
  if( a != NULL ){
    if( a->tab != NULL )
      free( a->tab );
    free( a );
  }
}



char tas_insert(tas* tas, int x){
	char memory_allocation = FALSE;
	if (tas!=NULL){
		if( tas_do_we_need_to_enlarge_capacity(tas)){
			memory_allocation = TRUE;
			tas_enlarge_capacity(tas);
			
		} 
		tas->tab[tas->size] = x;
		tas->size ++; 
		reorganise_tas(tas);
	}
	return memory_allocation;
		
}



char extract_min(tas* tas){
	char memory_reduction = FALSE;
	if (tas!=NULL && tas->size>0){
		if (tas_do_we_need_to_reduce_capacity(tas)){
			memory_reduction = TRUE;
			tas_reduce_capacity(tas);
		}
		tas->tab[0] = tas->tab[tas->size-1];
		tas->size--;
		Entasser(tas,0);
	}
		
	return memory_reduction;
}


int fils_gauche(int i){
	return 2*i+1;
}


int fils_droit(int i){
	return 2*i+2;
}


int parent(int i){
	return (i-1)/2;
}


void reorganise_tas(tas* tas){
	int aux;
	int pos= tas->size -1;
	if(tas !=NULL){
		while(tas->tab[pos] < tas->tab[parent(pos)] && tas->size > 1){
			aux = tas->tab[pos];
			tas->tab[pos] = tas->tab[parent(pos)];
			tas->tab[parent(pos)] = aux;
			pos = parent(pos);
		}
	}			

}



void Entasser(tas* tas, int i){
	int aux;
	int min;
	int g = fils_gauche(i); //renvoie l'indice du fils gauche
	int d = fils_droit(i);  //renvoie l'indice du fils droit
	if (tas !=NULL){
		if((g <= tas->size) && (tas->tab[g] < tas-> tab[i])){
			min = g;	
		}
		else {
			min = i;
		}
		if((d <= tas->size) && (tas->tab[d] < tas->tab[min])){
			min = d;
		}
		
		if (min != i){
			aux = tas->tab[i];
                        tas->tab[i] = tas->tab[min];
			tas->tab[min]= aux;
			
			Entasser(tas,min);
			
		}
	}
}



size_t tas_size(tas * tas){
  return ( tas!=NULL) ? tas->size : -1;
}

size_t tas_capacity(tas * tas){
  return ( tas!=NULL) ? tas->capacity : -1;
}


char tas_do_we_need_to_enlarge_capacity(tas * tas){
	return (tas->size == tas->capacity)? TRUE: FALSE;
}


void tas_enlarge_capacity(tas * tas){
	tas->capacity *= 2;
	tas->tab = (int *) realloc(tas->tab,sizeof(int)	* tas->capacity);
}

char tas_do_we_need_to_reduce_capacity(tas * tas){
	return ( tas->size <= tas->capacity/4 && tas->size >4 )? TRUE: FALSE;

}

void tas_reduce_capacity(tas * tas){
	tas->capacity /= 2;
	tas->tab = (int *)  realloc(tas->tab, sizeof(int) * tas->capacity);
}








		











