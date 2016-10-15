#include <stdio.h>
#define N 100
/*
�vning 8.6, Sida 166.

L�gg till en funktion till programmet p� sida 158.
Funktionen ska ber�kna medelv�rdet av f�r priserna
f�r de olika kontantkorten.
*/
double medelvarde(double kortpriser[], int antal){
	double hallare = 0;
	//for-sats som k�r lika m�nga g�nger som antal kort
	for (int i = 0; i < antal; i++){
		//variabeln h�llare f�r summan av alla element i arrayen
		hallare += kortpriser[i];
	}
	/*
	Medelv�rdet r�knas ut genom att dividera summan av alla element
	i arrayen, med antal element i arrayen.
	*/
	return hallare / antal;
}
int main(){
	double pris[N];
	int n = 0;
	while (n < N){
		printf("Pris/min f�r kort nr %d: ", n+1);
		if (scanf("%lf", &pris[n]) != 1)
			break;
		n++;
	}
	int billigast = 0;
	for (int i=1; i<n;i++){
		if (pris[i] < pris[billigast])
			billigast = i;
	}
	printf("\nKort nr %d �r billigast!\n", billigast+1);
	printf("\nKostnad: %4.2f\n", pris[billigast]);
	printf("Medelv�rde f�r kortpriserna: %4.2f\n", medelvarde(pris, n));
}