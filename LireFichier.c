#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int lireFichier(char * nomFichier, int * tableauARemplir) {
    
    // Ouvrir le fichier
    FILE * file = fopen(nomFichier, "r");
    if (file == NULL){
		printf("Problème à l'ouverture du fichier.\n");
		return 1;
    }
    // Lire ligne par ligne
    int n=0;
    char buffer[100]; 	
    while (fgets(buffer, 100, file) != NULL) {        
		tableauARemplir[n] = atof(buffer);
		n=n+1;
    }
    // Fermer le fichier et renvoyer le nombre de lignes lues
    fclose(file);
    return 0;
}

int main(int argc, char * argv[]) {
	int confirmed[314];
	int ligne = lireFichier("cases_Albania.csv", confirmed);
	printf("%d\n", confirmed[50]);

	return 0;
	
}

