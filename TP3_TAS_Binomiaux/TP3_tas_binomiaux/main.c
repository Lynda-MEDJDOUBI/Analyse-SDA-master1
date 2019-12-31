#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "tas_binomial.h"
#include "analyzer.h"



int main(int argc, char ** argv){
		/*int i;
		Noeud* a = Create_noeud(i);
		Inserer_Binomial(a,1);*/
		//int ch,val,n,m; 
		//struct Noeud * heap;
		//Noeud * p; 
		struct Noeud * H;
                H = NULL;
		//Noeud * min;
	
		//Analyse du temps pris par les opérations.
	  analyzer_t * time_analysis = analyzer_create();
	  // Analyse du nombre de copies faites par les opérations.
	 // analyzer_t * copy_analysis = analyzer_create();
	  // Analyse de l'espace mémoire inutilisé.
	  analyzer_t * memory_analysis = analyzer_create(); 
	  // Mesure de la durée d'une opération.
	  struct timespec before, after;
	  //clockid_t clk_id = CLOCK_REALTIME;
	 // utilisé comme booléen pour savoir si une allocation a été effectuée.
	  //char memory_allocation; 
/******************************************************************************/
 
	for (int i =1; i<=10000000; i++) {
		timespec_get(&before, TIME_UTC);
		H = Inserer_Binomial(H,i);
       	        timespec_get(&after, TIME_UTC);
                
       
		
  
/******************************************************************************/
//création de l'arbre initial
        /*int nombre_aleatoire;
	int borne_minimale = 0;
	int borne_maximale = 1000000;
	int cmp;
	srand(11710143);
 
        for (int i =0; i<1000000; i++) {
                nombre_aleatoire = rand()%(borne_maximale - borne_minimale) + borne_minimale;
		timespec_get(&before, TIME_UTC);
        	//H = Inserer_Binomial(H,nombre_aleatoire);
		timespec_get(&after, TIME_UTC);
*/
/******************************************************************************/
       int cmp;
        cmp =0;
	for (int i =10000000; i>=1; i--) {
		timespec_get(&before, TIME_UTC);
		H = Inserer_Binomial(H,i);
       	        timespec_get(&after, TIME_UTC);
                cmp++;
       
/******************************************************************************/       
  /*int i;
  float nombreAleatoire;
  srand(11607325);
  for(i=0;i<1000000;i++){
 	nombreAleatoire = (float)rand()/ (float)RAND_MAX; 
	if(nombreAleatoire < 0.5 || H->degree == 0){
//ajout d'un élément dans le tas et mesure du temps pris par l'opération
		timespec_get(&before, TIME_UTC);
        	H = Inserer_Binomial(H,i);
		timespec_get(&after, TIME_UTC);

		} else{
			timespec_get(&before, TIME_UTC);
        		H = Extract_Min(H);
			timespec_get(&after, TIME_UTC);

			}      */


		
   

			 	/// Enregistrement du temps pris par l'opération
				analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
				// Enregistrement du nombre de copies efféctuées par l'opération.
				// S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
				//analyzer_append(copy_analysis, (memory_allocation)? i:1 );
				// Enregistrement de l'espace mémoire non-utilisé.
				analyzer_append(memory_analysis,cmp);
	 }
	  DISPLAY(H);
	  
/*/Sauvegarde les données de l'expérience.(version originale du main)
	save_values(time_analysis, "../plots/binomial_tas_time_insert_c.plot");
			//save_values(copy_analysis, "../plots_tas_binomial/binomial_tas_insert_copy_insert_c.plot");
	save_values(memory_analysis, "../plots/binomial_tas_memory_insert_c.plot");	*/  

//Sauvegarde les données de l'expérience.(version originale du main)
	save_values(time_analysis, "../plots/binomial_tas_time_insert_DSC_c.plot");
			//save_values(copy_analysis, "../plots_tas_binomial/binomial_tas_insert_copy_insert_c.plot");
	save_values(memory_analysis, "../plots/binomial_tas_memory_insert_DSC_c.plot");	
		
/*/Sauvegarde les données de l'expérience.(version originale du main)
	save_values(time_analysis, "../plots/binomial_tas_time_insert_rand_c.plot");
			//save_values(copy_analysis, "../plots_tas_binomial/binomial_tas_insert_copy_insert_c.plot");
	save_values(memory_analysis, "../plots/binomial_tas_memory_insert_rand_c.plot");*/

			// Nettoyage de la mémoire avant la sortie du programme
			tas_destroy(H);
			analyzer_destroy(time_analysis);
			//analyzer_destroy(copy_analysis);
			//analyzer_destroy(memory_analysis);
	
 /*
	 
while(1){
	 printf("\n1. Insertion\t2. ExtractMin\n");
	 printf("3. Afficher tas\n");
         printf("4. Exit\nEnter your choice:");
	 scanf("%d", &ch);

	 switch(ch){
	 case 1:
          	printf("Entrez une valeur:");
           	scanf("%d", &val);
		p = Create_noeud(val);
           	H = Inserer_Binomial(H,p);
           	break;
       	case 2:
           	min = Extraire_Min(H);
		if (min != NULL){
			printf("\nLE MIN EST  %d", min->key);
		} 
		else {
			printf("\n AUCUN MIN ");
		}
            break;
	case 3:
          	DISPLAY(H);
           	break;
      	case 5:
           	exit(0);
       	default:
            printf("U have entered wrong option!!\n");
            break;
	}
                                
}	*/
	printf("\n");
	return EXIT_SUCCESS;

}





}
