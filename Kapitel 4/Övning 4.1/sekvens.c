#include <stdio.h>
#include <math.h>

/*
Övning 4.1, Sida 77

Mata in ett heltal, n. Beräkna summan av 
 2   +  4  +  9  ..... n^2
(1^2 + 2^2 + 3^2 ..... n^2)

math.h inkluderas för pow(x,y) som är x^y
Det skulle också gå att använda n*n

*/

int main(){
	int n, sum = 0; //variabler för inmatning av heltal n, samt summan av sekvensen
	printf("Ange ett heltal: ");
	scanf("%d", &n);
	//Så länge n  inte är noll så loopas while-satsen. 
	while (n != 0){
		sum = sum + pow(n, 2);
		n--; //n-- innebär n=n-1, jag har valt att beräkna sekvensen bakifrån
	}
	printf("Summan av sekvensen blir: %d", sum);
	return 0;
}