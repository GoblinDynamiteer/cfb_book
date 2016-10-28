/* Övning 8.8, Sida 176 - repetition
Skapa ett tvådimensionellt fält med tio rade och tio kolumner av typen int. 
Initiera och skriv ut en multiplikationstabell. */

#include <stdio.h>
#define R 25
#define K 10

int main(){
	int tabell[R][K];
	for(int r=0;r<R;r++){
		for(int k=0;k<K;k++){
			tabell[r][k] = (r+1) * (k+1);
			printf("%3d\t", tabell[r][k]);
		}
		printf("\n\n");
	}
	return 0;
}