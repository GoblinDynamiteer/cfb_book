#include <stdio.h>
#define L "\n----------------------------------------------------------------------------\n"
#define Lt "----------------------------------------------------------------------------\n"

/*
�vning 8.8, Sida 176

Skapa ett tv�dimensionellt f�lt med tio rader och tio kolumner
av typen int. Skapa en multiplikationstabell.

Sist i programmet ska tabellen skrivas ut!

*/

int main(){
	int tabell[10][10]; 
	/*En tv�dimensionell array har rader och kolumner
	x[R][K]:
	
	xKKKKKKKK
	R
	R
	R
	R
	*/
	printf("%sMultiplikationstabell!%s",L,L);
	//N�stlade for-satser som k�rs tio g�nger per varv
	for(int i=0; i<10;i++){
		for(int j=0; j<10;j++){
			tabell[i][j] = (i+1) * (j+1); //+1 f�r att array b�rjar p� 0
		}
	}
	//skriver ut v�rdena i den tv�dimensionella arrayen, som en multiplikationstabell
	for(int i=0; i<10;i++){
		for(int j=0; j<10;j++){
			printf("%d\t", tabell[i][j]);
		}
		printf("\n");
	}
	printf("%s",Lt);
	return 0;
}