/*
�vning 7.3, Sida 137

Studera f�ljande program:
*/

#include <stdio.h>
double x = 1.5;

double f(double x){
	return x;
}

int main(){
	double y = 3.0;
	if (y>0){
		double y = 0.0;
	}
	printf("%f", f(y));
}

/*
Vilken utskrift ger programmet?  -- SVAR: 3.000000
F�rklara varf�r! -- SVAR: 

if (y>0){
		double y = 0.0; <<<--- 	Variabeln deklareras innanf�r if-satsens {}, 
											och syns enbart d�r, f�r att fungera skulle det st� y = 0;


vad h�nder om man byter namn p� den
f�rsta deklarationen av variabeln y i main? -- SVAR:

OM 
double y = 3.0; >>>>>  double a = 3.0;
Kompilatorn ger felmeddelande
" error: 'y' undeclared (first use in this function) "
n�r den kommer till if-satsen, som f�rs�ker anv�nda y
*/
