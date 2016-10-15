#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> //för seed till rand
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.6, Sida 237

En textfil innehåller en lista med personer, endast ett namn per rad
Skriv ett program som slumpmässigt väljer ut en av personerna och
skriver ut dennes namn.

Tips: Räkna först raderna i filen, använd sedan standardfunktionen
rand (se sida 105) för att slumpa fram en rad. Skriv sedan ut raden

För att läsa om filen kan du använda freopen 

personer_namn.txt:
Ivar Zevulun
Quintina Rowntree
Yasser Porphyrios
Scottie Adebayo
Husein Viktor
Alexei Euphemios
Ram Mervin
Yash Ariel
Alexander Derrick
Raniero Spiro
Paula Georg
Josef Paulina
Elisabet Christoffer
Rong Addison
Gulzar Aeron
Kyo Khurshid
Hayden Head
Qiu Chen
Ron Jeremy
Peter North
Gili Issy
Vic Jocelyn
Rene Chifuniro

23 rader
*/

int main(){
	FILE *personfil = fopen("personer_namn.txt", "r");
	char s[N];
	int rader = 0, k;
	while(textfilTillString(s, N, personfil)){
		rader++;
		//printf("Rad: %2d - Namn: %s\n",rader, s);
	}
	freopen("personer_namn.txt", "r", personfil);
	srand(time(NULL));
	k = rand() % rader;
	//printf("Filen innhåller %d st rader (ska vara 23?)", rader);
	rader = 0;
	while(textfilTillString(s, N, personfil)){
		rader++;
		if(k==rader){
			printf("Slumpad person: %s (rad %d)", s, k);
		}
	}
	return 0;
}



