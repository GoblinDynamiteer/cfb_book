#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
Programmeringsuppgift 4.1, sida 90
Mata in heltal till användaren matar in "end of file" (CTRL+Z i Windows). 
Lista det största och minsta av de inmatade värdena.

scanf returnerar antal inlästa variabler, i detta fall läser vi in 1 (tal). 
Om "End of File" matas in returnerar scanf 0(?) och if-satsen triggar 
och kör break som avslutar while-loopen
*/

int main(){
	long min = INT_MAX, max = INT_MIN, tal, raknare=1;
		while(raknare != 13){
			printf("Mata in ett heltal (CTRL+Z när klar): ");
			if (scanf("%d", &tal) != 1){
				printf("Fel inmatning, avbryter!!");
				break;
			}
			max = fmax(max,tal); //fmax och fmin finns i math.h och returnerar det största resp. minsta av två inmatade värden.
			min = fmin(min,tal);
			raknare++;
		}
	printf("Det största av de inmatade talen: %d\nDet minsta av de inmatade talen: %d", max, min);
	return 0;
}
