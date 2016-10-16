#include <stdio.h>
#include <string.h>
#include "bil.h" //Deklaration av struct bil

/* �vning 12.8, Sida 309

G�r om programmet med bil-structarna. 
Skapa tv� program, ett som skriver structen till en fil, och en som l�ser structen
fr�n filen och skriver ut inneh�llet p� sk�rmen.

*/

int main(){
	//filvariabel med append (l�gg till) och bin�rt mode, f�r skrivning av structar
	FILE *bilfil = fopen("bil_data.dat", "ab");
	//array med tre bilar:
	struct bil bil_info[3] = {
		{"SZS361", "Polaris BIG Boss 6X6", 2002, 420, 23000},
		{"SZS351", "Volvo V70", 2001, 1610, 103000},
		{"ABC351", "Volvo XC 90", 2010, 2110, 163000}
	};
	//argument (pekare till struct, elementstorlek, antal element, data-fil)
	for(int i = 0;  i<3;i++){
		fwrite(&bil_info[i], sizeof(struct bil), 1, bilfil);
	}
	return 0;
}
