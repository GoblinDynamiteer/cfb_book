#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libtxt.h"
#include "abonnemang.h"
#define N 100

/* �vning 13.8, Sida 334

�ndra programmet fr�n �vning 13.4, 
s� att det anv�nder standardfunktionen qsort f�r att sortera. */

//Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

/* 
strcoll(str1,str2)
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2. */

/* 
standardfunktionen qsort beh�ver en "hj�lpfunktion" 
som returnerar ett heltal beroende p� vilket av tv� j�mf�ra 
v�rden som �r st�rts. Denna funktion ska skapas av programmeraren

Allm�na pekare anv�nds av qsort f�r att kunna sortera olika datatyper

H�r ska textstr�ngar anv�ndas, och strcoll anv�nds f�r att se vilken 
av str�ngarna som kommer f�rst i alfabetet.
*/
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

int main(){
	struct abonnemang a[N];
	FILE *f = fopen("mobildata.txt", "r");
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
	/* qsort beh�ver arrayen som ska sorteras, antal element som ska sorteras, 
	storleken p� ett arrayelement, sedan en funktion med allm�na voidpekare som parametrar 
	funktionen ska returnera ett negativt heltal om v�rdet i pekare 1 �r mindre �n v�rdet i pekare 2
	0 om de �r lika, och �ver 0 om v�rdet i pekare tv� �r st�rst */
	qsort(a, n, strlkStruct, jamfor_namn);
	//Skriv ut den sorterade listan -- f�r test
	printf("Abonnemang sorterat efter namn med " FORM_UNDER "qsort" FORM_END ":\n\n");
	for(int i=0;i<n;i++){
		printf(FORM_CYAN "%s" FORM_END "\n" 
		FORM_UNDER "Per m�nad" FORM_END ":\t%.2f kr\n" 
		FORM_UNDER "Gratisminuter" FORM_END ":\t%d min\n"
		FORM_UNDER "Pris per min" FORM_END ":\t%.2f kr\n"
		FORM_UNDER "Fri surf" FORM_END ":\t%.1f GB\n"
		FORM_UNDER "Pris per GB" FORM_END ":\t%.2f kr\n\n", 
		a[i].namn,
		a[i].per_manad,
		a[i].fria_min,
		a[i].extra_min,
		a[i].fria_gb,
		a[i].extra_gb
		);
	}
	//skriver sorterad struct till textfil
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
