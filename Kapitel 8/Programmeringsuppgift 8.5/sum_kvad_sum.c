#include <stdio.h>
#include <math.h> //för pow(x,y)
/*
Programmeringsuppgift 8.5, Sida 179

Skapa två funktioner:
sum
kvad_sum

båda ska som första parameter få en array av typen double
och andra parameter antalet element i arrayen.

funktionen sum ska returnera summan av alla element
funktionen kvad_sum ska returnera summan av alla element i kvadrat 

ex:
2,5^2+1,5^2+3,0^2 = 17,5

*/

//funktion som summerar och retunerar värdet av alla element i en array
double sum(double a[], int antal){
	double summa = 0;
	for(int i=0;i<antal;i++){
		summa += a[i];
	}
	return summa;
}

//funktion som summerar och retunerar värdet av alla element i kvadrat, för en array
double kvad_sum(double a[], int antal){
	double summa = 0;
	for(int i=0;i<antal;i++){
		summa += pow(a[i],2);
	}
	return summa;
}

int main(){
	double array[] = {2.5, 1.5, 3.0, 6.2, 3.1}; //array med testvärden
	printf("sum:\t\t%f\n", sum(array, sizeof array/sizeof array[0]));
	printf("kvadsum:\t%f", kvad_sum(array, sizeof array/sizeof array[0]));
	return 0;
}
























