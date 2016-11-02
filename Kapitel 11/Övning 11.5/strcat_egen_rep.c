#include <stdio.h>

/* �vning 11.5, Sida 254 - repetition

Bygg en egen version av strcat (se sida 203)

Tips: B�rja med att ta fram en pekare till nolltecknet i slutet p� den text du skall kopiera till
Kopiera sedan till detta st�lle som strcpy (Sida 254)

strcat l�gger en textrad i slutet p� en annan, text ska f� text+tillagg
 */

void strcat_egen(char *a, const char *b);
void strcat_skan(char *till, const char *fran);
 
int main(){
	char a[10] = "Kalle";
	printf("Innan funktion: %s", a);
	strcat_egen(a, " Anka");
	printf("\nEfter funktion: %s", a);
	return 0;
}

void strcat_egen(char *a, const char *b){
	while(*a){
		a++;
	}
	while(*b){
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
}
