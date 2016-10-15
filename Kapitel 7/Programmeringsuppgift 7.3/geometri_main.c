#include <stdio.h>
#include "area.h"
#include <math.h>
#include <stdlib.h>
/*
Programmeringsuppgift 7.3, Sida 147

Konstruera ett funktionsbibliotek 'area' som beräknar
area för cirklar, trianglar och rektanglar

Tips: Placera definition av konstanten PI i area.h så blir den allmänt tillgänglig
(Onödigt, M_PI finns i math.h)

filer:
area.c
area.h
geometri_main.c

*/

int main(){
	int val, felval;
	char * figur;
	double bredd, hojd, radie, area;
	while(1){
		felval = 0;
		//L en en linje med newline i början och slutet, definieras i area.h
		printf("%sBeräkna area för:\n1 - Rektangel\n2 - Cirkel\n3 - Triangel\n4 - Avsluta%sAnge val: ",L,L);
		scanf("%d", &val);
			switch(val){ 
				case 1:
					figur  = "rektangeln";
					printf("Ange bredd: ");
					scanf("%lf", &bredd);
					printf("Ange höjd: ");
					scanf("%lf", &hojd);
					area = area_rektangel(bredd, hojd);
					break;
				case 2:
					figur  = "cirkeln";
					printf("Ange radie: ");
					scanf("%lf", &radie);
					area = area_cirkel(radie);
					break;
				case 3:
					figur  = "triangeln";
					printf("Ange bredd: ");
					scanf("%lf", &bredd);
					printf("Ange höjd: ");
					scanf("%lf", &hojd);
					area = area_triangel(bredd, hojd);
					break;
				case 4:
					exit(1);
				default:
					printf("Fel val!");
					felval = 1;
					break;
			}	//slut switch-sats
		if (felval != 1){
			printf("%sArean för %s är %.2f", L, figur, area);
		}	//slut if-sats
	}		//slut while-sats
}			//slut mainfunktion