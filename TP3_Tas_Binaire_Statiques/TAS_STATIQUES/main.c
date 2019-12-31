#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "tas.h"
#include "analyzer.h"



int main(){
	int i,j;
	//Création du Tas
	tas * a = createTas();
	//Analyse du temps pris par les opérations.
	analyzer_t * time_analysis = analyzer_create();
	// Analyse du nombre de copies faites par les opérations.
	analyzer_t * copy_analysis = analyzer_create();
	// Analyse de l'espace mémoire inutilisé.
	analyzer_t * memory_analysis = analyzer_create(); 
	// Mesure de la durée d'une opération.
	struct timespec before, after;
	clockid_t clk_id = CLOCK_REALTIME;
	// utilisé comme booléen pour savoir si une allocation a été effectuée.
	char memory_allocation; 
	int nombre_aleatoire;
	int borne_minimale = 0;
	int borne_maximale = 5000;

	/************** Insertiondes clés dans l'ordre décroissant ********************/
	 /* for(i=5000;i>0;i--){
	  //ajout d'un élément dans le tas et mesure du temps pris par l'opération
			clock_gettime(clk_id, &before);
			memory_allocation = tas_insert(a,i);
			clock_gettime(clk_id, &after);
			


			// Enregistrement du temps pris par l'opération
		  analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
		  // Enregistrement du nombre de copies efféctuées par l'opération.
		  // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
		  analyzer_append(copy_analysis, (memory_allocation)? i:1 );
		  // Enregistrement de l'espace mémoire non-utilisé.
		  analyzer_append(memory_analysis,tas_capacity(a)-tas_size(a));

	 }
	for (j=0; j<5000;j++){
		printf("%d  ",a->tab[j]);
	}
	*/

	/******************* Insertion des clés aléatoires *******************/
	/*
	srand(time(NULL));
	for(i=0; i<5000; i++){
 	
	nombre_aleatoire = rand()%(borne_maximale - borne_minimale) + borne_minimale;
       
	
	  //ajout d'un élément dans le tas et mesure du temps pris par l'opération
			clock_gettime(clk_id, &before);
			memory_allocation = tas_insert(a,nombre_aleatoire);
			clock_gettime(clk_id, &after);
			



			// Enregistrement du temps pris par l'opération
		  analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
		  // Enregistrement du nombre de copies efféctuées par l'opération.
		  // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
		  analyzer_append(copy_analysis, (memory_allocation)? i:1 );
		  // Enregistrement de l'espace mémoire non-utilisé.
		  analyzer_append(memory_analysis,tas_capacity(a)-tas_size(a));

	 }
	for(j=0;j<5000;j++){
		printf("%d  ",a->tab[j]);
	}*/
		
	float nombreAleatoire;
	srand(11710143);
	for(i=0;i<500;i++){
	  	nombreAleatoire = (float)rand()/ (float)RAND_MAX; 
	  	if(nombreAleatoire>0.5 || a->size == 0){
			//ajout d'un élément dans le tas et mesure du temps pris par l'opération
			clock_gettime(clk_id, &before);
			memory_allocation = tas_insert(a,i);
			clock_gettime(clk_id, &after);
		} else{
			clock_gettime(clk_id, &before);
			memory_allocation = extract_min(a);
			clock_gettime(clk_id, &after);
		}


		// Enregistrement du temps pris par l'opération
		analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
		// Enregistrement du nombre de copies efféctuées par l'opération.
		// S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
		analyzer_append(copy_analysis, (memory_allocation)? i:1 );
		// Enregistrement de l'espace mémoire non-utilisé.
		analyzer_append(memory_analysis,tas_capacity(a)-tas_size(a));

	 }
	for (j=0; j<500;j++){
		printf("%d  ",a->tab[j]);
	}
	


	// Affichage de quelques statistiques sur l'expérience.
	fprintf(stderr, "Total cost: %Lf\n", get_total_cost(time_analysis));
	fprintf(stderr, "Average cost: %Lf\n", get_average_cost(time_analysis));
	fprintf(stderr, "Variance: %Lf\n", get_variance(time_analysis));
	fprintf(stderr, "Standard deviation: %Lf\n", get_standard_deviation(time_analysis));

	/*//Sauvegarde les données de l'expérience.(insertion des clés dans l'ordre croissant)
	save_values(time_analysis, "../plots_tas_static/static_tas_time_insert_c.plot");
	save_values(copy_analysis, "../plots_tas_static/static_tas_insert_copy_c.plot");
	save_values(memory_analysis, "../plots_tas_static/static_tas_memory_insert_c.plot");*/

	/*//Sauvegarde les données de l'expérience (insertion des données dans l'ordre décroissant)
	save_values(time_analysis, "../plots_tas_static/static_tas_time_insert_desc_c.plot");
	save_values(copy_analysis, "../plots_tas_static/static_tas_insert_copy_desc_c.plot");
	save_values(memory_analysis, "../plots_tas_static/static_tas_memory_insert_desc_c.plot");*/

	/*//Sauvegarde les données de l'expérience (insertion des clés aléatoires)
	save_values(time_analysis, "../plots_tas_static/static_tas_time_insert_rand_c.plot");
	save_values(copy_analysis, "../plots_tas_static/static_tas_insert_copy_rand_c.plot");
	save_values(memory_analysis, "../plots_tas_static/static_tas_memory_insert_rand_c.plot");*/

			
	//Sauvegarde les données de l'expérience.(insertion et extraction)
	save_values(time_analysis, "../plots_tas_static/static_tas_time_insert_extractMin_c.plot");
	save_values(copy_analysis, "../plots_tas_static/static_tas_insert_copy_insert_extractMin_c.plot");
	save_values(memory_analysis, "../plots_tas_static/static_tas_memory_insert_extractMin_c.plot");


			


	// Nettoyage de la mémoire avant la sortie du programme
	tas_destroy(a);
	analyzer_destroy(time_analysis);
	analyzer_destroy(copy_analysis);
	analyzer_destroy(memory_analysis);

	return EXIT_SUCCESS;

}
