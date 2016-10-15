#include <stdio.h>
#include <math.h> //f�r M_E, pow(x,y), och log(x)

/*
Programmeringsuppgift 6.10, Sida 122

Konstruera en funktion upphoj som ber�knar
x^y, d�r b�de x och y �r reella tal

Anv�nd 
x^y  = e^(y*ln(x))


*/

//funktion som ber�kna x^y
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
	//Anv�nder pow(x,y) fr�n math.h f�r att se om resultatet fr�n funktionen st�mmer:
	printf("\nTest - pow(%.2lf,%.2lf) \t= %.2lf: ",x,y,pow(x,y)); 
	return 0;
}