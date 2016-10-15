#include <stdio.h>
#include <math.h>

/*
�vning 4.6, sida 84

Skriv ett program som skapar en tabell f�r uttrycket 2x^2 - 5x + 1. 
Anv�nd x-v�rden -10 till 10.

*/

int main(){
	printf("F�r uttrycket 2x^2 - 5x + 1 :");
	for (long x=-10; x!=11; x++){ //Jag kunde bara f� pow() att fungera med long f�r variabeln x och %.0f i printf. int & %d blev 0
		printf("\nx=%d: %.0f", x, 2 * pow(x,2) - 5 * x + 1);
	}
	return 0;
}

/*
Fr�n excel:
-10	251
-9	208
-8	169
-7	134
-6	103
-5	76
-4	53
-3	34
-2	19
-1	8
0	1
1	-2
2	-1
3	4
4	13
5	26
6	43
7	64
8	89
9	118
10	151
*/