#include <stdio.h>
//F�r att skriva ut linjer i printf med newline f�re och efter:
#define L "\n---------------------------------------\n" 


/*
Programmeringsuppgift 7.2, Sida 146

Skriv en funktion som varje g�ng man anropar den
skriver ut n�sta tal i Fibonacci-serien. Den ska b�rja p� 
det tredje talet. Anv�nd tv� statiska variabler f�r att h�lla
reda p� talen.

Fibonacci-serien:
En serie heltal d�r varje tal �r summan av de tv� f�reg�ende

ex: 2 3 5 8 13 21

Funktionen main skriver ut de f�rsta 20 talen.

*/

//Statiska variabler f�r h�llande av tal i serien
static int tal1 = 1;
static int tal2 = 2;

//Funktion som returnerar ett Fibonacci-tal
int fibbos_talfoljd(void){
	int fibbo = tal1+tal2; 	//N�sta tal i serien efter tal1 och tal2
	tal1 = tal2; 					//tal1 byter till tal2
	tal2 = fibbo;					//tal2 byter till det ber�knade Fibonacci-talet
	return fibbo;				//returnerar det ber�knade Fibonacci-talet
}


int main(){
	int antal, tal_pa_linje =1;
	//Jag har valt att l�ta anv�ndaren mata in hur m�nga tal man vill se i serien:
	printf("Hur m�nga fibbo-tal vill du se?: "); 
	scanf("%d", &antal);
	printf("%s   Fibonacci-serien upp till %d%s", L,antal,L); //L �r en linje med returslag f�re och efter, definieras ovan
	for(int i = 1; i <= antal; i++){						//for-sats som k�rs 'antal' varv
		printf("%d\t\t", fibbos_talfoljd());				//Skriver ut det reurnerade talet fr�n funktinen fibbos_talfoljd, och tv� tabb-slag (\t) f�r snygghet
		tal_pa_linje++;
		if (tal_pa_linje == 4){								//om tre tal har skrivits p� en rad, sl�s printas en ny rad ut, f�r snygghet i utskrift
			printf("\n");
			tal_pa_linje = 1;
		}
	}
	printf("%s", L);
	return 0;
}