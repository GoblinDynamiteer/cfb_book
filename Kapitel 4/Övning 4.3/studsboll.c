#include <stdio.h>

/*
Övning 4.3, sida 78

Ange antal meter en studsboll släpps ovanför ett golv. 
Antag att bollen förlorar 30% höjd vid varjse studs. 
Hur många gånger studsar bollen innan den är stilla? 
Stilla = höjd < 1 cm
*/

int main(){
	double hojd;
	int studsar = 0;
	printf("Ange höjd i meter, som studsbollen släpps från: ");
	scanf("%lf", &hojd);
	//while-sats som loopas så länge höjd i centimeter är större än 1
	while ((hojd * 100) > 1){ //1 höjd m = 1 höjd * 100 cm
		studsar++; //räknar antalet studsar
		hojd = hojd * 0.7; //alternativt: hojd = hojd - (hojd * 0.3);
		printf("\nHöjd efter studs %d: %f m", studsar, hojd); //test som skriver ut bollens höjd efter varje studs.
	}
	printf("\nStudsbollen studsar %d gånger innan den blir stilla!", studsar);
	return 0;
}