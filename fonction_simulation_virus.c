#include <stdio.h>
#include <math.h>



int simulationVirus(double S0, double C0, double I0, double R0, double M0, double lambda, double mu, double v, int t, double betta0) {
	
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
		
		dSt[i] = -betta[i] * (It[i] + Ct[i]) * St[i];
		dCt[i] = betta[i] *  (It[i]+Ct[i]) * St[i] - Ct[i] / v;
		dIt[i] = Ct[i] / v - (It[i] / lambda) - It[i] * mu;
		dRt[i] = It[i] / lambda;
		dMt[i] = It[i] * mu;	
		
		
		if(i < 2) {
			dbetta[i] = (Ct[i] + It[i]) * St[i]/100;
		}
		else {
			dbetta[i] =  ((dbetta[i - 1] - dbetta[i - 2])/(fabs(dbetta[i - 1] - dbetta[i - 2]))) * (Ct[i] + It[i]) * St[i]/100;
			}
		}
		
		/*
		Impression des composantes des tableaux:  
		*/
		
		
	printf("\n");
	printf("Sains\n");
	printf("\n");

	printf("%f,\n", S0);
	for (int i = 1; i < t; i++) {
		printf("%f,\n", St[i]);		
		}	
				
		printf("\n");
		printf("\n");
		
		printf("Contagieux\n");
		printf("\n");
		printf("%f,\n", C0);
		
	for (int i = 1; i < t; i++) {
	
		printf("%f,\n", Ct[i]);
		}
		
		printf("\n");
		printf("\n");
		
		printf("Infectés\n");
		printf("\n");

		printf("%f,\n", I0);
	for (int i = 1; i < t; i++) {
			
		printf("%f,\n", It[i]);
		}
		
		
		printf("\n");
		printf("\n");
		
		printf("Rétablis\n");
		printf("\n");
		printf("%f,\n", R0);	
	for (int i = 1; i < t; i++) {		
		printf("%f,\n", Rt[i]);
		}
		
		printf("\n");
		printf("\n");
				
		printf("Mort\n");
		printf("\n");
		printf("%f,\n", M0);		
	for (int i = 1; i < t; i++) {
		printf("%f,\n", Mt[i]);
		}
		
		printf("\n");
		printf("\n");

	/*
	Vérification de l'homogénéité des équations (Somme doit toujours être égale à 1 --> 100% de la population):  
	 */

	float Somme[10000];
	for(int i = 0; i < t; i++) {
		Somme[i] = St[i] + Ct[i] + It[i] + Rt[i] + Mt[i];
		printf("%f\n", Somme[i]);		
		}
		
		
	return 0;
	}




int main(int argc, char * argv []) {
	
double I0 = 0;
double S0 = 0.95;
double R0 = 0;
double C0 = 0.05;
double M0 = 0;
double lambda = 30;
double mu = 0.02;
double v = 5;
int t = 100;
double betta0 = 0.15;


simulationVirus(S0, C0, I0, R0, M0, lambda, mu, v, t, betta0);


return 0;
}
