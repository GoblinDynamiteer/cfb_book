#include <stdio.h>
#include <math.h>

/* Programmeringsuppgift 11.2, Sida 276

Skriv en funktion som ber�knar den matematiska l�ngden 
av en vektor d�r koordinaterna �r reella tal. Funktionen ska
f� ett f�lt med element av typen double, samt ett heltal som
anger f�ltets l�ngd.

Anv�nd pekare i funktionen, inte indexering.

L�ngden ber�knas med

l = sqrt(v1^2 + v2^2 + v3^2 ......  vn^2) */



double mLangd(double a[], int n){
	double langd = 0.0;
	for(double *pekare =a;pekare<a+n;pekare++){
		langd += pow(*pekare,2);
	}
	return sqrt(langd);
}


int main(){
	double vektorer[10] = {1,2,3,4,5,1,2,3,4,5};
	printf("Den matematiska l�ngden �r %.2f", mLangd(vektorer, 10) );
	return 0;
}