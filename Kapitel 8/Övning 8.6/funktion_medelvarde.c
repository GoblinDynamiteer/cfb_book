#include <stdio.h>
#define N 100
/*
Övning 8.6, Sida 166.

Lägg till en funktion till programmet på sida 158.
Funktionen ska beräkna medelvärdet av för priserna
för de olika kontantkorten.
*/
double medelvarde(double kortpriser[], int antal){
	double hallare = 0;
	//for-sats som kör lika många gånger som antal kort
	for (int i = 0; i < antal; i++){
		//variabeln hållare får summan av alla element i arrayen
		hallare += kortpriser[i];
	}
	/*
	Medelvärdet räknas ut genom att dividera summan av alla element
	i arrayen, med antal element i arrayen.
	*/
	return hallare / antal;
}
int main(){
	double pris[N];
	int n = 0;
	while (n < N){
		printf("Pris/min för kort nr %d: ", n+1);
		if (scanf("%lf", &pris[n]) != 1)
			break;
		n++;
	}
	int billigast = 0;
	for (int i=1; i<n;i++){
		if (pris[i] < pris[billigast])
			billigast = i;
	}
	printf("\nKort nr %d är billigast!\n", billigast+1);
	printf("\nKostnad: %4.2f\n", pris[billigast]);
	printf("Medelvärde för kortpriserna: %4.2f\n", medelvarde(pris, n));
}