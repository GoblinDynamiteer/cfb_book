#include <stdio.h>

/*
�vning 9.3, Sida 192

Skriv ett program som r�knar hur m�nga rader anv�ndaren skriver in.
Inmatningen ska avbrytas med EOF.

Tips: R�kna antalet "\n"
*/

int main(){
	int raknare = 0;
	char c;
printf("Skriv in ett antal rader.\nAvbryt med EOF (CTRL+Z i Windows):\n");
	//while-sats k�rs s� l�nge anv�ndaren inte matar in EOF
	while ((c = getchar()) != EOF){
		if(c == '\n'){ //�kar r�knare med ett f�r varje newline
			raknare++;
		}
	}
	printf("Antal rader: %d", raknare);
}