#include <stdio.h>

/* �vning 11.3, Sida 250

Konstruera en funktion som skriver ut alla elementen i ett heltalsf�lt
Som parametrar f�r funktionen en pekare till f�ltet, och ett heltal som
anger antalet element i f�ltet.

Anv�nd pekararitmetik inne i funktionen. */

void SkrivUtFalt(int *a, int b);

int main(){
	int int_falt[] = {55,55,22,33,11,44,88,99,77,11,1,2,5,4};
	//antal element: sizeof hela f�ltet / sizeof ett element
	SkrivUtFalt(int_falt, sizeof int_falt/sizeof int_falt[0]);
}

void SkrivUtFalt(int *int_array, int antal_element){
	/*ny pekare initieras i for-satsen, s�tts till parametern int_array (blir automatiskt till f�rsta v�rdet i arrayen) 
	G�r ocks� anv�nda *pekare = &int_array[0].
	Satsen k�rs till pekare �r 1 under int_array+antal_element (pekare b�rjar likt array-indexering p� 0)
	*/
	for(int *pekare = int_array;pekare<int_array+antal_element; pekare++){
		printf("%d\n", *pekare);
	}
}


/* 
F�rfattarens:
#include <stdio.h>

void skriv_ut(int *a, int n) {
  for (int *p=a; p<a+n; p++)
    printf("%d  ", *p);
}

// Testprogram, ingick inte i uppgiften
int main() {
int f[5] = {1,2,3,4,5};
skriv_ut(f, 5);
}
 */