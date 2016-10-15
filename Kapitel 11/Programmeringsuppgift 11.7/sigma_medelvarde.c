#include <stdio.h>
#include <math.h> //för pow(x,y)

/* Programmeringsuppgift 11.7, Sida 277

Skriv en funktion som beräknar standardavvikelse (tecken sigma) och 
medelvärde för en array med element av typen double.

Parametrar till funktionen är arrayen, antal element (och adresser medelvärde och sigma)

Räkna:
Medelvärde är summan av elementen dividerat med antal element.

sigma: 
	Räkna först SUMMAN av varje element I KVADRAT (upphöjt med 2)
	summa_kvadrat = summa_kvadrat + element * element;
	
	Beräkna MEDELVÄRDET av SUMMAN AV ALLA TAL I KVADRAT
	summa = summa + element;
	medelvärde(för sigma) = element * element / (antal element)
	
	y = summa_kvadrat - medelvärde(för sigma) / (antal element - 1)
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
	//Beräkningar enligt ovan:
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
	/*	& framför variabeln betyder att man skickar addressen till funktionen, i stället för värdet 
	funktionen har som parametrar pekare för medelvärde och sigma
	Detta innebär att funktionen kommer kundda sätta/ändra värdena i mv och sigma
	utan att ha dem deklarerade så att de är synliga för funktionen */
	sigma_mv(array_test, n, &mv, &sigma);
	printf("Medelvärde: %.2f, standardavvikelse: %.2f", mv, sigma);
	return 0;
}