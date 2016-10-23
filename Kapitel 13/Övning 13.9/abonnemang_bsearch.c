#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funk.h"
#include "abonnemang.h"
#define N 100

/* Övning 13.9, Sida 336

Ändra programmet från övning 13.7, 
så att det använder standardfunktionen bsearch för att söka.
 */
 
 //Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

int sok_binar(struct abonnemang a[], int n, char leta[]);

/* Stödfunktion för bsearch, ska jämföra två värden och returnera 
-1, 0, 1 beroende på om värde 1 är mindre, lika eller lika med värde 2 */
int jamfor_namn(const void *p1, const void *p2);

int main(){
FILE *f = fopen("mobildata2.txt", "r"); //Sorterad efter namn
struct abonnemang a[N];
int n=0; //räkna antal abonnemang i filen, och för index vid läsning till struct.
	//Scannar in textfilen till struct
	while(TTS(a[n].namn, ABNAMN_LANGD, f)){
		fscanf(f, "%lf%d%lf%lf%lf",
			&a[n].per_manad,
			&a[n].fria_min,
			&a[n].extra_min,
			&a[n].fria_gb,
			&a[n].extra_gb);
		clearBufferFil(f); //töm teckenbuffer (fil)
		n++;	//öka typer av abonnemang med 1
	}
	system("chcp 1252");
	system("cls");
	printf("Kolla upp abonnemang: ");
	char s[ABNAMN_LANGD];
	radInput(s, ABNAMN_LANGD);
	/* Parametrar för bsearch:
		void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)
		Obs returnerar en pekare till det hittade värdet, INTE indexnummer.
		*/
	struct abonnemang *p = bsearch(s, a, n, strlkStruct, jamfor_namn); //sätter index för det sökta namnet, med bsearch
	if(p != NULL){
			printf(L "Hittade abonnemang" L FRO "%s\n" FR "Data:\n", p -> namn);
			printf("\n%.2f %d %.2f %.2f %.2f\n",
			p -> per_manad,
			p -> fria_min,
			p -> extra_min,
			p -> fria_gb,
			p-> extra_gb);
	}
	else {
		printf("Funktionen hittade " TSU "inte" FR " det sökta namnet!\n");
	}
	return 0;
}

/* 
strcoll(str1,str2)
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2. */

//Från Övning 13.8 där samma funktion användes för standardfunktionen qsort
int jamfor_namn(const void *p1, const void *p2){
	const struct abonnemang *q1 = p1, *q2 = p2;
	if (strcoll(q1 -> namn, q2 -> namn) < 0){
		return -1;
	}
	if (strcoll(q1 -> namn, q2 -> namn) > 0){
		return 1;
	}
	else return 0;
}