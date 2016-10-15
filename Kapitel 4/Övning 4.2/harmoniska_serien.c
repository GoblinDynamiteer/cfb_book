#include <stdio.h>
/*
�vning 4.2, sida 77

Mata in ett heltal "n", ber�kna den 
"harmoniska serien" (1/1 + 1/2 + 1/3 ... + 1/n)

g�r att testa p� wolframalpha med
harmonic series k=55
(f�r n=55)

*/

int main(){
	double n, sum = 0; //variabler f�r inmatning av heltal och summa
	printf("Ange ett heltal: ");
	//S� l�nge n  inte �r noll s� loopas while-satsen. 
	scanf("%lf", &n);
	while (n != 0){
		sum = sum + (1/n);
		n--; //n-- inneb�r n=n-1, jag har valt att ber�kna sekvensen bakifr�n
	}
	printf("Summan av sekvensen blir: %0.6lf", sum); //summan avrundas till 6 decimaler
	return 0;
}