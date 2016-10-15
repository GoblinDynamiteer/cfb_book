#include <stdio.h>

/* 
Övning 11.4, Sida 250 
Gör om övning 11.3 så funktionen skriver ut fälten baklänges!
*/

void SkrivUtFaltBak(int *a, int b);

int main(){
	int int_falt[] = {22,55,22,33,11,44,88,99,77,11,1,2,5,4};
	//antal element: sizeof hela fältet / sizeof ett element
	SkrivUtFaltBak(int_falt, sizeof int_falt/sizeof int_falt[0]);
}

void SkrivUtFaltBak(int *int_array, int antal_element){
	/*pekare sätts till int_array+antal_element-1 (för pekare till fält börjar på 0, likt array[index])
	forloopen körs så länge pekare är större eller lika med int_array+0 (första värdet i arrayen) 
	pekare minskar med 1 för varje varv*/
	for(int *pekare = int_array+(antal_element-1);pekare>=int_array+0; pekare--){
		printf("%d\n", *pekare);
	}
}