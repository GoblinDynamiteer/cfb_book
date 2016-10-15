#include <stdio.h>

/*
�vning 6.3, Sida 111
Skriv en funktion som ber�knar antalet siffror i ett heltal. F�ruts�tt att talet �r st�rre �n noll.

Tips: G�r om funktionen siff_sum (sida 110), men r�kna varv i st�llet f�r att ber�kna summan
*/

int antal_siffror(int tal){
	int sum = 0, counter = 0;
	while(tal > 0){ //while-sats som k�r s� l�nge tal �r st�rre �n 0
		tal /= 10; //heltalsdivision med 10, inneb�r att den sista siffran i talet f�rsvinner f�r varje while-varv
		counter++; //r�knare som �kar med ett f�r varje while-varv (r�knar antal siffror)
	}
	return counter; //returnerar antalet siffror (varv som while-satsen k�rt)
}

int main(){
	int tal;
	printf("Ange ett tal, f�r att ber�kna antal siffor det inneh�ller: ");
	scanf("%d", &tal);
	printf("Det finns %d siffror i %d", antal_siffror(tal), tal);
	return 0;
}