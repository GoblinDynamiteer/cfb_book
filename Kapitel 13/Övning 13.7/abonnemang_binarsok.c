#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funk.h"
#include "abonnemang.h"
#define N 100

/* �ndra programmet p� sida 314 s� att det anv�nder bin�r s�kning. 
Anv�nd den sorterade textfilen 'mobildata2.txt' fr�n �vning 13.4.
 */

int sok_binar(struct abonnemang a[], int n, char leta[]);

int main(){
FILE *f = fopen("mobildata2.txt", "r");
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
	int index = sok_binar(a, n, s); //s�tter index f�r det s�kta namnet, med funktion

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
		printf("Funktionen hittade " TSU "inte" FR " det s�kta namnet!\n");
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
		//s�tt m till det index som ligger i intervallet i1 - i2
		//ex om i1 =50 i2 = 100
		//mitten: 100-50 = 50  --> 50+(50/2) = 75
		m = i1 + ((i2 - i1) / 2);
		//om det s�kta elementet �r mindre �n elementet p� plats m
		if(strcoll(leta, a[m].namn) < 0){ //Return value < 0 then it indicates str1 is less than str2
			//s� s�tt i2 till m-1
			i2 = m-1;
		}
		//om det s�kta elementet �r st�rre �n elementet p� plats m
		//s� s�tt i1 till m+1
		else if(strcoll(leta, a[m].namn) > 0){ //Return value > 0 then it indicates str2 is less than str1.
			i1 = m+1;
		}
		//annars �r det s�kta elementet lika med elementet p� plats m
		else{
			printf("Funktionen k�rde " TSU "%d" FR " varv f�r att hitta namnet!\n", raknare);
			return m;
		}
	}
	return -1;
	//return m; //returnerar index d�r namnet hittades
}