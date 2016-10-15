#include <stdio.h>
#include <math.h>

/* Programmeringsuppgift 11.2, Sida 276

Skriv en funktion som beräknar den matematiska längden 
av en vektor där koordinaterna är reella tal. Funktionen ska
få ett fält med element av typen double, samt ett heltal som
anger fältets längd.

Använd pekare i funktionen, inte indexering.

Längden beräknas med

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
	printf("Den matematiska längden är %.2f", mLangd(vektorer, 10) );
	return 0;
}