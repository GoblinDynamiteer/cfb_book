#include <stdio.h>

/* �vning 2.7, Sida 46

Skriv ett program som l�ser in en rektangels h�jd och bredd.
Ber�kna och skriv ut dess omkrets och area. */

int main (){
	float sid1, sid2;
	printf("Ange rektangels h�jd: ");
	scanf("%f", &sid1);
	printf("Ange rektangels bredd: ");
	scanf("%f", &sid2);
	printf("\nRektangelns area �r: %.3f, dess omkrets �r %.3f", 
		sid1 * sid2, 
		2 * (sid1 + sid2));
	return 0;
}