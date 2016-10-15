#include <stdio.h>

int main()
{
	printf("Datatypen char: \t%d byte\n", sizeof(char)); 
	//sizeof tar reda på hur många byte en datatyp eller variabel representeras av i kompilatorn
	printf("Datatypen short int: \t%d byte\n", sizeof(short int)); 
	printf("Datatypen int: \t\t%d byte\n", sizeof(int)); 
	printf("Datatypen long int: \t%d byte\n", sizeof(long int)); 
	printf("Datatypen long long int: %d byte\n", sizeof(long long int)); 
	printf("Datatypen float: \t%d byte\n", sizeof(float)); 
	printf("Datatypen double: \t%d byte\n", sizeof(double)); 
	printf("Datatypen long double: \t%d byte\n", sizeof(long double)); 
	return 0;
}