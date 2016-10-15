#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
Programmeringsuppgift 4.1, sida 90
Mata in heltal till anv�ndaren matar in "end of file" (CTRL+Z i Windows). 
Lista det st�rsta och minsta av de inmatade v�rdena.

scanf returnerar antal inl�sta variabler, i detta fall l�ser vi in 1 (tal). 
Om "End of File" matas in returnerar scanf 0(?) och if-satsen triggar 
och k�r break som avslutar while-loopen
*/

int main(){
	long min = INT_MAX, max = INT_MIN, tal, raknare=1;
		while(raknare != 13){
			printf("Mata in ett heltal (CTRL+Z n�r klar): ");
			if (scanf("%d", &tal) != 1){
				printf("Fel inmatning, avbryter!!");
				break;
			}
			max = fmax(max,tal); //fmax och fmin finns i math.h och returnerar det st�rsta resp. minsta av tv� inmatade v�rden.
			min = fmin(min,tal);
			raknare++;
		}
	printf("Det st�rsta av de inmatade talen: %d\nDet minsta av de inmatade talen: %d", max, min);
	return 0;
}
