#include <stdio.h>

/*
�vning 8.3, Sida 179.

Skapa en egen version av funktionen memcpy
Funktionen beh�ver enbart fungera f�r f�lt av 
typen double;


memcpy:
En standardfunktion i string.h som kopierar ett f�lt
eller delar av ett f�lt till ett annat.

ex: 
memcpy(g, f, antal_bytes);
kopierar f�ltet f till f�ltet g (om b�da �r lika l�nga)
*/

void memcpy_egen(double a[], double b[], int antal){
	for(int i=0;i<antal;i++){
		b[i] = a[i];
	}
}


int main(){
	//testv�rden f�r array a
	double a[] = {1.2,2,3,4.5,5,6,7.1,6,5,3.3,2,3,4.3,5,6,1,9.3,8,6.4,4.3,2};
	int antal = sizeof a/sizeof a[0]; //antal element i array a
	double b[antal];
	//fyller b med nollor.
	
	for(int i = 0; i<antal;i++){
		b[i] = 0;
	}
	memcpy_egen(a,b,antal);
	printf("a[]: ");
	for(int i = 0; i<antal;i++){
		printf("%.2f ", a[i]);
	}
	printf("\nb[]: ");
	for(int i = 0; i<antal;i++){
		printf("%.2f ", b[i]);
	}
}
