#include <stdio.h>
#include <string.h>

/*
�vning 9.7, Sida 206

Mata in tv� personnummer, fyller personerna �r p� samma dag?

Anv�nd strncmp(x,y,n):
J�mf�r x med y, h�gtst n antal tecken

returnerar 0 om str�ngarna �r lika
*/

int main(){
	char pn1[12], pn2[12]; //Personnummer 1 och 2
	printf("Ange personnumer 1: ");
	scanf("%s", pn1);
	printf("Ange personnumer 2: ");
	scanf("%s", pn2);
	if (strncmp(pn1,pn2,6)){
		printf("Inte samma f�delsedag!");
	}
	else{
		printf("Samma f�delsedag!");
	}
	return 0;
}