#include <stdio.h>
#include <math.h> //f�r test med sqrt(x) - kvadratroten ur x, fabs(x) och pow(x,y)

/*
Programmeringsuppgift 6.11, Sida 122

Konstruera en funktion som ber�knar kvadratroten av ett tal x

Anv�nd "Newtons metod":
gissa ett tal g >= 0

det m�ste finnas ett annat tal h d�r

g * h = x

bryt ut h:

h = x/g

om g =~ h s� har man funnit l�sningen

om man "gissat d�ligt" kan man g�ra en b�ttre gissning med

gny = (g+(x/g))/2  <-- Detta �r medev�rdet av g & h:   (g+h)/2  ---> d�r h = x/g ---> (g+(x/g))/2

sedan g = gny och ber�kna ett nytt h (x/g)

skapa en funktion som ber�knar kvadratroten ur x
forst�tt tills skillnaden mellan tv� gissningar �r mindre �n 10^-6

*/

//Funktion f�r newtons metod, ger ungef�rlig kvadratrot ur x
double newton(double x){
	double g = x/2; //f�rsta gissningen, halva x
	double gny = (g+(x/g))/2; //gissning ny: medelv�rdet av h och g
	//k�rs medan absolutv�rdet av skillnaden mellan g och gny �r st�rre �n 10^-6:
	while (fabs(gny-g) > pow(10,-6)){ 
		g = gny;	//gissning s�tts till den nya framtagna gissningen gny
		gny = (g+(x/g))/2;	//ny b�ttre gissning tas fram fr�n medelv�rdet av h & g
	}
	return gny;
}

int main(){
	double x;
	printf("Ange x: ");
	scanf("%lf",&x);
	printf("Kvadratroten ur %.2lf �r %.3lf", x, newton(x));
	printf("\n--------------------------------------------");
	printf("\nTest sqrt(x) - Kvadratroten ur %.2lf �r %.3lf", x, sqrt(x)); //skriver ut kvadratroten ur x, med sqrt(x) fr�n math.h. F�r j�mf�relse
	printf("\nTest pow(%.2lf),2) - %.2lf^2 �r %.3lf",newton(x),newton(x),pow(newton(x),2)); //testar v�rdet fr�n funktionen ^2 , ska ge x
	return 0;
}