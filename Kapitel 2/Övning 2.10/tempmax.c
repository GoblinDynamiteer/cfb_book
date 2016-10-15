#include <stdio.h>
#include <math.h> //innehåller matematiska funktioner, t.ex fmax, som visar det största av två tal

int main()
{
	int t1, t2, tmax; //Variabler för temperatur1, temperatur2, och temperatur max. Jag har valt att använda heltal
	printf("Ange temperatur för måndag: ");
	scanf("%d", &t1);
	printf("Ange temperatur för tisdag: ");
	scanf("%d", &t2);
	tmax = fmax(t1, t2); //fmax jämför och hämtar det störa av två värden, i detta fall sätts det till var tmax
	printf("Ange temperatur för onsdag: ");
	scanf("%d", &t2);
	//det redan satta tmax jämförs nu med värdet i t2 som sätts av användare för alla nästkommande dagar.
	//är tmax fortfarande större än det inmatade värdet så sätts det åter i tmax.
	tmax = fmax(tmax, t2); 
	printf("Ange temperatur för torsdag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	printf("Ange temperatur för fredag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	printf("Ange temperatur för lördag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	printf("Ange temperatur för söndag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	//skriver ut tmax, som nu innehåller det största av alla inmatade temperaturer:
	printf("Den högsta temperaturen som uppmättes under veckan är: %d", tmax); 
	return 0;
}