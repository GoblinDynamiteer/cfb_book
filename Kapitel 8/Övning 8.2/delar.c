#include <stdio.h>

/*
�vning 8.2, Sida 155
Skapa ett f�lt med tio element, typ double.
Anv�nd en for-sats f�r att ge f�lten v�rdet 1/1, 1/2, 1/3 osv

Sist ska v�rdena skrivas ut!

*/

int main(){
	double delar[10];
	for(int i=0;i<sizeof delar/sizeof delar[0];i++){
		delar[i] = 1.0/(i+1);
	}
	printf("Delar:\n");
	for(int i=0;i<sizeof delar/sizeof delar[0];i++){
		printf("%.3f\t", delar[i]);
	}
}