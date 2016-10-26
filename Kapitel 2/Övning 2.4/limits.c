#include <limits.h> //inneh�ller information om max/minv�rden f�r datatyper
#include <float.h> //inneh�ller information om decimals�kerhet f�r datatyper
#include <stdio.h>

/* �vning 2.4, Sida 40
Skriv ett program som skriver ut det st�rsta och minsta tal en variabel av typen int kan lagra.
Skriv ocks� ut hur m�nga decimalers noggrannhet man f�r med typerna double och float. */

int main()
{
	//INT_MAX �r en konstant fr�n limits.h som inneh�ller det st�rsta v�rdet som kan lagras i en var av typen int
	printf("Det st�rsta v�rdet som kan lagras i en variabel av datatypen int: %d \n", INT_MAX);
	//INT_MIN �r en konstant fr�n limits.h som inneh�ller det minsta v�rdet som kan lagras i en var av typen int
	printf("Det minsta v�rdet som kan lagras i en variabel av datatypen int: %d \n", INT_MIN);
	//FLT_DIG �r en konstant fr�n float.h som inneh�ller decimals�kerhet f�r var av typen float
	printf("Decimalnoggranhet f�r en variabel av datatypen float: %d \n", FLT_DIG);
	//DBL_DIG �r en konstant fr�n float.h som inneh�ller decimals�kerhet f�r var av typen double
	printf("Decimalnoggranhet f�r en variabel av datatypen double: %d", DBL_DIG);
	return 0;
}