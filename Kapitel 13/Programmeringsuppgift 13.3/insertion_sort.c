#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 600

/* Programmeringsuppgift 13.3, Sida 337
Sortera en double array med insertion sort: 
Bygg upp ett allt större sorterat delfält av fältet som ska sorteras. 

Ex: 
osorterat	7 | 1 5 2 3 4 6 0.
steg1		1 7 | 5 2 3 4 6 0.
steg3		1 5 7 | 2 3 4 6 0. 

Nästa element att sortera går från höger till vänster tills det hamnar rätt i arrayen. */

void inSort(double a[], int start, int slut);

int main(){
	double lista[N];
	srand(time(NULL));
	//Sätter randomiserade värden till arrayen:
	for(int i=0; i<N;i++){
		//Första två värdena blir stora 100/1 = 100 och 100/2 = 50 + random
		lista[i] = (100.0 / (i+1)) + ((rand() % 10));
		//printf("%.5f\n", lista[i]);
	}
	inSort(lista, 0, N);
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

void inSort(double a[], int start, int slut){
	int j;
	double temp;
	for(int i=start;i<slut;i++){
		j = i;
		while(j){ //kör tills j är noll
			//a[j] är värdet att sortera in, från höger
			if(a[j] < a[j-1]){	//om värdet att sortera in är 
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
