/* Programmeringsuppgift 11.5, Sida 276 - repetition

Skriv en egen version av strpbrk. 
Anv�nd inte indexering, anv�nd pekare!

strpbrk(str1, str2) Letar upp det f�rsta tecknet i en str�ng som matchar 
N�GOT av tecknen i str2. Returv�rdet �r en pekare till tecket som hittas. 
Eller NULL om inget tecken hittas i str�ngen. */

#include <stdio.h>

char *strpbrk_egen(char *string, char *token);

int main(){
	char *a = strpbrk_egen("ABCDEFGHIJKLMNOPQabcdefghijklmnopq", "abc");
	printf("Hittade tecken: %c", *a);
	printf("\nStr�ng: %s", a);
}


char *strpbrk_egen(char *string, char *token){
	while(*string){ //Medans tecken inte �r '\0'
		char *p_token = token; //S�tter tempor�r pekare till token
		while(*p_token){ //medans tecken inte �r '\0'
			/*Testar varje tecken i pekare p_token mot tecken i string, returnerar aktuell pekare
			f�r string om hittas (det �r det f�rsta tecknet i str�ngen som matchar) */
			if(*p_token == *string){
				return string;
			}
			p_token++;
		}
		string++;
	}
	return 0; //returnerar 0 om inget tecken matchar
}