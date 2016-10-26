#include <stdio.h>
#include <math.h>
#include "list.h" //från http://skansholm.com/CFranBorjan/funktioner/
#include "libtxt.h"

/* Övning 14.1, Sida 346
Skriv ett program som läser in ett godtyckligt antal tal. 
Avsluta inläsning med EOF. 
Programmet ska lägga de inlästa talen i en lista. 
När inläsningen avslutats ska programmet löpa igenom listan och undersöka vilket av talen som är störst. 
Detta tal och dess index ska skrivas ut. 

Använd list.h och list.c från bokens hemsida. */

int main(){
	double tal, *talp;
	struct list *lista = new_list(); //list.c - new_list - skapar en ny lista.
	system("cls");
	printf("Skriv in värde: ");
	while((scanf("%lf", &tal) == 1  )){
		talp = malloc(sizeof(double));
		*talp = tal;
		add_last(lista, talp); //list.c - add_last - lägger till värde sist i lista.
		printf("Skriv in värde (avsluta med ctrl+z): ");
	}
	printf(ADD_LINE"Antal element i listan:"FORM_GREEN"%d"FORM_END"\n", size(lista));
	talp = get(lista, 0);
	double max = *talp; //Max sätts till första värdet i listan
	int index = 0; //Indexx sätts till första index i listan
	printf(ADD_LINE"Värden:\n");
	for(int i=0; i<size(lista);i++){ //list.c - size - anger antal element i lista.
		talp = get(lista, i); //list.c - get - hämtar pekare till element för index i
		if(max < *talp){
			max = *talp;
			index = i;
		}
		printf("%.2f\n", *talp);
	}
	printf(ADD_LINE"Max: "FORM_CYAN"%.2f"FORM_END" på index "FORM_GREEN"%d"FORM_END, max, index);
	return 0;
}

/* 
Författarens: 
http://skansholm.com/CFranBorjan/ovningar/Kap14/ovn14-1.c

int main() {
  struct list *l = new_list();
  double tal, *p;
  while ((scanf("%lf", &tal) == 1)) {
    p = malloc(sizeof (double));
    *p = tal;
    add_last(l, p);
  }
  p = get(l, 0);        // avläs det första elementet
  double max = *p;      // största talet hittills
  int imax = 0;         // index för största talet
  // Undersök resten av elementen
  for (int i = 1; i < size(l); i++) {
	p = get(l, i);
    if (*p > max) {
	  max = *p;
      imax = i;
	}
  }
  printf("Största tal: %f\nIndex: %d", max, imax);
} 
*/