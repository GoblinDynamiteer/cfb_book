#include <stdio.h>
#include <locale.h>
#include "pr71.h"
#define L "-------"


int main(){
	int val;
	int tim, min; 
	double temp;
	
	setlocale(LC_ALL,"swedish");
	while(1){
		printf("-----VÄDERKOLL-----\n");
		printf("INLÄSNING:1 || AVLÄSNING: 0\n");
		
		if(scanf("%d",&val) != 1)
			break;
		
		if(val == 1){
			printf("Skriv tid för obeservation timmar 1-24 ");
			scanf("%d", &tim);
			printf("Skriv tid för obeservation minuter 1-60 ");
			scanf("%d", &min);
			printf("Skriv tempratur vid obeservation ");
			scanf("%lf", &temp);
			observation(tim, min, temp);
			//printf("Senast inlästa temperatur:%.2lf (Inläst klockan: %d:%d)\n",aktuell_temp(),obs_timmar(),obs_minuter());
			//printf("funktionen ger: %d", observation(tim, min, temp));
			if(observation(tim, min, temp) == 0);
				printf("FELINMATAT\n");
			//else
				//printf("RÄTT INMATAT\n");
				
		}
		else{
				printf("Senast inlästa temperatur:%.2lf (Inläst klockan: %d:%d)\n",aktuell_temp(),obs_timmar(),obs_minuter());
		}

	
	}
	return 0;
}
