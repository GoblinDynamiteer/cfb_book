#include <stdio.h>
#include <math.h>
#include "list.h" //fr�n http://skansholm.com/CFranBorjan/funktioner/
#include "libtxt.h"

/* �vning 14.1, Sida 346
Skriv ett program som l�ser in ett godtyckligt antal tal. 
Avsluta inl�sning med EOF. 
Programmet ska l�gga de inl�sta talen i en lista. 
N�r inl�sningen avslutats ska programmet l�pa igenom listan och unders�ka vilket av talen som �r st�rst. 
Detta tal och dess index ska skrivas ut. 

Anv�nd list.h och list.c fr�n bokens hemsida. */

int main(){
	double tal, *talp;
	struct list *lista = new_list(); //list.c - new_list - skapar en ny lista.
	system("cls");
	printf("Skriv in v�rde: ");
	while((scanf("%lf", &tal) == 1  )){
		talp = malloc(sizeof(double));
		*talp = tal;
		add_last(lista, talp); //list.c - add_last - l�gger till v�rde sist i lista.
		printf("Skriv in v�rde (avsluta med ctrl+z): ");
	}
	printf(ADD_LINE"Antal element i listan:"FORM_GREEN"%d"FORM_END"\n", size(lista));
	talp = get(lista, 0);
	double max = *talp; //Max s�tts till f�rsta v�rdet i listan
	int index = 0; //Indexx s�tts till f�rsta index i listan
	printf(ADD_LINE"V�rden:\n");
	for(int i=0; i<size(lista);i++){ //list.c - size - anger antal element i lista.
		talp = get(lista, i); //list.c - get - h�mtar pekare till element f�r index i
		if(max < *talp){
			max = *talp;
			index = i;
		}
		printf("%.2f\n", *talp);
	}
	printf(ADD_LINE"Max: "FORM_CYAN"%.2f"FORM_END" p� index "FORM_GREEN"%d"FORM_END, max, index);
	return 0;
}

/* 
F�rfattarens: 
http://skansholm.com/CFranBorjan/ovningar/Kap14/ovn14-1.c

int main() {
  struct list *l = new_list();
  double tal, *p;
  while ((scanf("%lf", &tal) == 1)) {
    p = malloc(sizeof (double));
    *p = tal;
    add_last(l, p);
  }
  p = get(l, 0);        // avl�s det f�rsta elementet
  double max = *p;      // st�rsta talet hittills
  int imax = 0;         // index f�r st�rsta talet
  // Unders�k resten av elementen
  for (int i = 1; i < size(l); i++) {
	p = get(l, i);
    if (*p > max) {
	  max = *p;
      imax = i;
	}
  }
  printf("St�rsta tal: %f\nIndex: %d", max, imax);
} 
*/