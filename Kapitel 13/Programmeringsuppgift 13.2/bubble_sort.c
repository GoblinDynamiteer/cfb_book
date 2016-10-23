#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 600

/* Programmeringsuppgift 13.2, Sida 336

Skriv en funktion för 'Bubble-sort'-sortering. 
Låt ett algoritm gång på gång löpa igenom arrayen, byt plats på alla par som inte är i ordning. 
Om en genomlöpning lyckas utan byte är arrayen sorterad. 
Använd en double-array, funktionen ska ha samma parametrar som den på sida 320 */

void bubbleSort(double a[], int start, int slut);

int main(){
	double lista[N];
	srand(time(NULL));
	//Sätter randomiserade värden till arrayen:
	for(int i=0; i<N;i++){
		//Första två värdena blir stora 100/1 = 100 och 100/2 = 50 + random
		lista[i] = (100.0 / (i+1)) + ((rand() % 10));
		//printf("%.5f\n", lista[i]);
	}
	bubbleSort(lista, 0, N);
	//Skriver ut arrayens värden:
	int nyrad = 4;
	printf("----------------------------------------------\n");
	for(int i=0; i<N;i++,nyrad--){
		printf("lista[%d]: %.5f\t", i, lista[i]);
		if(!nyrad){ //newline var femte utskrift
			printf("\n");
			nyrad = 5;
		}
	}
}

//Funktion som sorterar arrayen med bubblesort
void bubbleSort(double a[], int start, int slut){
	_Bool hit = 1;
	int raknare = 0, raknare2 = 0; //varvräknare
	double temp;
	while(hit){ //medans hit==1
		hit = 0;
		for(int i = 0;i<slut-1;i++){
			//om värdet efter a[i] är mindre ska värdena byta plats med varandra.
			if(a[i] > a[i+1]){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				hit = 1; //Sätts till 1 när ett byte av två värden har gjorts
				raknare2++;
			}
		}
		raknare++;
	}
	printf("----------------------------------------------\nBUBBELSORTERING\n----------------------------------------------\n");
	printf("Det tog %d while-varv för att sortera arrayen!\n", raknare);
	printf("%d st byten har utförts i for-loopen\n", raknare2);
	return;
}
