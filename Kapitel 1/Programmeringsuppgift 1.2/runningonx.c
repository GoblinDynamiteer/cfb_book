#include <stdlib.h> //Inneh�ller "getenv"
#include <stdio.h>

int main()
{
	printf("Running on "); //Skriver ut "Running on" p� sk�rmen
	printf(getenv("COMPUTERNAME")); //getenv h�mtar milj�variabler, t.ex USERNAME, COMPUTERNAME. I detta fall h�mtas datorns namn och skrivs ut
	return 0;
}