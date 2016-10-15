#include <math.h>
#include <stdio.h>

/*
Programmeringsuppgift 4.2, sida 90

Johan Kämpe

Uppgift:
Skriv ett program som matar ut en tabell för tal mellan 1-12.
På varje rad: talet, talet i kvadrat, talet i kubik.

Problematik:
Av någon anledning kan jag inte använda pow(x,2) med int x, 
dock fungerar pow(x,3) med variabel med datatyp int. 

med double för x, och %.0lf kan man mata ut heltal i printf från double variabler

Det skulle också gå at köra in variabler med x*x resp. x*x*x, men jag gillar pow(), 
det känns snyggare på något sätt.
*/

int main(){
	printf("n\tn^2\tn^3\n-------------------------\n"); // '\t' är tabb-slag
	//for-sats som kör så länge x är mindre eller lika med 12, i används också för beräkningarna i printf
	for(double i=1;i<=12;i++) 
		printf("%.0lf\t%.0lf\t%.0lf\n", i, pow(i,2), pow(i,3)); 
	return 0;
}