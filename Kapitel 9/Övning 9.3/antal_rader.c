#include <stdio.h>

/*
Övning 9.3, Sida 192

Skriv ett program som räknar hur många rader användaren skriver in.
Inmatningen ska avbrytas med EOF.

Tips: Räkna antalet "\n"
*/

int main(){
	int raknare = 0;
	char c;
printf("Skriv in ett antal rader.\nAvbryt med EOF (CTRL+Z i Windows):\n");
	//while-sats körs så länge användaren inte matar in EOF
	while ((c = getchar()) != EOF){
		if(c == '\n'){ //ökar räknare med ett för varje newline
			raknare++;
		}
	}
	printf("Antal rader: %d", raknare);
}