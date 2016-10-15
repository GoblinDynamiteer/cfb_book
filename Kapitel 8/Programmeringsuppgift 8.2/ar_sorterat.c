#include <stdio.h>
#define N 200

/*
Programmeringsuppgift 8.2, Sida 179

Skapa en funktion 'ar_sorterat'. Funktion ska unders�ka om 
en array som anropas till funktionen �r sorterad. 
Fubnktionen ska ha array av typen double och en int f�r antalet 
element, som parametrar.

Funktionen ska var av booleansk typ och returnera 1 om arrayen
�r sorterad, annars 0.

Skriv ock� en funktion main som l�ser in ett antal heltal till en array 
och anv�nder funktionen f�r att kontrollera om den �r sorterad.



Funktionen ar_sorterat. Unders�ker om en array �r sorterad i storleksordnding
Elementet i j�mf�rs med element i-1 (elementet innan i), s� initialt j�mf�rs
array[1] med array[0]. B�de stigande och fallande nummersortering 
j�mf�rs. Om b�da variablerna sorteratFallande och sorteratStigande �r noll
returnerar funktionen 0, annars 1 (arrayen �r sorterad)
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
	//F�r test:
	if(sorteratFallande)	{printf("Arrayen �r fallande!\n");}
	if(sorteratStigande)	{printf("Arrayen �r stigande!\n");}
	//b�da variablerna �r 0, s� returneras 1 (med ! i b�rjan inverteras uttrycket)
	return !(sorteratFallande == 0 && sorteratStigande==0); 
}
int main(){
	double a[N];
	int i = 0, raknare=0;
	while (1){
		printf("Sl� in ett heltal: ");
		if (scanf("%lf", &a[raknare]) == EOF)
			break;
		raknare++;
	}
	if(ar_sorterat(a, raknare)){
		printf("Arrayen �r sorterad!");
	}
	else 
		printf("Arrayen �r inte sorterad!");
}