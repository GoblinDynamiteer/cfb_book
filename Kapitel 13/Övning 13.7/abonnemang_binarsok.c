#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funk.h"
#include "abonnemang.h"
#define N 100

/* Ändra programmet på sida 314 så att det använder binär sökning. 
Använd den sorterade textfilen 'mobildata2.txt' från övning 13.4.
 */

int sok_binar(struct abonnemang a[], int n, char leta[]);

int main(){
FILE *f = fopen("mobildata2.txt", "r");
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
	int index = sok_binar(a, n, s); //sätter index för det sökta namnet, med funktion

	if(index >= 0){
			printf(L "Hittade abonnemang" L FRO "%s\n" FR "Data:\n", a[index].namn);
			printf("\n%.2f %d %.2f %.2f %.2f\n",
			a[index].per_manad,
			a[index].fria_min,
			a[index].extra_min,
			a[index].fria_gb,
			a[index].extra_gb);
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

int sok_binar(struct abonnemang a[], int n, char leta[]){
	int i1 = 0, i2 = n, m, raknare = 0;
	while(i1 <= i2){
		raknare++;
		//sätt m till det index som ligger i intervallet i1 - i2
		//ex om i1 =50 i2 = 100
		//mitten: 100-50 = 50  --> 50+(50/2) = 75
		m = i1 + ((i2 - i1) / 2);
		//om det sökta elementet är mindre än elementet på plats m
		if(strcoll(leta, a[m].namn) < 0){ //Return value < 0 then it indicates str1 is less than str2
			//så sätt i2 till m-1
			i2 = m-1;
		}
		//om det sökta elementet är större än elementet på plats m
		//så sätt i1 till m+1
		else if(strcoll(leta, a[m].namn) > 0){ //Return value > 0 then it indicates str2 is less than str1.
			i1 = m+1;
		}
		//annars är det sökta elementet lika med elementet på plats m
		else{
			printf("Funktionen körde " TSU "%d" FR " varv för att hitta namnet!\n", raknare);
			return m;
		}
	}
	return -1;
	//return m; //returnerar index där namnet hittades
}