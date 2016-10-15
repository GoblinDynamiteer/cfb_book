#include <limits.h> //innehåller information om max/minvärden för datatyper
#include <float.h> //innehåller information om decimalsäkerhet för datatyper
#include <stdio.h>

int main()
{
	//INT_MAX är en konstant från limits.h som innehåller det största värdet som kan lagras i en var av typen int
	printf("Det största värdet som kan lagras i en variabel av datatypen int: %d \n", INT_MAX);
	//INT_MIN är en konstant från limits.h som innehåller det minsta värdet som kan lagras i en var av typen int
	printf("Det minsta värdet som kan lagras i en variabel av datatypen int: %d \n", INT_MIN);
	//FLT_DIG är en konstant från float.h som innehåller decimalsäkerhet för var av typen float
	printf("Decimalnoggranhet för en variabel av datatypen float: %d \n", FLT_DIG);
	//DBL_DIG är en konstant från float.h som innehåller decimalsäkerhet för var av typen double
	printf("Decimalnoggranhet för en variabel av datatypen double: %d", DBL_DIG);
	return 0;
}