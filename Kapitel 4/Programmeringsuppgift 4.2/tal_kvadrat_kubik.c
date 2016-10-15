#include <math.h>
#include <stdio.h>

/*
Programmeringsuppgift 4.2, sida 90
Skriv program som matar ut en tabell f�r tal mellan 1-12
p� varje rad: talet, talet i kvadrat, talet i kubik 

Av n�gon anledning kan jag inte anv�nda pow(x,2) med int x, 
dock funkar pow(x,3) med int x. med double f�r x, och %.0f formattering
fungerar det. 

Det skulle ocks� g� at k�ra x*x resp. x*x*x, men jag gillar pow(), det 
k�nns snyggare p� n�got s�tt.
*/

int main(){
	printf("n\tn^2\tn^3"); // \t �r tabb
	for(double x=1;x<=12;x++) //for-sats som k�r s� l�nge x mindre eller lika med 12
		printf("\n%.0f\t%.0f\t%.0f", x, pow(x,2), pow(x,3)); 
	return 0;
}