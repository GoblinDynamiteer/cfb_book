/* Programmeringsuppgift 11.5, Sida 276 - repetition

Skriv en egen version av strpbrk. 
Använd inte indexering, använd pekare!

strpbrk(str1, str2) Letar upp det första tecknet i en sträng som matchar 
NÅGOT av tecknen i str2. Returvärdet är en pekare till tecket som hittas. 
Eller NULL om inget tecken hittas i strängen. */

#include <stdio.h>

char *strpbrk_egen(char *string, char *token);

int main(){
	char *a = strpbrk_egen("ABCDEFGHIJKLMNOPQabcdefghijklmnopq", "abc");
	printf("Hittade tecken: %c", *a);
	printf("\nSträng: %s", a);
}


char *strpbrk_egen(char *string, char *token){
	while(*string){ //Medans tecken inte är '\0'
		char *p_token = token; //Sätter temporär pekare till token
		while(*p_token){ //medans tecken inte är '\0'
			/*Testar varje tecken i pekare p_token mot tecken i string, returnerar aktuell pekare
			för string om hittas (det är det första tecknet i strängen som matchar) */
			if(*p_token == *string){
				return string;
			}
			p_token++;
		}
		string++;
	}
	return 0; //returnerar 0 om inget tecken matchar
}