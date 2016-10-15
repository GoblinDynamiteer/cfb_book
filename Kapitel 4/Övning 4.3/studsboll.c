#include <stdio.h>

/*
�vning 4.3, sida 78

Ange antal meter en studsboll sl�pps ovanf�r ett golv. 
Antag att bollen f�rlorar 30% h�jd vid varjse studs. 
Hur m�nga g�nger studsar bollen innan den �r stilla? 
Stilla = h�jd < 1 cm
*/

int main(){
	double hojd;
	int studsar = 0;
	printf("Ange h�jd i meter, som studsbollen sl�pps fr�n: ");
	scanf("%lf", &hojd);
	//while-sats som loopas s� l�nge h�jd i centimeter �r st�rre �n 1
	while ((hojd * 100) > 1){ //1 h�jd m = 1 h�jd * 100 cm
		studsar++; //r�knar antalet studsar
		hojd = hojd * 0.7; //alternativt: hojd = hojd - (hojd * 0.3);
		printf("\nH�jd efter studs %d: %f m", studsar, hojd); //test som skriver ut bollens h�jd efter varje studs.
	}
	printf("\nStudsbollen studsar %d g�nger innan den blir stilla!", studsar);
	return 0;
}