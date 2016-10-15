#include <stdio.h>

/*
Övning 4.4, sida 80

Gör om övning 4.3, så att man kan göra upprepade 
beräkningar med studsbollen. 

För att avbryta matas ett negativt värde in.
*/

int main(){
	double hojd;
	while (1){ //while-loopen kommer alltid att köras med (1) som argument
		int studsar = 0; //antal studsar behöver nollställas inom while-satsen, annars kommer värde från föregående beräkning av studsar adderas
		printf("\nAnge höjd i meter, som studsbollen släpps från (negativt värde avslutar programmet) : ");
		scanf("%lf", &hojd);
		if (hojd < 0)
			break; //break avbryter while-satsen, om hojd är under 0 (användaren matar in ett negativt värde)
		//while-sats som loopas så länge höjd i centimeter är större än 1
		while ((hojd * 100) > 1){ //1 höjd m = 1 höjd * 100 cm
			studsar++; //räknar antalet studsar
			hojd = hojd * 0.7; //alternativt: hojd = hojd - (hojd * 0.3);
			//printf("\nHöjd efter studs %d: %f m", studsar, hojd); //test som skriver ut bollens höjd efter varje studs.
		}
		printf("\nStudsbollen studsar %d gånger innan den blir stilla!", studsar);
	}
	return 0;
}