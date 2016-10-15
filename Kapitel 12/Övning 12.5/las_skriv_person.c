#include <stdio.h>
#include <ctype.h> //för tolower()
#include "person.h"

/* Övning 12.5, Sida 295

Skriv om programmet på sida 287 så att inläsningen av
personens data sker i en funktion kallad 'las_person' och
utskriften ska ske i en funktion kallad 'skriv_person'. */

int main(){
	struct person p, a;
	las_person(&p);
	las_person(&a);
	skriv_person(&p);
	skriv_person(&a);
}

//Inläsning av person
void las_person(struct person *p){
	printf("Förnamn: ");
	//(*p).fornamn och p -> fornamn är samma sak (?)
	scanf("%s", (*p).fornamn);
	printf("Efternamn: ");
	scanf("%s", p -> efternamn);
	printf("Födelseår: ");
	//Likt "vanlig" scanf med %d måste det vara till variabelns adress
	scanf("%d", &p -> fodd_ar);
	printf("Singel?: ");
	char svar_singel[20];
	scanf("%s", svar_singel);
	if(tolower(svar_singel[0]) == 'j'){
		p -> singel = 1;
	}
	else {
		p -> singel = 0;
	}
}

//Utskrift av person
void skriv_person(struct person *p){
	printf("%s %s, född år %d, är ", p -> fornamn, p -> efternamn, p -> fodd_ar);
	if(p -> singel){
		printf("singel!\n");
	}
	else{
		printf("inte singel!\n");
	}
}