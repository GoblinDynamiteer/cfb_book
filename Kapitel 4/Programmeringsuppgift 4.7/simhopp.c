#include <stdio.h>
#include <stdlib.h> //för exit() -- avslutar programmet
#include <math.h> //för max(x), min(x)
/*
Programmeringsuppgift 4.7, Sida 91

In: antal domare, svårighetsgrad, poäng
Ut: beräkna poängen för hopp

Kontrollera att antalet domare är minst tre
hopp/domarpoäng matas in tills användaren matar 
in end of file (ctrl+z) vid någon inläsning


Simhopptävlingar: 
Minst 3 domare
Poäng: 0-10
Ta bort högsta och lägsta
Ta medelvärde av resterande poäng
Multiplicera medelvärdet med 3, sedan med svårighetsgradsfaktor.


Problematik: 
All sifferinmatning som inte har punkt istället för kommatecken avslutar programmet
All icke-sifferinmatning (bokstäver etc) avslutar programmet
*/

//definierar avsluta till att skriva ut en rad och avsluta programmet med exit(1);
#define avsluta {printf("EOF inmatat, avslutar program!");exit(1);} //verkar behövas vara på en rad?

int main(){
int domare = 0, hopp=1; //Antal domare, samt hopp # (denna används enbart i utmatad text)
float svarighet; //svårighetsgrad för hopp (svårighetsgrad verkar ligga mellan 1.0 och 1.4 ish)
printf("---------------\nSimhopptävling!\n---------------\n");
printf("Programmet kan avbytas med EOF (Ctrl+Z) vid någon inmatning!\n\n");
while(domare<3){ //så länge användaren matar in fel antal domare körs while-satsen, samt första gången, då domare = 0
	printf("Ange antal domare: ");
	if (scanf("%d", &domare) != 1) //if-sats som triggar i fall scanf inte returnerar 1 (0=ingen variabel inläst)
		avsluta	//definieras innan int main
	if (domare < 3) //triggar om användaren skriver in fel antal domare
		printf("För några domare!\n");
}
float poang[domare]; //array för hållande av domarpoäng, storlek till lika antal domare, egentligen har boken inte behandlat arrays än
printf("Domarantal OK!\n");
while(1){ //while-sats kommer köras konstant, till användaren avslutar programmet vid en inmatning
	printf("\nHopp nr %d\nAnge svårighetsgrad för hopp %d: ", hopp, hopp);
	if (scanf("%f", &svarighet) != 1) 
		avsluta
	printf("\nAnge poäng!\nSka vara 0-10\n"); 
	for(int i=1;i<=domare;i++){ //for-sats som kör lika många varv som angivet antal domare
		printf("Hopp %d - Ange poäng för domare %d: ", hopp, i);
		if (scanf("%f", &poang[i]) != 1) //poäng sätts till nummer i i array
			avsluta
		if ((poang[i] >10) || (poang[i] <0)){ //if-sats som triggar om användaren matar in felaktig poäng (ej 0-10)
			while ((poang[i] > 10) || (poang[i] <0)){ //while-sats som kör så länge användaren matar in felaktig poäng
				printf("Fel intmatning! (poäng ska vara 0-10)\nHopp %d - Ange poäng för domare %d: ", hopp, i);
				if (scanf("%f", &poang[i]) != 1) //poäng sätts till nummer i i array
					avsluta
			}
		}
	}
	float max =-1.0, min = 11.0; //variabler som ska hålla max och min-värden från poäng-array, jag provade att inte initera dem, men då funkade inte fmax/fmin jag ville
	float resultat = 0.0; //variabel för resultatet
	for(int i=1;i<=domare;i++){
		max = fmax(poang[i],max);	//tar reda på den högsta poängen
		min = fmin(poang[i],min);	//tar reda på den lägsta poängen
		resultat += poang[i];  			//adderar all poäng till variabeln resultat
	}
	resultat -= (max + min); //plockar bort de största och lägsta poängen från resultatet
	resultat /= (domare - 2); //medelvärdet av domarnas resultat (minus två domare)
	resultat *= svarighet * 3;
	printf("\nResultat för hopp %d: %.2f\n", hopp, resultat);
	hopp++; //lägger till 1 till hopp #, och kör om while-satsen (nytt hopp)
}
return 0;
}