#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100
#define DATAFIL "mobildata.dat"

/* �vning 13.4 Sida 326
G�r om programmet som l�ser mobilabonnemang.
Sortera abonnemangen efter namn.

Skriv ut till textfil mobildata2.txt
*/

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
	printf("Abonnemang sorterat efter Namn:\n\n");
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
/* Skriv ut till textfil
	format: 
	Surfa Mini
	95 200 0.45 1 50
	Ring Liten
	99 60 0.49 2 39
	Surfa Fast
	245 0 0 6 50
	Maxsurf
	299.00 500 0.50 10.00 40.00 */
	remove("mobildata2.txt"); //raderar mobildata2.txt om den finns
	for(int i=0;i<n;i++){
		FILE *textfil = fopen("mobildata2.txt", "a"); //adderar till textfil
		fprintf(textfil, "%s\n%.2f %d %.2f %.2f %.2f\n", 
			a[i].namn,
			a[i].per_manad,
			a[i].fria_min,
			a[i].extra_min,
			a[i].fria_gb,
			a[i].extra_gb
			);
	}
}

/* 
strcoll(str1,str2)
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2. */

void sortera(struct abonnemang a[], int antal){
	//F�r tempor�r h�llare vid byte mellan tv� abonnemang
	struct abonnemang temp;
	for(int i = 0;i<antal;i++){
		int abc = i;
		/* abc s�tts till i och j�mf�rs sedan med i+1 (j) 
		om j �r kommer f�re i alfabetet �n i s�tts abc till index f�r j
		i j�mf�rs med alla efterkommande indexpositioner */
		for(int j=i+1;j<antal;j++){
			//if((a[j].fria_gb)> (a[max].fria_gb)){
			if(strcoll(a[j].namn, a[abc].namn) < 0){
				//printf("%s kommer f�re %s \n", a[j].namn, a[i].namn);
				abc = j;
			}
		}
		//printf("Jag kommer l�gga %s f�rst!\n", a[abc].namn);
		temp = a[i];
		a[i] = a[abc];
		a[abc] = temp;
	}
	return;
}















