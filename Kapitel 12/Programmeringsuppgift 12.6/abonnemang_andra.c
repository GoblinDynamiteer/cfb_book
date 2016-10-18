#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100
#define DATAFIL "mobildata.dat"

/* Programmeringsuppgift 12.6, Sida 311

Utöka programmet på sida 307 så att man kan 
ändra abonnemangsuppgifter som redan finns 
i filen

Tips: Använd fseek för att skriva till rätt position
i .dat-filen. */

void lagg_till(void);
void lista_ab(void);
void andra_abonnemang(void);
//Storleken i byte av en struct abonnemang (64)
const int strlkStruct = sizeof(struct abonnemang);

int main(){
		int v;
		while(1){
		printf("1: Lägg till abonnemang\n2: Ändra abonnemang\n3: Lista abonnemang\n0: Avsluta");
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
	// "rb" är read binary
	FILE *f = fopen(DATAFIL, "rb");
	while(fread(&a, strlkStruct, 1, f) == 1){
		printf("Namn: %s\nPer månad %.2f kr\nGratisminuter: %d\nPris per min: %.2f kr\nFri surf: %.2f GB\nPris per GB: %.2f kr\n\n", 
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

//Ändra abonnemang
void andra_abonnemang(void){
	//a är enbart för att lista namn för abonnemang som finns i filen.
	struct abonnemang a[N], b;
	int n = 0, v; // v för val av abonnemang att ändra
	// r+ är read+write, b=binary
	FILE *f = fopen(DATAFIL, "r+b");
	//Läser in datan till struct
	while(fread(&a[n], strlkStruct, 1, f) == 1){
		n++; //Räknar antal abonnemang i filen
	}
	printf("\nVälj abonnemang att ändra:\n");
	for(int i=0;i<n;i++){
		printf("%d: %s\n", i+1, a[i].namn);
	}
	printf("\nVal: ");
	scanf("%d", &v);
	strcpy(b.namn,a[v-1].namn);
	printf("Ange ny data för %s\n", b.namn);
	printf("Pris/månad - Gratisminuter/månad - Pris/min - GB/mån - Pris/GB\n");
	printf("Värden: ");
	scanf("%lf%d%lf%lf%lf",
		&b.per_manad,
		&b.fria_min,
		&b.extra_min,
		&b.fria_gb,
		&b.extra_gb);
	clearBuffer(); //Tömmer textbuffert
	rewind(f); //Spolar tillbaka filen
	/*fseek sätter pekarposition i datafilen med utgångspunkt från tredje argumentet
	SEEK_SET innebär början av filen. Vi stegar lika många byte som (v-1) multiplicerat 
	med storlek för en struct abonnemang. v sattes när vi valde abonnemang att ändra
	om det vore det första blir v-1 = 0, vilket gör att vi skriver i början av datafilen */
	if(!fseek(f, strlkStruct*(v-1), SEEK_SET)){ //fseek returnerar 0 vid lyckat flyttning av  pekarposition
		printf("Position i fil: %lld \n", ftell(f));
		fwrite(&b, strlkStruct, 1, f); //Skriv 1 struct till f, vid positionen vi tog fram med fseek
	}
	else{
		printf("Uppdatering av datafil misslyckades!\n");
	}
	//Stänger filen - Obs viktigt
	fclose(f);
}

void lagg_till(void){
	//Öppna datafilen i binärt läge med append (lägger till text i slutet)
	FILE *f = fopen(DATAFIL, "ab");
	//Hållare för inmatat abonnemang
	struct abonnemang b;
	clearBuffer(); //Verkar ligga kvar något efter valinput i mainfunk
	printf("Ange abonnemangets namn: ");
	if (!radInput(b.namn, ABNAMN_LANGD)){
		return; //Avbryter funktionen om användaren matar in EOF
	}
	printf("Ange data för %s\n", b.namn);	printf("Pris/månad - Gratisminuter/månad - Pris/min - GB/mån - Pris/GB\n");
	printf("Värden: ");
	scanf("%lf%d%lf%lf%lf",
		&b.per_manad,
		&b.fria_min,
		&b.extra_min,
		&b.fria_gb,
		&b.extra_gb);
	//Skriv 1 struct till f i slutet av filen (append)
	fwrite(&b, strlkStruct, 1, f);
	//Stänger filen - Obs viktigt
	fclose(f);
	return;
}