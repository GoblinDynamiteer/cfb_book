#include <stdio.h>
#include <math.h> //inneh�ller matematiska funktioner, t.ex fmax, som visar det st�rsta av tv� tal

int main()
{
	int t1, t2, tmax; //Variabler f�r temperatur1, temperatur2, och temperatur max. Jag har valt att anv�nda heltal
	printf("Ange temperatur f�r m�ndag: ");
	scanf("%d", &t1);
	printf("Ange temperatur f�r tisdag: ");
	scanf("%d", &t2);
	tmax = fmax(t1, t2); //fmax j�mf�r och h�mtar det st�ra av tv� v�rden, i detta fall s�tts det till var tmax
	printf("Ange temperatur f�r onsdag: ");
	scanf("%d", &t2);
	//det redan satta tmax j�mf�rs nu med v�rdet i t2 som s�tts av anv�ndare f�r alla n�stkommande dagar.
	//�r tmax fortfarande st�rre �n det inmatade v�rdet s� s�tts det �ter i tmax.
	tmax = fmax(tmax, t2); 
	printf("Ange temperatur f�r torsdag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	printf("Ange temperatur f�r fredag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	printf("Ange temperatur f�r l�rdag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	printf("Ange temperatur f�r s�ndag: ");
	scanf("%d", &t2);
	tmax = fmax(tmax, t2);
	//skriver ut tmax, som nu inneh�ller det st�rsta av alla inmatade temperaturer:
	printf("Den h�gsta temperaturen som uppm�ttes under veckan �r: %d", tmax); 
	return 0;
}