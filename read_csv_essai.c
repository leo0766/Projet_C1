#include <stdio.h>
#include <string.h>

int main () {
	
	
	FILE *the_file = fopen("/Users/leodurst/Documents/EPFL Ba3 C/Projet_C/csse_covid_19_daily_reports/11-09-2020.csv",  "r");
	if (the_file == NULL) {
		perror("Unable to open the file.");
		
	}
	
	char line[100];
	
	while(fgets(line, sizeof(line), the_file)) {
		
		char *token = strtok(line, ",");
		
		while(token != NULL) {
			printf("%-12s", token);
			token = strtok(NULL, ",");
		}
		printf("\n");
		
	}
	
	
}
