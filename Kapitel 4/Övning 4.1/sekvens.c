#include <stdio.h>
#include <math.h>

/*
�vning 4.1, Sida 77

Mata in ett heltal, n. Ber�kna summan av 
 2   +  4  +  9  ..... n^2
(1^2 + 2^2 + 3^2 ..... n^2)

math.h inkluderas f�r pow(x,y) som �r x^y
Det skulle ocks� g� att anv�nda n*n

*/

int main(){
	int n, sum = 0; //variabler f�r inmatning av heltal n, samt summan av sekvensen
	printf("Ange ett heltal: ");
	scanf("%d", &n);
	//S� l�nge n  inte �r noll s� loopas while-satsen. 
	while (n != 0){
		sum = sum + pow(n, 2);
		n--; //n-- inneb�r n=n-1, jag har valt att ber�kna sekvensen bakifr�n
	}
	printf("Summan av sekvensen blir: %d", sum);
	return 0;
}