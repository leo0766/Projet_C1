

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int lireLigne(char * ligne, int *tableauARemplir) {
    
    char * virgule[500];
    virgule[0] = strchr(ligne, ',');
    int i= 1;
    while(i<304){   //a voir le nombre dans notre fichier csv
		virgule[i] = strchr(virgule[i-1] +1, ',');
		
		i = i + 1;
	}
	int z = 3;	
    while(z<304) {      // meme chose 
		tableauARemplir[z-3] = atoi(virgule[z] + 1); // remplir notre tableau à partir des premiers chiffres
		z = z + 1;
	}
    return 1;
}


int lireFichier(char * nomFichier, int * tableauARemplir, int longueur, char * pays) {
    // Ouvrir le fichier
    
    FILE * file = fopen(nomFichier, "r");
	
    if (file == NULL){
		printf("Problème à l'ouverture du fichier.\n");
		return 1;
    }

    // Lire ligne par ligne
    
    int ok;
    char buffer[500]; 	
    while (fgets(buffer, 500, file) != NULL) {        
        char * pos = strstr(buffer, pays);  
        if (pos != NULL) {
			ok = lireLigne(buffer, tableauARemplir);
			break;
			printf("%d\n", ok);		
        }
    }
	

    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return 0;
}


int main(int argc, char * argv[]) {
	int confirmed[302];
	int ligne = lireFichier("covid-19_confirmed.csv", confirmed, 400, "Greece");
	printf("%d\n", confirmed[50]);
	printf("%d\n",ligne);
	return 0;
	
}

