#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //för fmax och fmin
#define N 20

/* Programmeringsuppgift 11.6, Sida 177

Skriv en funktion som får ett double-fält och fältets
längd som parametrar. Funktionen ska ge två resultat:
fältets största och minsta värde! */

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
	//Genererar randomiserade float-värden till arrayen:
	for(int i=0; i<N; i++){
		array[i] = rand() % 100/(i+1.32);
		//printf("\n%.2f\t", array[i]);
	}
	/* Skickar adresserna för max och min till funktionen, som har parametrar som pekare 
	Detta innebär att funktionen kommer kunna ändra variablerna max och min. */
	minmax(array, N, &max, &min);
	printf("\nmin: %.2f max:%.2f", min, max);
	return 0;
}