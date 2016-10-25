#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 600

/* Programmeringsuppgift 13.3, Sida 337
Sortera en double array med insertion sort: 
Bygg upp ett allt st�rre sorterat delf�lt av f�ltet som ska sorteras. 

Ex: 
osorterat	7 | 1 5 2 3 4 6 0.
steg1		1 7 | 5 2 3 4 6 0.
steg3		1 5 7 | 2 3 4 6 0. 

N�sta element att sortera g�r fr�n h�ger till v�nster tills det hamnar r�tt i arrayen. */

void inSort(double a[], int start, int slut);

int main(){
	double lista[N];
	srand(time(NULL));
	//S�tter randomiserade v�rden till arrayen:
	for(int i=0; i<N;i++){
		//F�rsta tv� v�rdena blir stora 100/1 = 100 och 100/2 = 50 + random
		lista[i] = (100.0 / (i+1)) + ((rand() % 10));
		//printf("%.5f\n", lista[i]);
	}
	inSort(lista, 0, N);
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

void inSort(double a[], int start, int slut){
	int j;
	double temp;
	for(int i=start;i<slut;i++){
		j = i;
		while(j){ //k�r tills j �r noll
			//a[j] �r v�rdet att sortera in, fr�n h�ger
			if(a[j] < a[j-1]){	//om v�rdet att sortera in �r 
				temp = a[j];
				a[j] = a[j-1];
				a[j-1]  = temp;
				j--;
			}
			else {
				//printf("funk bryt\n");
				break;
			}
		}
	}
}
