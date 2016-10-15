#include <math.h> //f�r logaritm log(x) och konstanten M_E (e)
#include <stdio.h>
#define LAMBDA log(2) / 5730 //S�tter konstanten LAMBDA f�r �mnet kol-14

/*
Ange hur m�nga procent som �terst�r av isotopen kol-14 efter S �r.
S anges av anv�ndaren.

m�ngen kvarvarande radioaktivt avfall n efter tid t ber�knas med

n = n0 * e^-(lambda * t)

n0 �r �mnets m�ngd vid tiden tiden 0
lambda �r en konstant f�r ett visst radioaktivt �mne och ber�knas med

lambda = ln(2) / T

T �r halveringstiden f�r �mnet
F�r kol-14 �r halveringstiden T = 5730 �r.

Test: Om vi s�tter S=T=t s� borde n bli h�lften av �mnets vikt
vi best�mmer n=50

n = n0 * e^-(lambda * t) = 50 * e^-(ln(2) / 5730 * 5730)  = 50 * e^-(ln(2) = 25
25/50 = 0.5 = 50%
*/

int main ()
{
	int S;	//Variabel f�r antal �r, 
	float n0 = 50, n; //n0 = materalets m�ngd vid tid noll, ett v�rde beh�vs(?) f�r att kunna ber�kna �terst�ende procent
	printf("Ange antal �r (S): ");
	scanf("%d", &S); //anv�ndaren s�tter antal �r
	n = n0 * pow(M_E, -LAMBDA * S); //ber�knar n enligt formel
	//Skriver ut hur m�nga procent som �terst�r av �mnet kol-14 efter S antal �r:
	printf("Efter %d antal �r �terst�r %.2f procent av det radioaktiva �mnet kol-14", S, (n/n0)*100);
	return 0;
}