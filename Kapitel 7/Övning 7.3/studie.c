/*
Övning 7.3, Sida 137

Studera följande program:
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
Förklara varför! -- SVAR: 

if (y>0){
		double y = 0.0; <<<--- 	Variabeln deklareras innanför if-satsens {}, 
											och syns enbart där, för att fungera skulle det stå y = 0;


vad händer om man byter namn på den
första deklarationen av variabeln y i main? -- SVAR:

OM 
double y = 3.0; >>>>>  double a = 3.0;
Kompilatorn ger felmeddelande
" error: 'y' undeclared (first use in this function) "
när den kommer till if-satsen, som försöker använda y
*/
