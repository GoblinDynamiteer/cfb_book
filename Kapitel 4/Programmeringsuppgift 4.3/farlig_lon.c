#include <stdio.h>

/*
Programmeringsuppgift 4.3, Sida 90

På en mycket farlig arbetsplats: 
Din lön börjar på 1 öre, lönen dubbleras 
varje dag som du arbetar kvar.

Hur länge måste du arbeta innan du tjänat ihop 10 miljoner kronor?

10 000 000 kr = 10 000 000 * 100 öre = 1000000000
*/

int main (){
	long lon = 1;
	int dagar = 1; //Jag kan ev. ha tänkt fel, kanske ska dagar börja på 0
	while (1){
		dagar++;
		lon *= 2; // lon *= 2 betyder lon = lon * 2, sida 87 i boken
		if (lon >= 1000000000) //om lönen blir lika med eller över 1000000000 öre så bryts while-satsen med break.
			break;
	};
	printf("Det tar %d dagar att tjäna ihop 10 miljoner kronor på arbetsplatsen", dagar);
	return 0;
}