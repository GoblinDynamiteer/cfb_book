#include <stdio.h>
#include <math.h> //för test med sqrt(x) - kvadratroten ur x, fabs(x) och pow(x,y)

/*
Programmeringsuppgift 6.11, Sida 122

Konstruera en funktion som beräknar kvadratroten av ett tal x

Använd "Newtons metod":
gissa ett tal g >= 0

det måste finnas ett annat tal h där

g * h = x

bryt ut h:

h = x/g

om g =~ h så har man funnit lösningen

om man "gissat dåligt" kan man göra en bättre gissning med

gny = (g+(x/g))/2  <-- Detta är medevärdet av g & h:   (g+h)/2  ---> där h = x/g ---> (g+(x/g))/2

sedan g = gny och beräkna ett nytt h (x/g)

skapa en funktion som beräknar kvadratroten ur x
forstätt tills skillnaden mellan två gissningar är mindre än 10^-6

*/

//Funktion för newtons metod, ger ungefärlig kvadratrot ur x
double newton(double x){
	double g = x/2; //första gissningen, halva x
	double gny = (g+(x/g))/2; //gissning ny: medelvärdet av h och g
	//körs medan absolutvärdet av skillnaden mellan g och gny är större än 10^-6:
	while (fabs(gny-g) > pow(10,-6)){ 
		g = gny;	//gissning sätts till den nya framtagna gissningen gny
		gny = (g+(x/g))/2;	//ny bättre gissning tas fram från medelvärdet av h & g
	}
	return gny;
}

int main(){
	double x;
	printf("Ange x: ");
	scanf("%lf",&x);
	printf("Kvadratroten ur %.2lf är %.3lf", x, newton(x));
	printf("\n--------------------------------------------");
	printf("\nTest sqrt(x) - Kvadratroten ur %.2lf är %.3lf", x, sqrt(x)); //skriver ut kvadratroten ur x, med sqrt(x) från math.h. För jämförelse
	printf("\nTest pow(%.2lf),2) - %.2lf^2 är %.3lf",newton(x),newton(x),pow(newton(x),2)); //testar värdet från funktionen ^2 , ska ge x
	return 0;
}