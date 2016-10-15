#include <stdio.h>

/*
�vning 4.4, sida 80

G�r om �vning 4.3, s� att man kan g�ra upprepade 
ber�kningar med studsbollen. 

F�r att avbryta matas ett negativt v�rde in.
*/

int main(){
	double hojd;
	while (1){ //while-loopen kommer alltid att k�ras med (1) som argument
		int studsar = 0; //antal studsar beh�ver nollst�llas inom while-satsen, annars kommer v�rde fr�n f�reg�ende ber�kning av studsar adderas
		printf("\nAnge h�jd i meter, som studsbollen sl�pps fr�n (negativt v�rde avslutar programmet) : ");
		scanf("%lf", &hojd);
		if (hojd < 0)
			break; //break avbryter while-satsen, om hojd �r under 0 (anv�ndaren matar in ett negativt v�rde)
		//while-sats som loopas s� l�nge h�jd i centimeter �r st�rre �n 1
		while ((hojd * 100) > 1){ //1 h�jd m = 1 h�jd * 100 cm
			studsar++; //r�knar antalet studsar
			hojd = hojd * 0.7; //alternativt: hojd = hojd - (hojd * 0.3);
			//printf("\nH�jd efter studs %d: %f m", studsar, hojd); //test som skriver ut bollens h�jd efter varje studs.
		}
		printf("\nStudsbollen studsar %d g�nger innan den blir stilla!", studsar);
	}
	return 0;
}