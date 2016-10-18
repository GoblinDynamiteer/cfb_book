#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100
#define DATAFIL "mobildata.dat"

/* �vning 13.3, Sida 324
G�r om programmet som l�ser mobilabonnemang.
Sortera abonnemangen efter hur m�nga GB/m�nad som ing�r.

Skriv ut listan.*/

void sortera(struct abonnemang *a, int antal);
//Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

int main(){
	int n = 0;
	struct abonnemang a[N];
	// "rb" �r read binary
	FILE *f = fopen(DATAFIL, "rb");
	while(fread(&a[n], strlkStruct, 1, f) == 1){
		n++; //R�knar antal abonnemang i filen
	}
	sortera(a, n);
	
	for(int i=0;i<n;i++){
		printf("Namn: %s\nPer m�nad %.2f kr\nGratisminuter: %d\nPris per min: %.2f kr\nFri surf: %.2f GB\nPris per GB: %.2f kr\n\n", 
		a[i].namn,
		a[i].per_manad,
		a[i].fria_min,
		a[i].extra_min,
		a[i].fria_gb,
		a[i].extra_gb
		);
	}

}

void sortera(struct abonnemang *a, int antal){
	struct abonnemang *temp;// = malloc(strlkStruct);
	// printf("Funktion: a0 namn %s\n", a -> namn);
	// printf("Funktion: a0 gig %.2f\n", a -> fria_gb);
	// printf("Funktion: a1 namn %s\n", (a+1) -> namn);
	// printf("Funktion: a1 gig %.2f\n", (a+1) -> fria_gb);
	
	for(int i = 0;i<antal;i++){
		int max = i;
		//s�k st�rsta tills i �r slut
		for(int j=i+1;j<antal;j++){
			if((a+j) -> fria_gb > (a+max) -> fria_gb){
				max = j;
			}
		}
		temp = a+i; //Hur s�tta structpekare till varandras v�rde?!
		a+i = (a+max);
		a = temp;
		//a+max = temp;
		//printf("St�rsta �r %s med %2.f GB!\n\n", (a+max) -> namn, (a+max) -> fria_gb); //test
		printf("temp  -> fria_gb %2.f GB!\n", temp  -> fria_gb); //test
	}
	return;
}















