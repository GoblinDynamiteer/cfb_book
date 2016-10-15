#include <stdio.h>
#include <string.h>

/*
�vning 9.8, Sida 210

G�r om funktionen index_of fr�n sida 209 
s� att den g�r s�kningen bakifr�n.

*/

//funktionen fr�n sida 209
int index_of(const char *s, char c){
	char *p = strchr(s, c);
	if (p == NULL)
		return -1;
	else
		return p-s;
}

/*
Funktionen last_index_of, s�ker efter ett tecken i en str�ng, med b�rjan 
fr�n slutet och returnerar dess plats (den f�rsta som hittas)*/
int last_index_of(const char *s, char c){
	//strrchr g�r samma som strchr, fast testar str�ngen bakifr�n, det extra r-et borde vara f�r reverse
	char *p = strrchr(s, c); //
	if (p == NULL)
		return -1;
	else
		return p-s;
}

int main(){
	char test_string[] = "KALLEANKA123";
	char c = 'A';
	//%c i printf �r f�r att skriva ut en enstaka char, %s fungerar inte f�r dem
	printf("F�rsta instansen av %c �r p� plats %d i %s, s�kt bakifr�n",c, last_index_of(test_string, c)+1, test_string);
	return 0;
}