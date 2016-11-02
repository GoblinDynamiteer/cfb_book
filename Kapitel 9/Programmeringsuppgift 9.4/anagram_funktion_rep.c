#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define N 20

/* 
Programmeringsuppgift 9.4, Sida 215 - repetition

Skriv en funktion 'ar_anagram', som j�mf�r tv� textstr�ngar.
Om den ena str�ngen �r ett anagram av den andra, s� ska 1
returneras, annars 0. Funktionen ska vara booleansk typ och
ha de tv� textstr�ngarna som parametrar.

Tips: Ta bort vita tecken i texterna innan j�mf�relse.

Ett anagram �r en tex/mening som bildar en annan text/mening
om man kastar om bokst�verna.

Ex:
Curt �rlig -> C �r lurigt 
Melt Rolls -> Slemtroll
Rack Rots -> RockStar
*/

bool ar_anagram(char *a, char *b);
void remSpaceLower(char *a, char b[]);

int main(){
	char a[N] = "Rack Rots", b[N] = "RockStar";
	if(ar_anagram(a,b)){
		printf("Anagram!");
	}
	else{
		printf("Ej Anagram! :(");
	}
	return 0;
}

bool ar_anagram(char *a, char *b){
	char c[N], d[N];
	remSpaceLower(a,c);
	remSpaceLower(b,d);
	//Kollar om str�ngarna �r lika l�nga
	if(strlen(d) != strlen(c)){
		return false;
	}
	for(int i=0;i<strlen(d);i++){
		char check = *(c+i);
		int countc =0, countd = 0;
		for(int j=0;j<strlen(d);j++){
			//R�knar hur m�nga tecken som hittas i av varje tecken i str�ng 1, i de b�da str�ngarna
			countc = (check == *(c+j)) ? countc+1 : countc;
			countd = (check == *(d+j)) ? countd+1 : countd;
		}
		printf("Hittade %dst '%c' i %s\n",countc, check, a); //F�r debug
		printf("Hittade %dst '%c' i %s\n",countd, check, b); //F�r debug
		if(countc != countd){
			return false;
		}
	}
	return true;
}

//Kopierar a till b, tar bort mellanslag och g�r till gemen
void remSpaceLower(char *a, char b[]){
	int i=0;
	while(*a){
		if(!isspace(*a)){
			b[i++] = tolower(*a);
			a++;
		}
		else{
			a++;
		}
	}
	b[i] = '\0';
}