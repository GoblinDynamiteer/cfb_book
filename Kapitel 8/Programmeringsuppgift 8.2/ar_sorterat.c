#include <stdio.h>
#define N 200

/*
Programmeringsuppgift 8.2, Sida 179

Skapa en funktion 'ar_sorterat'. Funktion ska undersöka om 
en array som anropas till funktionen är sorterad. 
Fubnktionen ska ha array av typen double och en int för antalet 
element, som parametrar.

Funktionen ska var av booleansk typ och returnera 1 om arrayen
är sorterad, annars 0.

Skriv ockå en funktion main som läser in ett antal heltal till en array 
och använder funktionen för att kontrollera om den är sorterad.



Funktionen ar_sorterat. Undersöker om en array är sorterad i storleksordnding
Elementet i jämförs med element i-1 (elementet innan i), så initialt jämförs
array[1] med array[0]. Både stigande och fallande nummersortering 
jämförs. Om båda variablerna sorteratFallande och sorteratStigande är noll
returnerar funktionen 0, annars 1 (arrayen är sorterad)
*/
_Bool ar_sorterat(double array[], int element){
	int sorteratStigande = 1;
	int sorteratFallande = 1;
	for(int i=1; i<element;i++){
		if(array[i-1]>array[i]){ 
			sorteratStigande = 0;
		}
		if(array[i-1]<array[i]){
			sorteratFallande = 0;
		}
	}
	//För test:
	if(sorteratFallande)	{printf("Arrayen är fallande!\n");}
	if(sorteratStigande)	{printf("Arrayen är stigande!\n");}
	//båda variablerna är 0, så returneras 1 (med ! i början inverteras uttrycket)
	return !(sorteratFallande == 0 && sorteratStigande==0); 
}
int main(){
	double a[N];
	int i = 0, raknare=0;
	while (1){
		printf("Slå in ett heltal: ");
		if (scanf("%lf", &a[raknare]) == EOF)
			break;
		raknare++;
	}
	if(ar_sorterat(a, raknare)){
		printf("Arrayen är sorterad!");
	}
	else 
		printf("Arrayen är inte sorterad!");
}