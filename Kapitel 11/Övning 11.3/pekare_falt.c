#include <stdio.h>

/* Övning 11.3, Sida 250

Konstruera en funktion som skriver ut alla elementen i ett heltalsfält
Som parametrar får funktionen en pekare till fältet, och ett heltal som
anger antalet element i fältet.

Använd pekararitmetik inne i funktionen. */

void SkrivUtFalt(int *a, int b);

int main(){
	int int_falt[] = {55,55,22,33,11,44,88,99,77,11,1,2,5,4};
	//antal element: sizeof hela fältet / sizeof ett element
	SkrivUtFalt(int_falt, sizeof int_falt/sizeof int_falt[0]);
}

void SkrivUtFalt(int *int_array, int antal_element){
	/*ny pekare initieras i for-satsen, sätts till parametern int_array (blir automatiskt till första värdet i arrayen) 
	Går också använda *pekare = &int_array[0].
	Satsen körs till pekare är 1 under int_array+antal_element (pekare börjar likt array-indexering på 0)
	*/
	for(int *pekare = int_array;pekare<int_array+antal_element; pekare++){
		printf("%d\n", *pekare);
	}
}


/* 
Författarens:
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