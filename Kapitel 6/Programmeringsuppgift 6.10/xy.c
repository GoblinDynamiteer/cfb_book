#include <stdio.h>
#include <math.h> //för M_E, pow(x,y), och log(x)

/*
Programmeringsuppgift 6.10, Sida 122

Konstruera en funktion upphoj som beräknar
x^y, där både x och y är reella tal

Använd 
x^y  = e^(y*ln(x))


*/

//funktion som beräkna x^y
double xy(double x, double y){
	return pow(M_E,(y*log(x))); //e^(y*ln(x))
}

int main(){
	double x,y;
	printf("Ange x:");
	scanf("%lf",&x);
	printf("Ange y:");
	scanf("%lf",&y);
	printf("Resultat: %.2lf^%.2lf \t= %.2lf", x,y,xy(x,y));
	//Använder pow(x,y) från math.h för att se om resultatet från funktionen stämmer:
	printf("\nTest - pow(%.2lf,%.2lf) \t= %.2lf: ",x,y,pow(x,y)); 
	return 0;
}