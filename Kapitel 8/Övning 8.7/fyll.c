#include <stdio.h>
	
	/*
	Övning 8.7, Sida 168
	
	Skriv funktion: fyll
	
	Funktionen ska skriva ett inmatat värde i ett visst intervall till ett fält
	Låt fältet ha element av typen double
	
	Den ska ha fyra parametrar:
		Det första fältet
		Undre index
		Övre index
		Värde
	
	Ex:
	För att lägga till värdet 2.3 i elementen 5-9 så skall anropet vara:
	fyll(f, 5, 9, 2.3)
	
	*/


/*
Funktion som tilldelar ett (samma) värde till en array, i ett indexspann
Arrayvärden som sätts i en funktion behåller sina värden. Jämför med
"vanliga" variabler där värdet kopieras till funktionens variabler, och 
därmed inte kan ändras.
*/
void fyll(double f[], int start, int stopp, double varde){
	for(start; start <= stopp; start++){
		f[start] = varde;
	}
}
	
int main(){
	double varde;
	int start, stopp;
	printf("Ange värde: ");
	scanf("%lf", &varde);
	printf("Ange start för index-spann att skriva till: ");
	scanf("%d", &start);
	printf("Ange slut för index-spann att skriva till: ");
	scanf("%d", &stopp);
	//En array skapas med lika många element som stopp är stort
	double array[stopp];
	fyll(array, start, stopp, varde);
	/*
	Endast de värden som är skrivna till arrayen skrivs ut, de andra innehåller "skräpdata"
	for-satsen är lik den som används i funktionen. Den kör medan värdet för start
	är minde än stopp i index-spannet som ska tilldelas värden.
	*/
	for(start; start <= stopp; start++){
		printf("array[%d]: %.2f\n", start, array[start]);
	}
	return 0;
}