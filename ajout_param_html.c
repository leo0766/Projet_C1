#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double surface = 47.69e6;

int main(int argc, char * argv[]) {
	// Configuration par défaut
	int hours = 48;
	double level = 557.326;
	double inflow = 13 + 6;




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

		if (strcmp(key, "level") == 0) {
			level = atof(value);
		} else if (strcmp(key, "inflow") == 0) {
			inflow = atof(value);
		}

		parametres = ampersand == NULL ? NULL : ampersand + 1;
	}

	// Simulation
	// On génère du JSON, mais on pourrait aussi générer du CSV
	printf("{\n");
	printf("\"resultat\": [\n");

	for (int i = 0; i < hours; i++) {
		double outflow = pow(level - 557.05, 2.0) * 250;
		level = level + (inflow - outflow) * 3600 / surface;
		char * virgule = i == hours - 1 ? "" : ",";
		printf("\t{\"hours\": %d, \"inflow\": %0.6f, \"outflow\": %0.6f, \"level\": %0.6f}%s\n", i + 1, inflow, outflow, level, virgule);
	}

	printf("\t]\n");
	printf("}\n");
	
	



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

		if (strcmp(key, "beta") == 0) {
			beta = atof(value);
		} else if (strcmp(key, "mu") == 0) {
			mu = atof(value);
		}
		else if (strcmp(key, "mu") == 0) {
			mu = atof(value);
		}
		else if (strcmp(key, "nu") == 0) {
					nu = atof(value);
				}
		else if (strcmp(key, "lambda") == 0) {
					lambda = atof(value);
				}
		else if (strcmp(key, "time") == 0) {
					t = atoi(value);
				}
		else if (strcmp(key, "s0") == 0) {
					S0 = atof(value);
				}
		else if (strcmp(key, "c0") == 0) {
					C0 = atof(value);
				}
		else if (strcmp(key, "i0") == 0) {
					I0 = atof(value);
				}
		else if (strcmp(key, "r0") == 0) {
					R0 = atof(value);
				}
		else if (strcmp(key, "m0") == 0) {
					M0 = atof(value);
				}

		parametres = ampersand == NULL ? NULL : ampersand + 1;
	}




	return 0;
}
