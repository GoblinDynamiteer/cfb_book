#include <stdio.h>
#include <math.h> //för pow(x,y)
/*
Övning 8.9, Sida 177

Skapa ett tvådimensionellt array med fyra rader och fem kolumner.
Elementen ska vara av typen double.

Initiera den tredje kolumnen så att den innehåller värdet 
1.0 på rad 1
0.1 på rad 2
0.01 på rad 3
0.001 på rad 4

anropa sedan funktionen kol_sum från sida 176 för att beräkna summan
i den tredje raden

Skriv ut resultatet

*/

//funktion från sida 176. Räknar ut summan av samtliga element i kolum k
double kol_sum(double f[][5], int antal_rader, int k){
	double sum = 0;
	for(int i = 0; i<antal_rader; i++){
		sum = sum + f[i][k];
	}
	return sum;
}

int main(){
	double array[4][5];
	/*
	sizeof array/sizeof array[0] ger antalet rader som arrayen innehåller.
	Jag är dock inte helt säker på att detta stämmer för en tvådimensionell
	array, men det verkar ge rätt resultat.
	Sizeof kan användas både för att ange hur många varv for-satsen som
	sätter värdena ska ha, samt att mata funktionen kol_sum.
	*/
	for(int i=0;i<sizeof array/sizeof array[0];i++){
		/*
		Värden i arrayen sätts till 1/10^i (10^0 = 1)
		Jag använder 3-1 för kolumn tre, jag tycker det känns lättare
		att förstå än att direkt skriva 2. (eftersom array börjar på 0)
		*/
		array[i][3-1] = 1 / pow(10,i);
	}
	//printf("test rader array: %d\n", sizeof array/sizeof array[0]);
	printf("Summan av elementen i kolumn 3 är: %.10f", kol_sum(array, sizeof array/sizeof array[0], 3-1));
	return 0;
}