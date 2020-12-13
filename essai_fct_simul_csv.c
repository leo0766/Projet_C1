#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[] ) {


//Configuration par défaut

char *pays1;
pays1 = "Angola";
char *pays2;


// Lire les paramètres du site web
	char * parametres = argc > 1 ? argv[1] : NULL;
	while (parametres != NULL) {
		char * equal = strchr(parametres, '=');
		if (equal == NULL) break;
		equal[0] = 0;
		char * ampersand = strchr(equal + 1, '&');
		if (ampersand != NULL) ampersand[0] = 0;
		char * key = parametres;
		char * value = equal + 1;

		if (strcmp(key, "pays") == 0) {
			pays2 = value;
		} 

		parametres = ampersand == NULL ? NULL : ampersand + 1;
	}



if (strlen(pays2) == 0) {
FILE * pay;
pay = fopen("donneur_pays.csv", "w");
fprintf(pay, "%s", pays1);
fclose(pay);
}


else {
FILE * pay;
pay = fopen("donneur_pays.csv", "w");
fprintf(pay, "%s", pays2);
fclose(pay);
}
	

system("./csv_reader.py");
return 0;

}

