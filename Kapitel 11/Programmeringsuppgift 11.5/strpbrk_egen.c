#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 11.5, Sida 276

Skriv en egen version av strpbrk. 

Anv�nd inte indexering, anv�nd pekare!


strpbrk(str1, str2)
Letar upp det f�rsta tecknet i en str�ng som matchar N�GOT av tecknen i str2.
Returv�rdet �r en pekare till tecket som hittas. Eller NULL om inget tecken hittas
i str�ngen.

 */

char *strpbrk_egen(char *string1, char *string2){
	printf("Funktion: string 1 l�ngd: %d\n", strlen(string1));
	printf("Funktion: string 2 l�ngd: %d\n", strlen(string2));
	for(int i=0;i<strlen(string2);i++){ //BYGG WHILE-LOOP?!
		for(int j=0;j<strlen(string1);j++){
			if (*(string2+i) == *(string1+j)){
				printf("Funktion: Hittade tecken och returnerar: %c - p� adress %p\n", *(string1+j), string1+j);
				return string1+j;
			}
		}
	}
	printf("Funktion: returnerar null, tecknet hittades inte!\n");
	return NULL;
}
 
int main(){
	char *pekare;
	pekare = strpbrk_egen("Text att s�ka i ABCDEFGHq", "qex");
	if (pekare == NULL){
		printf("Main: Funktionen returnerade NULL");
	}
	else {
		printf("Main: Funktionen returnerade %c - p� adress %p, satt till pekare", *pekare, pekare);
	}
	return 0;
}