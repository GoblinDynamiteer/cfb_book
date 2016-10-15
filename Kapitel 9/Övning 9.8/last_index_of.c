#include <stdio.h>
#include <string.h>

/*
Övning 9.8, Sida 210

Gör om funktionen index_of från sida 209 
så att den gör sökningen bakifrån.

*/

//funktionen från sida 209
int index_of(const char *s, char c){
	char *p = strchr(s, c);
	if (p == NULL)
		return -1;
	else
		return p-s;
}

/*
Funktionen last_index_of, söker efter ett tecken i en sträng, med början 
från slutet och returnerar dess plats (den första som hittas)*/
int last_index_of(const char *s, char c){
	//strrchr gör samma som strchr, fast testar strängen bakifrån, det extra r-et borde vara för reverse
	char *p = strrchr(s, c); //
	if (p == NULL)
		return -1;
	else
		return p-s;
}

int main(){
	char test_string[] = "KALLEANKA123";
	char c = 'A';
	//%c i printf är för att skriva ut en enstaka char, %s fungerar inte för dem
	printf("Första instansen av %c är på plats %d i %s, sökt bakifrån",c, last_index_of(test_string, c)+1, test_string);
	return 0;
}