#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



void simulationVirus(double S0, double C0, double I0, double R0, double M0, double lambda, double mu, double v, int t, double betta0) {
	
	/*
	initialisation des char arrays: 
	*/
	
	float St[10000], dSt[10000], Ct[10000], dCt[10000], It[10000], dIt[10000], Rt[10000], dRt[10000], Mt[10000], dMt[10000], betta[10000], dbetta[10000];
	
	/* 
	initialisation de la valeur [0] des char arrays:
	*/
	
	dSt[0] = - betta0 * (I0+C0) * S0;
	dIt[0] = C0 / v - I0 / lambda - mu * I0;
	dRt[0] = I0 / lambda;
	dCt[0] = betta0 * (I0 + C0) * S0 - C0 / v;
	dMt[0] = I0 * mu;
	St[0] = S0;
	Ct[0] = C0;
	It[0] = I0;
	Rt[0] = R0;
	Mt[0] = M0;
	betta[0] = betta0;
	dbetta[0] = 0;
	
	
	/*
	Remplissage des char arrays par les formules (équations différentielles) 
	 */
	
	for (int i = 1; i < t; i++) {
	
		St[i] = St[i - 1] + dSt[i - 1];
		It[i] = It[i - 1] + dIt[i - 1];
		Rt[i] = Rt[i - 1] + dRt[i - 1];
		Ct[i] = Ct[i - 1] + dCt[i - 1];
		Mt[i] = Mt[i - 1] + dMt[i - 1];
		
		betta[i] = betta[i - 1] + dbetta[i - 1];				
		
		dSt[i] = -betta[i] * It[i] * St[i];
		dCt[i] = betta[i] * It[i] * St[i] - Ct[i] / v;
		dIt[i] = Ct[i] / v - (It[i] / lambda) - It[i] * mu;
		dRt[i] = It[i] / lambda;
		dMt[i] = It[i] * mu;	
		
		
		if(i < 2) {
			dbetta[i] = It[i] * St[i]/100;
		}
		else {
			dbetta[i] =  ((dbetta[i - 1] - dbetta[i - 2])/(fabs(dbetta[i - 1] - dbetta[i - 2]))) * It[i] * St[i]/100;
			}
		}
		
		
		FILE * data_virus;
	  
	   /* open the file for writing*/
	   
	   data_virus = fopen ("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/dataSimulVirus_c.csv","w");
		
		/*
		Impression des composantes des tableaux dans le fichier txt:  
		*/
		
		
		fprintf(data_virus, "Jours;Sains;Contamines;Infectes;Retablis;Morts\n");
	for (int i = 0; i < t; i++) {
		fprintf(data_virus, "%d;", i);
		fprintf(data_virus, "%f;", St[i]);	
		fprintf(data_virus, "%f;", Ct[i]);
		fprintf(data_virus, "%f;", It[i]);
		fprintf(data_virus, "%f;", Rt[i]);
		fprintf(data_virus, "%f;\n", Mt[i]);
		
		}		

	fclose(data_virus);
	
	FILE * time_virus;
	
	time_virus = fopen("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/time_virus.txt","w");
	
	fprintf(time_virus, "%d", t);
	
	fclose(time_virus);
  
	}







int main(int argc, char * argv []) {
	
	
// Configuration par défaut
double I0 = 0;
double S0 = 0.97;
double R0 = 0;
double C0 = 0.03;
double M0 = 0;
double lambda = 20;
double mu = 0.01;
double v = 5;
int t = 100;
double betta = 0.15;



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
			betta = atof(value);
		} else if (strcmp(key, "mu") == 0) {
			mu = atof(value);
		}
		else if (strcmp(key, "nu") == 0) {
					v = atof(value);
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




simulationVirus(S0, C0, I0, R0, M0, lambda, mu, v, t, betta);


return 0;
}
