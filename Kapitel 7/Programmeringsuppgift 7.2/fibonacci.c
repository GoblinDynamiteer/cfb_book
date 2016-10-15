#include <stdio.h>
//För att skriva ut linjer i printf med newline före och efter:
#define L "\n---------------------------------------\n" 


/*
Programmeringsuppgift 7.2, Sida 146

Skriv en funktion som varje gång man anropar den
skriver ut nästa tal i Fibonacci-serien. Den ska börja på 
det tredje talet. Använd två statiska variabler för att hålla
reda på talen.

Fibonacci-serien:
En serie heltal där varje tal är summan av de två föregående

ex: 2 3 5 8 13 21

Funktionen main skriver ut de första 20 talen.

*/

//Statiska variabler för hållande av tal i serien
static int tal1 = 1;
static int tal2 = 2;

//Funktion som returnerar ett Fibonacci-tal
int fibbos_talfoljd(void){
	int fibbo = tal1+tal2; 	//Nästa tal i serien efter tal1 och tal2
	tal1 = tal2; 					//tal1 byter till tal2
	tal2 = fibbo;					//tal2 byter till det beräknade Fibonacci-talet
	return fibbo;				//returnerar det beräknade Fibonacci-talet
}


int main(){
	int antal, tal_pa_linje =1;
	//Jag har valt att låta användaren mata in hur många tal man vill se i serien:
	printf("Hur många fibbo-tal vill du se?: "); 
	scanf("%d", &antal);
	printf("%s   Fibonacci-serien upp till %d%s", L,antal,L); //L är en linje med returslag före och efter, definieras ovan
	for(int i = 1; i <= antal; i++){						//for-sats som körs 'antal' varv
		printf("%d\t\t", fibbos_talfoljd());				//Skriver ut det reurnerade talet från funktinen fibbos_talfoljd, och två tabb-slag (\t) för snygghet
		tal_pa_linje++;
		if (tal_pa_linje == 4){								//om tre tal har skrivits på en rad, slås printas en ny rad ut, för snygghet i utskrift
			printf("\n");
			tal_pa_linje = 1;
		}
	}
	printf("%s", L);
	return 0;
}