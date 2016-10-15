#include <math.h>
#include <stdio.h>

/*
Programmeringsuppgift 4.2, sida 90
Skriv program som matar ut en tabell för tal mellan 1-12
på varje rad: talet, talet i kvadrat, talet i kubik 

Av någon anledning kan jag inte använda pow(x,2) med int x, 
dock funkar pow(x,3) med int x. med double för x, och %.0f formattering
fungerar det. 

Det skulle också gå at köra x*x resp. x*x*x, men jag gillar pow(), det 
känns snyggare på något sätt.
*/

int main(){
	printf("n\tn^2\tn^3"); // \t är tabb
	for(double x=1;x<=12;x++) //for-sats som kör så länge x mindre eller lika med 12
		printf("\n%.0f\t%.0f\t%.0f", x, pow(x,2), pow(x,3)); 
	return 0;
}