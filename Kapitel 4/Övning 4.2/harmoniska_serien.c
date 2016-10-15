#include <stdio.h>
/*
Övning 4.2, sida 77

Mata in ett heltal "n", beräkna den 
"harmoniska serien" (1/1 + 1/2 + 1/3 ... + 1/n)

går att testa på wolframalpha med
harmonic series k=55
(för n=55)

*/

int main(){
	double n, sum = 0; //variabler för inmatning av heltal och summa
	printf("Ange ett heltal: ");
	//Så länge n  inte är noll så loopas while-satsen. 
	scanf("%lf", &n);
	while (n != 0){
		sum = sum + (1/n);
		n--; //n-- innebär n=n-1, jag har valt att beräkna sekvensen bakifrån
	}
	printf("Summan av sekvensen blir: %0.6lf", sum); //summan avrundas till 6 decimaler
	return 0;
}