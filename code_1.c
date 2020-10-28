#include <stdio.h>
#include <math.h>


int main(int argc, char * argv []) {
	
double I0 = 0.1;
double S0 = 0.9;
double R0 = 0;
double betta = 0.6;
double lambda = 20;
int t = 30;


float St[10000], dSt[10000], It[10000], dIt[10000], Rt[10000], dRt[10000];

dSt[0] = - betta * I0 * S0;
dIt[0] = betta * I0 * S0 - I0 / lambda;
dRt[0] = I0 / lambda;
St[0] = S0;
It[0] = I0;
Rt[0] = R0;

for (int i = 1; i < t; i++) {
	
	St[i] = St[i - 1] + dSt[i - 1];
	It[i] = It[i - 1] + dIt[i - 1];
	Rt[i] = Rt[i - 1] + dRt[i - 1];
	dSt[i] = -betta * St[i] * It[i];
	dIt[i] = betta * St[i] * It[i] -(It[i] / lambda);
	dRt[i] = It[i] / lambda;
	
	printf("%f\n", St[i]);
	}
	
	
}







