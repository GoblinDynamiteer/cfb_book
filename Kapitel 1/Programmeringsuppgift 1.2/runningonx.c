#include <stdlib.h> //Innehåller "getenv"
#include <stdio.h>

int main()
{
	printf("Running on "); //Skriver ut "Running on" på skärmen
	printf(getenv("COMPUTERNAME")); //getenv hämtar miljövariabler, t.ex USERNAME, COMPUTERNAME. I detta fall hämtas datorns namn och skrivs ut
	return 0;
}