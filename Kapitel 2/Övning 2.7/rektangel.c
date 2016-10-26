#include <stdio.h>

/* Övning 2.7, Sida 46

Skriv ett program som läser in en rektangels höjd och bredd.
Beräkna och skriv ut dess omkrets och area. */

int main (){
	float sid1, sid2;
	printf("Ange rektangels höjd: ");
	scanf("%f", &sid1);
	printf("Ange rektangels bredd: ");
	scanf("%f", &sid2);
	printf("\nRektangelns area är: %.3f, dess omkrets är %.3f", 
		sid1 * sid2, 
		2 * (sid1 + sid2));
	return 0;
}