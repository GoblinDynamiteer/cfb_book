#include <stdio.h>
#define L "\n----------------------------------------------------------------------------\n"
#define Lt "----------------------------------------------------------------------------\n"

/*
Övning 8.8, Sida 176

Skapa ett tvådimensionellt fält med tio rader och tio kolumner
av typen int. Skapa en multiplikationstabell.

Sist i programmet ska tabellen skrivas ut!

*/

int main(){
	int tabell[10][10]; 
	/*En tvådimensionell array har rader och kolumner
	x[R][K]:
	
	xKKKKKKKK
	R
	R
	R
	R
	*/
	printf("%sMultiplikationstabell!%s",L,L);
	//Nästlade for-satser som körs tio gånger per varv
	for(int i=0; i<10;i++){
		for(int j=0; j<10;j++){
			tabell[i][j] = (i+1) * (j+1); //+1 för att array börjar på 0
		}
	}
	//skriver ut värdena i den tvådimensionella arrayen, som en multiplikationstabell
	for(int i=0; i<10;i++){
		for(int j=0; j<10;j++){
			printf("%d\t", tabell[i][j]);
		}
		printf("\n");
	}
	printf("%s",Lt);
	return 0;
}