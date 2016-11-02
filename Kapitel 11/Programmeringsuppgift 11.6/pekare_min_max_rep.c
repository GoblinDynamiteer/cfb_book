/* Programmeringsuppgift 11.6, Sida 177 - repetition

Skriv en funktion som får ett double-fält och fältets
längd som parametrar. Funktionen ska ge två resultat:
fältets största och minsta värde! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>		//För seed av random
#include <float.h>		//för DBL_MAX, DBL_MIN
#include <math.h> //För absolutvärde fabs(x)
#define SMALL 0.000000001 //Jämförelse av float, absolutvärde av x-y < SMALL --> typ samma
#include "libtxt.h"	//teckenfärg

void dblMinMax(double a[], int n, double *min, double *max);

int main(){
	double falt[100], max, min;
	int antalElement = sizeof(falt) / sizeof(double);
	system("cls");
	
	//Sätter randomiserade decimaltal till array:
	srand(time(NULL));
	int heltal,dec;
	char tal[10], *ptr;
	for(int i=0;i<antalElement;i++){
		heltal = rand() % 100;
		dec = rand() % 100;
		sprintf(tal, "%d.%d", heltal, dec);
		falt[i] = strtod(tal, &ptr);
	}
	//Slut sättning av värden till array
	dblMinMax(falt, antalElement, &min, &max);
	printf("Minsta: %.3f | Största: %.3f\n\n", min, max);
	
	int tab = 2;
	for(int i=0;i<antalElement;i++){
		if(fabs(min - falt[i]) < SMALL){
			printf(FORM_RED FORM_UNDER);
		}
		if(fabs(max - falt[i]) < SMALL){
			printf(FORM_GREEN FORM_UNDER);
		}
		printf("%6.3f\t"FORM_END, falt[i]);
		while(!tab--){
			printf("\n");
			tab = 3;
		}
	}
	return 0;
}

void dblMinMax(double a[], int n, double *min, double *max){
	*max = DBL_MIN;
	*min = DBL_MAX;
	for(int i = 0; i<n; i++){
		*max = (a[i] > *max) ? a[i] : *max;
		*min = (a[i] < *min) ? a[i] : *min;
	}
	return;
}