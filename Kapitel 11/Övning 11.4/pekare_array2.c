#include <stdio.h>

/* 
�vning 11.4, Sida 250 
G�r om �vning 11.3 s� funktionen skriver ut f�lten bakl�nges!
*/

void SkrivUtFaltBak(int *a, int b);

int main(){
	int int_falt[] = {22,55,22,33,11,44,88,99,77,11,1,2,5,4};
	//antal element: sizeof hela f�ltet / sizeof ett element
	SkrivUtFaltBak(int_falt, sizeof int_falt/sizeof int_falt[0]);
}

void SkrivUtFaltBak(int *int_array, int antal_element){
	/*pekare s�tts till int_array+antal_element-1 (f�r pekare till f�lt b�rjar p� 0, likt array[index])
	forloopen k�rs s� l�nge pekare �r st�rre eller lika med int_array+0 (f�rsta v�rdet i arrayen) 
	pekare minskar med 1 f�r varje varv*/
	for(int *pekare = int_array+(antal_element-1);pekare>=int_array+0; pekare--){
		printf("%d\n", *pekare);
	}
}