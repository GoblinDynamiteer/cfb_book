#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100
#define DATAFIL "mobildata.dat"

void lagg_till(void);
void lista_ab(void);
void andra_abonnemang(void);

int main(){int v;while(1){
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
void lista_ab(void){
	struct abonnemang a[N];
	int n = 0;
	FILE *f = fopen(DATAFIL, "rb");
	//Scannar in textfilen till struct
	while(fread(&a[n], sizeof(struct abonnemang), 1, f) == 1){
		n++;	//öka typer av abonnemang med 
	}
	for(int i=0;i<n;i++){
		printf("Namn: %s\nPer månad %.2f kr\nGratisminuter: %d\nPris per min: %.2f kr\nFri surf: %.2f GB\nPris per GB: %.2f kr\n\n", 
		a[i].namn,
		a[i].per_manad,
		a[i].fria_min,
		a[i].extra_min,
		a[i].fria_gb,
		a[i].extra_gb
		);
	}
}

void andra_abonnemang(void){
	struct abonnemang a[N];
	int n = 0, v;
	FILE *f = fopen(DATAFIL, "rb");
	//Scannar in textfilen till struct
	while(fread(&a[n], sizeof(struct abonnemang), 1, f) == 1){
		n++;	//öka typer av abonnemang med 
	}
	printf("\nVälj abonnemang att ändra:\n");
	for(int i=0;i<n;i++){
		printf("%d: %s\n", i+1, a[i].namn);
	}
	printf("\nVal: ");
	scanf("%d", &v);
	printf("Ange ny data för %s:", a[v-1].namn);
	scanf("%lf%d%lf%lf%lf",
		&a[v-1].per_manad,
		&a[v-1].fria_min,
		&a[v-1].extra_min,
		&a[v-1].fria_gb,
		&a[v-1].extra_gb);
	clearBuffer();
	freopen(DATAFIL, "wb", f);
	fseek(f, sizeof(struct abonnemang) * (v-1), SEEK_SET);
	fwrite(&a, sizeof(struct abonnemang), 1, f);
}

void lagg_till(void){
	//Öppna datafilen i binärt läge med append (lägger till text i slutet)
	FILE *f = fopen(DATAFIL, "ab");
	//Hållare för inmatat abonneman
	struct abonnemang b;
	printf("Ange abonnemangets namn: ");
	if (!radInput(b.namn, ABNAMN_LANGD)){
		return; //Avbryter funktionen om användaren matar in EOF
	}
	printf("Ange data för %s: ", b.namn);
	scanf("%lf%d%lf%lf%lf",
		&b.per_manad,
		&b.fria_min,
		&b.extra_min,
		&b.fria_gb,
		&b.extra_gb);
	clearBuffer();
	//Skriv abonnemanget till datafilen
	fwrite(&b, sizeof(struct abonnemang), 1, f);
	//Stäng filen
	fclose(f);
}