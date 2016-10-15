#include <stdio.h>

/*
�vning 8.5, Sid 160

Skapa tv� int f�lt a & b:

a[100] = 0,1,2,3 ... osv
b[20] = alla element 0

Kopiera f�lt med index 50-54 fr�n a till 10-14 i b
Kopiera f�lt med index 95-99 fr�n a till 5-9 i b

Anv�nd for-satser f�r att initiera och kopiera element!

Anv�nd till sist en forsats f�r att skriva ut hela f�ltet b

*/


int main(){
	int a[100], b[20];
	/*
	sizeof x/sizeof x[0] ger antalet element i f�lt x
	forsatserna k�rs s� l�nge i �r mindre �n f�ltens
	antal element. Notera att f�ltens elementindex 
	b�rjar p� noll s� f�ltet a �r a[0] - a[99]
	D�rf�r s�tter jag k�rvillkoren till i<x ist�llet
	f�r i<=x.
	*/
	for (int i=0;i<sizeof a/sizeof a[0];i++){
		a[i] = i;
	}
	for (int i=0;i<sizeof b/sizeof b[0];i++){
		b[i] = 0;
	}
	/*
	Dessa for-satser g�r fixa p� m�nga olika
	s�tt. Jag tycker denna l�sning �r ganska
	enkel att f�rst�. N�r i b�rjar p� 0 blir f�rsta
	varvet 
	b[i+10] = a[i+50] == b[0+10] = a[0+50] 
	osv.
	*/
	for (int i=0;i+50<=54;i++){
		b[i+10] = a[i+50];
	}
	for (int i=0;i+95<=99;i++){
		b[i+5] = a[i+95];
	}
	printf("Element i f�ltet b:\n");
	//Likadan for-sats som anv�ndes f�r att s�tta elementen i b
	for (int i=0;i<sizeof b/sizeof b[0];i++){
		printf("b[%d]: %d \n", i, b[i]);
	}
}