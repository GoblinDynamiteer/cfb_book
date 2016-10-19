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
	//Skriv ut den sorterade listan
	printf("Abonnemang sorterat efter h�gsta GB/M�nad:\n\n");
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

/* F�rs�kte initialt sortera med pekare (abonnemang_sortera_gb.c), men fick det inte 
att fungera. Anv�nder indexering i st�llet...*/

void sortera(struct abonnemang a[], int antal){
	//F�r tempor�r h�llare vid byte mellan tv� abonnemang
	struct abonnemang temp;// = malloc(strlkStruct);
	for(int i = 0;i<antal;i++){
		int max = i;
		/* max s�tts tilli och j�mf�rs sedan med i+1 (j) 
		om j �r st�rre s�tts max till detta index 
		i j�mf�rs med alla efterkommande indexpositioner */
		for(int j=i+1;j<antal;j++){
			if((a[j].fria_gb)> (a[max].fria_gb)){
				max = j;
			}
		}
		/* a[i] (inialt f�rsta arraypositionen, byter plats med index max, st�rsta hamnar f�rst) 
		Sedan kommer i �ka med ett (plats 2 i array) och tal kommer j�mf�ras */
		temp = a[i];		//Hur s�tta structpekare till varandras v�rde?!
		a[i] = a[max];
		a[max] = temp;
	}
	return;
}















