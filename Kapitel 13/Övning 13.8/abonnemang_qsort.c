#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libtxt.h"
#include "abonnemang.h"
#define N 100

/* Övning 13.8, Sida 334

Ändra programmet från övning 13.4, 
så att det använder standardfunktionen qsort för att sortera. */

//Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

/* 
strcoll(str1,str2)
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2. */

/* 
standardfunktionen qsort behöver en "hjälpfunktion" 
som returnerar ett heltal beroende på vilket av två jämföra 
värden som är störts. Denna funktion ska skapas av programmeraren

Allmäna pekare används av qsort för att kunna sortera olika datatyper

Här ska textsträngar användas, och strcoll används för att se vilken 
av strängarna som kommer först i alfabetet.
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
	/* qsort behöver arrayen som ska sorteras, antal element som ska sorteras, 
	storleken på ett arrayelement, sedan en funktion med allmäna voidpekare som parametrar 
	funktionen ska returnera ett negativt heltal om värdet i pekare 1 är mindre än värdet i pekare 2
	0 om de är lika, och över 0 om värdet i pekare två är störst */
	qsort(a, n, strlkStruct, jamfor_namn);
	//Skriv ut den sorterade listan -- för test
	printf("Abonnemang sorterat efter namn med " FORM_UNDER "qsort" FORM_END ":\n\n");
	for(int i=0;i<n;i++){
		printf(FORM_CYAN "%s" FORM_END "\n" 
		FORM_UNDER "Per månad" FORM_END ":\t%.2f kr\n" 
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
