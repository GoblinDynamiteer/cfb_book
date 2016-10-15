#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Programmeringsuppgift 9.5, Sida 215

Skriv in en rad, best�m vilket det f�rsta och sista ordet �r p� raden
F�ruts�tt att det finns minst ett blankt tecken mellen tv� ord i raden.

T�nk p� att det det f�rsta och/eller sista tecknet kan vare ett eller flera
vita tecken. */

//Funktion fr�n Programmeringsuppgift 9.1, v�nder p� en textstr�ng
void baklanges(char *till, char *fran){
	int raknare = 0;
	for(int i=strlen(fran)-1;i>=0;i--){
		till[raknare] = fran[i];
		raknare++;
	}
	till[raknare]='\0';
}
int main(){
	char text[100], ord_forst[20], ord_sist[20];
	int raknare=0, i=0;
	printf("Skriv in en textrad med minst ett mellanrum mellan tv� ord: ");
	fgets(text,100,stdin);
	//�kar i med 1 s� l�nge vittecken hittas i b�rjan av den inmatade text-str�ngen
	while(isspace(text[i]))
		i++;
	//skriver det f�rsta ordet till ord_forst, till ett vittecken hittas
	while(!isspace(text[i])){
		ord_forst[raknare++] = text[i++];
	}
	/*
	i s�tts till textens str�ngl�ngd 
	-1 f�r att sista tecknet �r nolltecken
	-1 f�r att str�ngen b�rjar med index 0
	*/
	i = strlen(text)-2;
	//nolltecken s�tts efter slutet av ordet i variabeln som h�ller det f�rsta ordet
	ord_forst[raknare] = '\0';
	raknare=0;
	//minskar i med 1 s� l�nge vittecken hittas i slutet av den inmatade text-str�ngen
	while(isspace(text[i]))
		i--;
	//skriver det sista ordet till ord_sist, till ett vittecken hittas, texten blir dock bakl�nges
	while(!isspace(text[i])){
		ord_sist[raknare++] = text[i--];
	}
	//nolltecken s�tts efter slutet av ordet i variabeln som h�ller det sista ordet
	ord_sist[raknare] = '\0';
	//variabel f�r att h�lla sista ordet omv�ndt, beh�vs f�r funktionen baklanges
	char ord_sist_bak[20] = "";
	//baklanges anropas f�r att v�nda p� textstr�ngen i ord_sist
	baklanges(ord_sist_bak,ord_sist);
	printf("F�rsta ordet: %s, andra ordet: %s", ord_forst, ord_sist_bak);
/* 	for(int i = strlen(ord_sist)-1;i>=0;i--)
		printf("%c", ord_sist[i]); */
}