#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100
#define DATAFIL "mobildata.dat"

/* Övning 13.3, Sida 324
Gör om programmet som läser mobilabonnemang.
Sortera abonnemangen efter hur många GB/månad som ingår.

Skriv ut listan.*/

void sortera(struct abonnemang *a, int antal);
//Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

int main(){
	int n = 0;
	struct abonnemang a[N];
	// "rb" är read binary
	FILE *f = fopen(DATAFIL, "rb");
	while(fread(&a[n], strlkStruct, 1, f) == 1){
		n++; //Räknar antal abonnemang i filen
	}
	sortera(a, n);
	//Skriv ut den sorterade listan
	printf("Abonnemang sorterat efter högsta GB/Månad:\n\n");
	for(int i=0;i<n;i++){
		printf("Namn: %s\nPer månad %.2f kr\nGratisminuter: %d\nPris per min: %.2f kr\nFri surf: %.2f GB\nPris per GB: %.2f kr\n\n", 
		a[i].namn,
		a[i].per_manad,
		a[i].fria_min,
		a[i].extra_min,
		a[i].fria_gb,
		a[i].extra_gb
		);
	}
}

/* Försökte initialt sortera med pekare (abonnemang_sortera_gb.c), men fick det inte 
att fungera. Använder indexering i stället...*/

void sortera(struct abonnemang a[], int antal){
	//För temporär hållare vid byte mellan två abonnemang
	struct abonnemang temp;// = malloc(strlkStruct);
	for(int i = 0;i<antal;i++){
		int max = i;
		/* max sätts tilli och jämförs sedan med i+1 (j) 
		om j är större sätts max till detta index 
		i jämförs med alla efterkommande indexpositioner */
		for(int j=i+1;j<antal;j++){
			if((a[j].fria_gb)> (a[max].fria_gb)){
				max = j;
			}
		}
		/* a[i] (inialt första arraypositionen, byter plats med index max, största hamnar först) 
		Sedan kommer i öka med ett (plats 2 i array) och tal kommer jämföras */
		temp = a[i];		//Hur sätta structpekare till varandras värde?!
		a[i] = a[max];
		a[max] = temp;
	}
	return;
}















