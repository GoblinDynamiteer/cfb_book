#include <stdio.h>

/* Programmeringsuppgift 11.3, Sida 276

Kolla om två vektorer är 'ortogonala'
Detta görs med formeln:
a1*b1+a2*b2+a3*b3+.......an*bn
blir summan lika med noll är de ortogonala.

Skriv en funktion som får två heltalsfält, samt 
en int som visar fältens längd.

Använd pekare, inte indexering! 

Ex på ortogonal vektor:
a	1		3		2
b	3		-1		0
	3	+	-3	+ 	0 = 0
*/


_Bool arOrto(int *a, int *b, int n){
	int summa = 0;
	for(int *pekare = a;pekare<a+n;summa += *pekare++ * *b++){
		//summa += *pekare**b;
		//printf("%d\t", summa);
	}
	//returnerar 1 om summa är 0, annars 1
	return summa==0;
}

int main(){
	int a[3] = {1,3,2};
	int b[3] = {3,-1,0};
	if(arOrto(a,b,3)){
		printf("Orto!");
	}
	else{
		printf("Ej orto!");
	}
	return 0;
}