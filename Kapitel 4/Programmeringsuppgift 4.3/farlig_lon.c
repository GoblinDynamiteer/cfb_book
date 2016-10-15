#include <stdio.h>

/*
Programmeringsuppgift 4.3, Sida 90

P� en mycket farlig arbetsplats: 
Din l�n b�rjar p� 1 �re, l�nen dubbleras 
varje dag som du arbetar kvar.

Hur l�nge m�ste du arbeta innan du tj�nat ihop 10 miljoner kronor?

10 000 000 kr = 10 000 000 * 100 �re = 1000000000
*/

int main (){
	long lon = 1;
	int dagar = 1; //Jag kan ev. ha t�nkt fel, kanske ska dagar b�rja p� 0
	while (1){
		dagar++;
		lon *= 2; // lon *= 2 betyder lon = lon * 2, sida 87 i boken
		if (lon >= 1000000000) //om l�nen blir lika med eller �ver 1000000000 �re s� bryts while-satsen med break.
			break;
	};
	printf("Det tar %d dagar att tj�na ihop 10 miljoner kronor p� arbetsplatsen", dagar);
	return 0;
}