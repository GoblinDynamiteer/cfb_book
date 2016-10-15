#include <stdio.h>
#include <math.h> //för fmin(x,y)
/*
Programmeringsuppgift 8.4, Sida 179

Skriv en egen version av funktionen memcmp

memcmp:
Jämför elementen i två arrayer, returnerar 1 om alla är lika, annars 0.


Funktion som jämför antal element samt elementens innehåll i två arrayer. Om 
arrayerna är lika returneras 1, annars 0
Parametrar är två arrayer, samt storlekarna för arrayerna. 
Eventuellt ska inte element-antal jämföras.
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
	//sätter int variabler till antalet element för de två fälten
	int storlek_a = sizeof a/sizeof a[0];
	int storlek_b = sizeof b/sizeof b[0];
	/*
	for-sats som sätter samma värde till båda arrayerna a och b, för test
	Ändra för att testa om arrayerna innehåller olika värden.
	
	for-sats som körs lika många gånger som det minsta antal element
	i de två arrayerna
	*/
	for(int i=0;i<fmin(storlek_a,storlek_b);i++){
		a[i] = i;
		b[i] = i;
	}
	if(memcmp_egen(a,b, storlek_a, storlek_b)){
		printf("Arrayerna är lika!");
	}
	else {
		printf("Arrayerna är olika!");
	}
	return 0;
}

