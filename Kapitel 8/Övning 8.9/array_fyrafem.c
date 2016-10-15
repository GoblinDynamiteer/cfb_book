#include <stdio.h>
#include <math.h> //f�r pow(x,y)
/*
�vning 8.9, Sida 177

Skapa ett tv�dimensionellt array med fyra rader och fem kolumner.
Elementen ska vara av typen double.

Initiera den tredje kolumnen s� att den inneh�ller v�rdet 
1.0 p� rad 1
0.1 p� rad 2
0.01 p� rad 3
0.001 p� rad 4

anropa sedan funktionen kol_sum fr�n sida 176 f�r att ber�kna summan
i den tredje raden

Skriv ut resultatet

*/

//funktion fr�n sida 176. R�knar ut summan av samtliga element i kolum k
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
	sizeof array/sizeof array[0] ger antalet rader som arrayen inneh�ller.
	Jag �r dock inte helt s�ker p� att detta st�mmer f�r en tv�dimensionell
	array, men det verkar ge r�tt resultat.
	Sizeof kan anv�ndas b�de f�r att ange hur m�nga varv for-satsen som
	s�tter v�rdena ska ha, samt att mata funktionen kol_sum.
	*/
	for(int i=0;i<sizeof array/sizeof array[0];i++){
		/*
		V�rden i arrayen s�tts till 1/10^i (10^0 = 1)
		Jag anv�nder 3-1 f�r kolumn tre, jag tycker det k�nns l�ttare
		att f�rst� �n att direkt skriva 2. (eftersom array b�rjar p� 0)
		*/
		array[i][3-1] = 1 / pow(10,i);
	}
	//printf("test rader array: %d\n", sizeof array/sizeof array[0]);
	printf("Summan av elementen i kolumn 3 �r: %.10f", kol_sum(array, sizeof array/sizeof array[0], 3-1));
	return 0;
}