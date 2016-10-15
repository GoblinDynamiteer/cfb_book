#include <math.h> //för logaritm log(x) och konstanten M_E (e)
#include <stdio.h>
#define LAMBDA log(2) / 5730 //Sätter konstanten LAMBDA för ämnet kol-14

/*
Ange hur många procent som återstår av isotopen kol-14 efter S år.
S anges av användaren.

mängen kvarvarande radioaktivt avfall n efter tid t beräknas med

n = n0 * e^-(lambda * t)

n0 är ämnets mängd vid tiden tiden 0
lambda är en konstant för ett visst radioaktivt ämne och beräknas med

lambda = ln(2) / T

T är halveringstiden för ämnet
För kol-14 är halveringstiden T = 5730 år.

Test: Om vi sätter S=T=t så borde n bli hälften av ämnets vikt
vi bestämmer n=50

n = n0 * e^-(lambda * t) = 50 * e^-(ln(2) / 5730 * 5730)  = 50 * e^-(ln(2) = 25
25/50 = 0.5 = 50%
*/

int main ()
{
	int S;	//Variabel för antal år, 
	float n0 = 50, n; //n0 = materalets mängd vid tid noll, ett värde behövs(?) för att kunna beräkna återstående procent
	printf("Ange antal år (S): ");
	scanf("%d", &S); //användaren sätter antal år
	n = n0 * pow(M_E, -LAMBDA * S); //beräknar n enligt formel
	//Skriver ut hur många procent som återstår av ämnet kol-14 efter S antal år:
	printf("Efter %d antal år återstår %.2f procent av det radioaktiva ämnet kol-14", S, (n/n0)*100);
	return 0;
}