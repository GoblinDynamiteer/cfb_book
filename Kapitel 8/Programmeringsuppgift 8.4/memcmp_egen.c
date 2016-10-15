#include <stdio.h>
#include <math.h> //f�r fmin(x,y)
/*
Programmeringsuppgift 8.4, Sida 179

Skriv en egen version av funktionen memcmp

memcmp:
J�mf�r elementen i tv� arrayer, returnerar 1 om alla �r lika, annars 0.


Funktion som j�mf�r antal element samt elementens inneh�ll i tv� arrayer. Om 
arrayerna �r lika returneras 1, annars 0
Parametrar �r tv� arrayer, samt storlekarna f�r arrayerna. 
Eventuellt ska inte element-antal j�mf�ras.
*/
_Bool memcmp_egen(double a[], double b[], int storlek_a, int storlek_b){
	if (storlek_a != storlek_b)
		return 0;
	for(int i=0;i<storlek_a;i++){
		if(a[i] != b[i]){
			return 0;
		}
	}
	return 1;
}


int main(){
	double a[15]; 
	double b[15];
	//s�tter int variabler till antalet element f�r de tv� f�lten
	int storlek_a = sizeof a/sizeof a[0];
	int storlek_b = sizeof b/sizeof b[0];
	/*
	for-sats som s�tter samma v�rde till b�da arrayerna a och b, f�r test
	�ndra f�r att testa om arrayerna inneh�ller olika v�rden.
	
	for-sats som k�rs lika m�nga g�nger som det minsta antal element
	i de tv� arrayerna
	*/
	for(int i=0;i<fmin(storlek_a,storlek_b);i++){
		a[i] = i;
		b[i] = i;
	}
	if(memcmp_egen(a,b, storlek_a, storlek_b)){
		printf("Arrayerna �r lika!");
	}
	else {
		printf("Arrayerna �r olika!");
	}
	return 0;
}

