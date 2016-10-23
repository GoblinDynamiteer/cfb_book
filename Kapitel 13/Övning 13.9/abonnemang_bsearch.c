#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funk.h"
#include "abonnemang.h"
#define N 100

/* �vning 13.9, Sida 336

�ndra programmet fr�n �vning 13.7, 
s� att det anv�nder standardfunktionen bsearch f�r att s�ka.
 */
 
 //Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

int sok_binar(struct abonnemang a[], int n, char leta[]);

/* St�dfunktion f�r bsearch, ska j�mf�ra tv� v�rden och returnera 
-1, 0, 1 beroende p� om v�rde 1 �r mindre, lika eller lika med v�rde 2 */
int jamfor_namn(const void *p1, const void *p2);

int main(){
FILE *f = fopen("mobildata2.txt", "r"); //Sorterad efter namn
struct abonnemang a[N];
int n=0; //r�kna antal abonnemang i filen, och f�r index vid l�sning till struct.
	//Scannar in textfilen till struct
	while(TTS(a[n].namn, ABNAMN_LANGD, f)){
		fscanf(f, "%lf%d%lf%lf%lf",
			&a[n].per_manad,
			&a[n].fria_min,
			&a[n].extra_min,
			&a[n].fria_gb,
			&a[n].extra_gb);
		clearBufferFil(f); //t�m teckenbuffer (fil)
		n++;	//�ka typer av abonnemang med 1
	}
	system("chcp 1252");
	system("cls");
	printf("Kolla upp abonnemang: ");
	char s[ABNAMN_LANGD];
	radInput(s, ABNAMN_LANGD);
	/* Parametrar f�r bsearch:
		void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)
		Obs returnerar en pekare till det hittade v�rdet, INTE indexnummer.
		*/
	struct abonnemang *p = bsearch(s, a, n, strlkStruct, jamfor_namn); //s�tter index f�r det s�kta namnet, med bsearch
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
		printf("Funktionen hittade " TSU "inte" FR " det s�kta namnet!\n");
	}
	return 0;
}

/* 
strcoll(str1,str2)
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2. */

//Fr�n �vning 13.8 d�r samma funktion anv�ndes f�r standardfunktionen qsort
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