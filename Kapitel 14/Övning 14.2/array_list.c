//Filen är hämtad från http://skansholm.com/CFranBorjan/funktioner/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"
#include "libtxt.h"

#define CAPACITY 100
struct array_list {
  void *a[CAPACITY];
  int n;
};

struct array_list *new_list(void) {
  struct array_list *l = malloc(sizeof (struct array_list));
  l->n = 0;
  return l;
}

void *get_elem(struct array_list *l, int index) {
  if (index >= 0 && index < l->n){
	printf("["FORM_MAGENTA"Returnerar pekare på element %d"FORM_END"]\n", index);
    return l->a[index];
  }
  else
    return NULL;
}

int size(struct array_list *l) {
  return l->n;
}

_Bool add_last(struct array_list *l, void *new_data) {
  if (l->n < CAPACITY) {
    l->a[l->n++] = new_data;
	printf("["FORM_MAGENTA"Lade till pekare på plats %d"FORM_END"]\n", (l->n)-1);
    return 1;
  }
  else
    return 0;
}

/* Övning 14.2, Sida 348
Lägg till i modulen 'array_list': en funktion 'remove_last', som tar bort det sista elementet. 
Funktionen ska returnera en pekare till det borttagna elementet om det gick bra, annars NULL. */

void *remove_last(struct array_list *l){
	if(l->n == 0){ //Om arrayens n är 0, n håller värde för antal element i arrayen
		printf("["FORM_MAGENTA"Return NULL"FORM_END"]\n");
		return NULL;
	}
	else {
		printf("["FORM_MAGENTA"Tog bort pekare på index %d"FORM_END"]\n", (l->n)-1);
		l->n--; /*minska n med 1, "plockar bort" sista element. Pekaren finns kvar, 
		men platsen kommer skrivas över om ny inmatning görs */
		return l->a[l->n];
	}
}

