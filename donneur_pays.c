#include <stdio.h>


int main (int argc, char*argv[]) {
	
	FILE * pays;
	pays = fopen("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/donneur_pays.csv", "w");
	fprintf(pays, "%s", "Mexico");
	fclose(pays);
	
	
	
	return 0;
	}

