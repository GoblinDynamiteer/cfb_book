#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 600

/* Programmeringsuppgift 13.2, Sida 336

Skriv en funktion f�r 'Bubble-sort'-sortering. 
L�t ett algoritm g�ng p� g�ng l�pa igenom arrayen, byt plats p� alla par som inte �r i ordning. 
Om en genoml�pning lyckas utan byte �r arrayen sorterad. 
Anv�nd en double-array, funktionen ska ha samma parametrar som den p� sida 320 */

void bubbleSort(double a[], int start, int slut);

int main(){
	double lista[N];
	srand(time(NULL));
	//S�tter randomiserade v�rden till arrayen:
	for(int i=0; i<N;i++){
		//F�rsta tv� v�rdena blir stora 100/1 = 100 och 100/2 = 50 + random
		lista[i] = (100.0 / (i+1)) + ((rand() % 10));
		//printf("%.5f\n", lista[i]);
	}
	bubbleSort(lista, 0, N);
	//Skriver ut arrayens v�rden:
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
	int raknare = 0, raknare2 = 0; //varvr�knare
	double temp;
	while(hit){ //medans hit==1
		hit = 0;
		for(int i = 0;i<slut-1;i++){
			//om v�rdet efter a[i] �r mindre ska v�rdena byta plats med varandra.
			if(a[i] > a[i+1]){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				hit = 1; //S�tts till 1 n�r ett byte av tv� v�rden har gjorts
				raknare2++;
			}
		}
		raknare++;
	}
	printf("----------------------------------------------\nBUBBELSORTERING\n----------------------------------------------\n");
	printf("Det tog %d while-varv f�r att sortera arrayen!\n", raknare);
	printf("%d st byten har utf�rts i for-loopen\n", raknare2);
	return;
}
