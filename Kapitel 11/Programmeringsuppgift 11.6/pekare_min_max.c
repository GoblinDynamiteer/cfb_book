#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //f�r fmax och fmin
#define N 20

/* Programmeringsuppgift 11.6, Sida 177

Skriv en funktion som f�r ett double-f�lt och f�ltets
l�ngd som parametrar. Funktionen ska ge tv� resultat:
f�ltets st�rsta och minsta v�rde! */

void minmax(double a[], int n, double *max, double *min){
	double *p = a;
	*max = DBL_MIN;
	*min = DBL_MAX;
	for(;p<a+n;p++){
		*max = fmax(*p,*max);
		*min = fmin(*p,*min);
		//printf("\nmin: %.2f max:%.2f", *min, *max);
	}
}

int main(){
	double max, min, array[20];
	time_t tid;
	srand(time(&tid));
	//Genererar randomiserade float-v�rden till arrayen:
	for(int i=0; i<N; i++){
		array[i] = rand() % 100/(i+1.32);
		//printf("\n%.2f\t", array[i]);
	}
	/* Skickar adresserna f�r max och min till funktionen, som har parametrar som pekare 
	Detta inneb�r att funktionen kommer kunna �ndra variablerna max och min. */
	minmax(array, N, &max, &min);
	printf("\nmin: %.2f max:%.2f", min, max);
	return 0;
}