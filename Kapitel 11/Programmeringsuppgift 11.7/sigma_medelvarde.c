#include <stdio.h>
#include <math.h> //f�r pow(x,y)

/* Programmeringsuppgift 11.7, Sida 277

Skriv en funktion som ber�knar standardavvikelse (tecken sigma) och 
medelv�rde f�r en array med element av typen double.

Parametrar till funktionen �r arrayen, antal element (och adresser medelv�rde och sigma)

R�kna:
Medelv�rde �r summan av elementen dividerat med antal element.

sigma: 
	R�kna f�rst SUMMAN av varje element I KVADRAT (upph�jt med 2)
	summa_kvadrat = summa_kvadrat + element * element;
	
	Ber�kna MEDELV�RDET av SUMMAN AV ALLA TAL I KVADRAT
	summa = summa + element;
	medelv�rde(f�r sigma) = element * element / (antal element)
	
	y = summa_kvadrat - medelv�rde(f�r sigma) / (antal element - 1)
	sigma = roten ur y

exempel
array:
13.4,15.2,14.21,8.2,10.2,17.5,14.2,13.2,13.9,15.2,11.9,7.3,6.9

mv:
12.41

sigma:
3.31 */

void sigma_mv(double *array, int antal_element, double *medelvarde, double *sigma){
	double summa_kvadrat = 0.0, summa = 0.0;
	for(double *tal = array;tal<array+antal_element;tal++){
		summa_kvadrat += pow(*tal, 2);
		summa += *tal;
		//printf("+");
	}
	//Ber�kningar enligt ovan:
	double medelvarde_kvad = pow(summa,2) / antal_element;
	//printf("Funktion: medelvarde_kvad: %lf\n", medelvarde_kvad);
	//printf("Funktion: summa_kvadrat: %lf\n", summa_kvadrat);
	*sigma = sqrt((summa_kvadrat - medelvarde_kvad) / (antal_element-1)); //OBS paranteser!
	*medelvarde = summa/antal_element;
	//printf("Funktion: summa_kvadrat: %lf\n", summa_kvadrat);
	//printf("Funktion: summa: %lf\n", summa);
}

int main(){
	double array_test[] = {13.4,15.2,14.21,8.2,10.2,17.5,14.2,13.2,13.9,15.2,11.9,7.3,6.9}, mv, sigma;
	int n = sizeof array_test / sizeof(double);
	//printf("Antal element: %d", n);
	/*	& framf�r variabeln betyder att man skickar addressen till funktionen, i st�llet f�r v�rdet 
	funktionen har som parametrar pekare f�r medelv�rde och sigma
	Detta inneb�r att funktionen kommer kundda s�tta/�ndra v�rdena i mv och sigma
	utan att ha dem deklarerade s� att de �r synliga f�r funktionen */
	sigma_mv(array_test, n, &mv, &sigma);
	printf("Medelv�rde: %.2f, standardavvikelse: %.2f", mv, sigma);
	return 0;
}