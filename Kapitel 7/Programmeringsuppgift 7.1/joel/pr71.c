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
		printf("-----V�DERKOLL-----\n");
		printf("INL�SNING:1 || AVL�SNING: 0\n");
		
		if(scanf("%d",&val) != 1)
			break;
		
		if(val == 1){
			printf("Skriv tid f�r obeservation timmar 1-24 ");
			scanf("%d", &tim);
			printf("Skriv tid f�r obeservation minuter 1-60 ");
			scanf("%d", &min);
			printf("Skriv tempratur vid obeservation ");
			scanf("%lf", &temp);
			observation(tim, min, temp);
			//printf("Senast inl�sta temperatur:%.2lf (Inl�st klockan: %d:%d)\n",aktuell_temp(),obs_timmar(),obs_minuter());
			//printf("funktionen ger: %d", observation(tim, min, temp));
			if(observation(tim, min, temp) == 0);
				printf("FELINMATAT\n");
			//else
				//printf("R�TT INMATAT\n");
				
		}
		else{
				printf("Senast inl�sta temperatur:%.2lf (Inl�st klockan: %d:%d)\n",aktuell_temp(),obs_timmar(),obs_minuter());
		}

	
	}
	return 0;
}
