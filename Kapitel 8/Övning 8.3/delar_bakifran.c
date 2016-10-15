#include <stdio.h>

/*
Övning 8.3, Sida 155
Gör om föregående övning
Skapa ett fält med tio element, typ double.
Använd en for-sats för att ge fälten värdet 1 osv

Sist ska värdena skrivas ut!

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
