#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Programmeringsuppgift 9.5, Sida 215

Skriv in en rad, bestäm vilket det första och sista ordet är på raden
Förutsätt att det finns minst ett blankt tecken mellen två ord i raden.

Tänk på att det det första och/eller sista tecknet kan vare ett eller flera
vita tecken. */

//Funktion från Programmeringsuppgift 9.1, vänder på en textsträng
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
	printf("Skriv in en textrad med minst ett mellanrum mellan två ord: ");
	fgets(text,100,stdin);
	//ökar i med 1 så länge vittecken hittas i början av den inmatade text-strängen
	while(isspace(text[i]))
		i++;
	//skriver det första ordet till ord_forst, till ett vittecken hittas
	while(!isspace(text[i])){
		ord_forst[raknare++] = text[i++];
	}
	/*
	i sätts till textens stränglängd 
	-1 för att sista tecknet är nolltecken
	-1 för att strängen börjar med index 0
	*/
	i = strlen(text)-2;
	//nolltecken sätts efter slutet av ordet i variabeln som håller det första ordet
	ord_forst[raknare] = '\0';
	raknare=0;
	//minskar i med 1 så länge vittecken hittas i slutet av den inmatade text-strängen
	while(isspace(text[i]))
		i--;
	//skriver det sista ordet till ord_sist, till ett vittecken hittas, texten blir dock baklänges
	while(!isspace(text[i])){
		ord_sist[raknare++] = text[i--];
	}
	//nolltecken sätts efter slutet av ordet i variabeln som håller det sista ordet
	ord_sist[raknare] = '\0';
	//variabel för att hålla sista ordet omvändt, behövs för funktionen baklanges
	char ord_sist_bak[20] = "";
	//baklanges anropas för att vända på textsträngen i ord_sist
	baklanges(ord_sist_bak,ord_sist);
	printf("Första ordet: %s, andra ordet: %s", ord_forst, ord_sist_bak);
/* 	for(int i = strlen(ord_sist)-1;i>=0;i--)
		printf("%c", ord_sist[i]); */
}