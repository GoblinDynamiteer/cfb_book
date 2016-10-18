#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100
#define DATAFIL "mobildata.dat"

/* Programmeringsuppgift 12.6, Sida 311

Ut�ka programmet p� sida 307 s� att man kan 
�ndra abonnemangsuppgifter som redan finns 
i filen

Tips: Anv�nd fseek f�r att skriva till r�tt position
i .dat-filen. */

void lagg_till(void);
void lista_ab(void);
void andra_abonnemang(void);
//Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

int main(){
		int v;
		while(1){
		printf("1: L�gg till abonnemang\n2: �ndra abonnemang\n3: Lista abonnemang\n0: Avsluta");
		printf("\n--------------------------------------\nVal: ");
		scanf("%d", &v);
		switch(v){
			case 0:
				return 0;
			case 1:
				lagg_till();
				break;
			case 2:
				andra_abonnemang();
				break;
			case 3:
				lista_ab();
				break;
			default:
				printf("Fel val!\n");
		}
	}
	return 0;
}

//Listar abonnemangen i .dat-filen
void lista_ab(void){
	struct abonnemang a;
	// "rb" �r read binary
	FILE *f = fopen(DATAFIL, "rb");
	while(fread(&a, strlkStruct, 1, f) == 1){
		printf("Namn: %s\nPer m�nad %.2f kr\nGratisminuter: %d\nPris per min: %.2f kr\nFri surf: %.2f GB\nPris per GB: %.2f kr\n\n", 
		a.namn,
		a.per_manad,
		a.fria_min,
		a.extra_min,
		a.fria_gb,
		a.extra_gb
		);
	}
	fclose(f);
}

//�ndra abonnemang
void andra_abonnemang(void){
	//a �r enbart f�r att lista namn f�r abonnemang som finns i filen.
	struct abonnemang a[N], b;
	int n = 0, v; // v f�r val av abonnemang att �ndra
	// r+ �r read+write, b=binary
	FILE *f = fopen(DATAFIL, "r+b");
	//L�ser in datan till struct
	while(fread(&a[n], strlkStruct, 1, f) == 1){
		n++; //R�knar antal abonnemang i filen
	}
	printf("\nV�lj abonnemang att �ndra:\n");
	for(int i=0;i<n;i++){
		printf("%d: %s\n", i+1, a[i].namn);
	}
	printf("\nVal: ");
	scanf("%d", &v);
	strcpy(b.namn,a[v-1].namn);
	printf("Ange ny data f�r %s\n", b.namn);
	printf("Pris/m�nad - Gratisminuter/m�nad - Pris/min - GB/m�n - Pris/GB\n");
	printf("V�rden: ");
	scanf("%lf%d%lf%lf%lf",
		&b.per_manad,
		&b.fria_min,
		&b.extra_min,
		&b.fria_gb,
		&b.extra_gb);
	clearBuffer(); //T�mmer textbuffert
	rewind(f); //Spolar tillbaka filen
	/*fseek s�tter pekarposition i datafilen med utg�ngspunkt fr�n tredje argumentet
	SEEK_SET inneb�r b�rjan av filen. Vi stegar lika m�nga byte som (v-1) multiplicerat 
	med storlek f�r en struct abonnemang. v sattes n�r vi valde abonnemang att �ndra
	om det vore det f�rsta blir v-1 = 0, vilket g�r att vi skriver i b�rjan av datafilen */
	if(!fseek(f, strlkStruct*(v-1), SEEK_SET)){ //fseek returnerar 0 vid lyckat flyttning av  pekarposition
		printf("Position i fil: %lld \n", ftell(f));
		fwrite(&b, strlkStruct, 1, f); //Skriv 1 struct till f, vid positionen vi tog fram med fseek
	}
	else{
		printf("Uppdatering av datafil misslyckades!\n");
	}
	//St�nger filen - Obs viktigt
	fclose(f);
}

void lagg_till(void){
	//�ppna datafilen i bin�rt l�ge med append (l�gger till text i slutet)
	FILE *f = fopen(DATAFIL, "ab");
	//H�llare f�r inmatat abonnemang
	struct abonnemang b;
	clearBuffer(); //Verkar ligga kvar n�got efter valinput i mainfunk
	printf("Ange abonnemangets namn: ");
	if (!radInput(b.namn, ABNAMN_LANGD)){
		return; //Avbryter funktionen om anv�ndaren matar in EOF
	}
	printf("Ange data f�r %s\n", b.namn);	printf("Pris/m�nad - Gratisminuter/m�nad - Pris/min - GB/m�n - Pris/GB\n");
	printf("V�rden: ");
	scanf("%lf%d%lf%lf%lf",
		&b.per_manad,
		&b.fria_min,
		&b.extra_min,
		&b.fria_gb,
		&b.extra_gb);
	//Skriv 1 struct till f i slutet av filen (append)
	fwrite(&b, strlkStruct, 1, f);
	//St�nger filen - Obs viktigt
	fclose(f);
	return;
}