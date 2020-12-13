#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int lireFichier(char * nomFichier, int * tableauARemplir) {
    
    FILE * file = fopen(nomFichier, "r");
    if (file == NULL){
		printf("Problème à l'ouverture du fichier.\n");
		return 0;
    }
    // Lire ligne par ligne
    int n=0;
    char buffer[10]; 	
    while (fgets(buffer, 10, file) != NULL) {        
		tableauARemplir[n] = atoi(buffer);
		n=n+1;
    }

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return n;
}
int Covid_est(double mu_real){
	//Définition de nos tableaux
	int confirmed[400], new_cases[314], death[400], new_death[308];
	double mu_calculated[294], new_cases_est_moy[294], confirmed_est[294], new_cases_est[294], new_death_moy[308], new_cases_moy[308];
	
	lireFichier("cases.csv", confirmed);
	lireFichier("death.csv", death);
	
	//Calcul des nouveaux cas par jour
	new_cases[0]=confirmed[0];
	for(int i=1; i<315; i++){
		new_cases[i] = confirmed[i]-confirmed[i-1];
	}
	//En faire une moyenne sur 7 jours (on coupe les 3 valeurs au extrémité)
    for (int i=3; i<312; i++){
		new_cases_moy[i-3] = (new_cases[i-3]+new_cases[i-2]+new_cases[i-1]+new_cases[i]+new_cases[i+1]+new_cases[i+2]+new_cases[i+3]) / 7;
    }
	//Calcul des nouvelles morts par jour
	new_death[0]=death[0];
	for(int i=1; i<312; i++){
		new_death[i] = death[i]-death[i-1];
	}
	//En faire une moyenne sur 7 jours (on coupe les 3 valeurs au extrémité)
    for (int i=3; i<312; i++){
		new_death_moy[i-3] = (new_death[i-3]+new_death[i-2]+new_death[i-1]+new_death[i]+new_death[i+1]+new_death[i+2]+new_death[i+3]) / 7;
	} 
	
	for (int i =0; i < 295 ;i++){ //294 + 14 limite du tableau new_death_moy 
		if (new_cases_moy[i] != 0){    
			mu_calculated[i] = new_death_moy[i+14]/ new_cases_moy[i];   //attention au division d'entier par entier donne des entiers
			new_cases_est[i] = new_cases_moy[i]*(mu_calculated[i]/mu_real);
		}
		else{
			new_cases_est[i] = 0;
		}
	}	
	for (int i=3; i<295; i++){
		new_cases_est_moy[i-3] = (new_cases_est[i-3]+new_cases_est[i-2]+new_cases_est[i-1]+new_cases_est[i]+new_cases_est[i+1]+new_cases_est[i+2]+new_cases_est[i+3]) / 7;
	}
	confirmed_est[0]= new_cases_est[0];
	for (int i=1; i<295; i++){
		confirmed_est[i]= confirmed_est[i-1] + new_cases_est[i];
	}


	FILE * data_virus;
	  
	   /* open the file for writing*/
	   
	   data_virus = fopen("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/dataCovid.csv","w");
		
		/*
		Impression des composantes des tableaux dans le fichier txt:  
		*/

		fprintf(data_virus, "Jours;Nouveaux_cas;Nouveaux_cas_est;Morts;Cas_confirmes;Cas_confirme_est\n");
	for (int i = 1; i < 291; i++) {
		fprintf(data_virus, "%d;", i);
		fprintf(data_virus, "%f;", new_cases_moy[i]);	
		fprintf(data_virus, "%f;", new_cases_est_moy[i]);
		fprintf(data_virus, "%f;", new_death_moy[i]);
		fprintf(data_virus, "%d;", confirmed[i]);
		fprintf(data_virus, "%f;\n", confirmed_est[i]);
		
		}		

	fclose(data_virus);
	
	
		
		
	
	return 0;
}
	



int main(int argc, char * argv[]) {
	
	//En l'occurance, la seule variable de la fonction Covid_est n'en est pas vraiment une car nous avons fixé mu à 0.006.
	double mu_real = 0.006;
	Covid_est(mu_real);
	
	
	//for(int i = 0; i<309;i++){
	//printf("new_cases %d : %f\n", i, new_cases[i]);
	//printf("new_cases_est %d : %f\n", i, );
	//}
	//}
	//for(int i = 0; i<309;i++)
	//{
	//printf("mu %d : %f\n", i, mu[i]);
	//	}
	
	return 0; 
	}

