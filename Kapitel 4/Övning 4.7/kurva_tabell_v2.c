#include <stdio.h>
#include <math.h>

/*
Övning 4.7, sida 85
Skriv om programmet i övn 4.6 så x-värdet är mellan -1 och 1, med 0.1-steg intervall

*/

int main(){
	printf("För uttrycket 2x^2 - 5x + 1 :");
	for (double x=-1; x<=1; x=x+.1){
		printf("\nx=%.1f: %.2f", x, 2 * pow(x,2) - 5 * x + 1);
	}
	return 0;
}

/*
Från excel:
-1		8
-0,9	7,12
-0,8	6,28
-0,7	5,48
-0,6	4,72
-0,5	4
-0,4	3,32
-0,3	2,68
-0,2	2,08
-0,1	1,52
0		1
0,1	0,52
0,2	0,08
0,3	-0,32
0,4	-0,68
0,5	-1
0,6	-1,28
0,7	-1,52
0,8	-1,72
0,9	-1,88
1		-2

*/