#include <stdio.h>
#include <string.h>

/*
Övning 9.7, Sida 206

Mata in två personnummer, fyller personerna år på samma dag?

Använd strncmp(x,y,n):
Jämför x med y, högtst n antal tecken

returnerar 0 om strängarna är lika
*/

int main(){
	char pn1[12], pn2[12]; //Personnummer 1 och 2
	printf("Ange personnumer 1: ");
	scanf("%s", pn1);
	printf("Ange personnumer 2: ");
	scanf("%s", pn2);
	if (strncmp(pn1,pn2,6)){
		printf("Inte samma födelsedag!");
	}
	else{
		printf("Samma födelsedag!");
	}
	return 0;
}