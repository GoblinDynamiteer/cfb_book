#include <stdio.h>
	
	/*
	�vning 8.7, Sida 168
	
	Skriv funktion: fyll
	
	Funktionen ska skriva ett inmatat v�rde i ett visst intervall till ett f�lt
	L�t f�ltet ha element av typen double
	
	Den ska ha fyra parametrar:
		Det f�rsta f�ltet
		Undre index
		�vre index
		V�rde
	
	Ex:
	F�r att l�gga till v�rdet 2.3 i elementen 5-9 s� skall anropet vara:
	fyll(f, 5, 9, 2.3)
	
	*/


/*
Funktion som tilldelar ett (samma) v�rde till en array, i ett indexspann
Arrayv�rden som s�tts i en funktion beh�ller sina v�rden. J�mf�r med
"vanliga" variabler d�r v�rdet kopieras till funktionens variabler, och 
d�rmed inte kan �ndras.
*/
void fyll(double f[], int start, int stopp, double varde){
	for(start; start <= stopp; start++){
		f[start] = varde;
	}
}
	
int main(){
	double varde;
	int start, stopp;
	printf("Ange v�rde: ");
	scanf("%lf", &varde);
	printf("Ange start f�r index-spann att skriva till: ");
	scanf("%d", &start);
	printf("Ange slut f�r index-spann att skriva till: ");
	scanf("%d", &stopp);
	//En array skapas med lika m�nga element som stopp �r stort
	double array[stopp];
	fyll(array, start, stopp, varde);
	/*
	Endast de v�rden som �r skrivna till arrayen skrivs ut, de andra inneh�ller "skr�pdata"
	for-satsen �r lik den som anv�nds i funktionen. Den k�r medan v�rdet f�r start
	�r minde �n stopp i index-spannet som ska tilldelas v�rden.
	*/
	for(start; start <= stopp; start++){
		printf("array[%d]: %.2f\n", start, array[start]);
	}
	return 0;
}