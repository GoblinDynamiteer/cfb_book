#include <stdio.h>

/*
�vning 8.3, Sida 155
G�r om f�reg�ende �vning
Skapa ett f�lt med tio element, typ double.
Anv�nd en for-sats f�r att ge f�lten v�rdet 1 osv

Sist ska v�rdena skrivas ut!

*/

int main(){
	double delar[10];
	int delning = 10;
	for(int i=0;i<sizeof delar/sizeof delar[0];i++){
		delar[i] = 1.0/delning;
		delning--;
	}
	printf("Delar:\n");
	for(int i=0;i<sizeof delar/sizeof delar[0];i++){
		printf("%.3f\t", delar[i]);
	}
}
