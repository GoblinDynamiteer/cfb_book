#include <stdio.h>
#include <stdlib.h> //f�r exit() -- avslutar programmet
#include <math.h> //f�r max(x), min(x)
/*
Programmeringsuppgift 4.7, Sida 91

In: antal domare, sv�righetsgrad, po�ng
Ut: ber�kna po�ngen f�r hopp

Kontrollera att antalet domare �r minst tre
hopp/domarpo�ng matas in tills anv�ndaren matar 
in end of file (ctrl+z) vid n�gon inl�sning


Simhoppt�vlingar: 
Minst 3 domare
Po�ng: 0-10
Ta bort h�gsta och l�gsta
Ta medelv�rde av resterande po�ng
Multiplicera medelv�rdet med 3, sedan med sv�righetsgradsfaktor.


Problematik: 
All sifferinmatning som inte har punkt ist�llet f�r kommatecken avslutar programmet
All icke-sifferinmatning (bokst�ver etc) avslutar programmet
*/

//definierar avsluta till att skriva ut en rad och avsluta programmet med exit(1);
#define avsluta {printf("EOF inmatat, avslutar program!");exit(1);} //verkar beh�vas vara p� en rad?

int main(){
int domare = 0, hopp=1; //Antal domare, samt hopp # (denna anv�nds enbart i utmatad text)
float svarighet; //sv�righetsgrad f�r hopp (sv�righetsgrad verkar ligga mellan 1.0 och 1.4 ish)
printf("---------------\nSimhoppt�vling!\n---------------\n");
printf("Programmet kan avbytas med EOF (Ctrl+Z) vid n�gon inmatning!\n\n");
while(domare<3){ //s� l�nge anv�ndaren matar in fel antal domare k�rs while-satsen, samt f�rsta g�ngen, d� domare = 0
	printf("Ange antal domare: ");
	if (scanf("%d", &domare) != 1) //if-sats som triggar i fall scanf inte returnerar 1 (0=ingen variabel inl�st)
		avsluta	//definieras innan int main
	if (domare < 3) //triggar om anv�ndaren skriver in fel antal domare
		printf("F�r n�gra domare!\n");
}
float poang[domare]; //array f�r h�llande av domarpo�ng, storlek till lika antal domare, egentligen har boken inte behandlat arrays �n
printf("Domarantal OK!\n");
while(1){ //while-sats kommer k�ras konstant, till anv�ndaren avslutar programmet vid en inmatning
	printf("\nHopp nr %d\nAnge sv�righetsgrad f�r hopp %d: ", hopp, hopp);
	if (scanf("%f", &svarighet) != 1) 
		avsluta
	printf("\nAnge po�ng!\nSka vara 0-10\n"); 
	for(int i=1;i<=domare;i++){ //for-sats som k�r lika m�nga varv som angivet antal domare
		printf("Hopp %d - Ange po�ng f�r domare %d: ", hopp, i);
		if (scanf("%f", &poang[i]) != 1) //po�ng s�tts till nummer i i array
			avsluta
		if ((poang[i] >10) || (poang[i] <0)){ //if-sats som triggar om anv�ndaren matar in felaktig po�ng (ej 0-10)
			while ((poang[i] > 10) || (poang[i] <0)){ //while-sats som k�r s� l�nge anv�ndaren matar in felaktig po�ng
				printf("Fel intmatning! (po�ng ska vara 0-10)\nHopp %d - Ange po�ng f�r domare %d: ", hopp, i);
				if (scanf("%f", &poang[i]) != 1) //po�ng s�tts till nummer i i array
					avsluta
			}
		}
	}
	float max =-1.0, min = 11.0; //variabler som ska h�lla max och min-v�rden fr�n po�ng-array, jag provade att inte initera dem, men d� funkade inte fmax/fmin jag ville
	float resultat = 0.0; //variabel f�r resultatet
	for(int i=1;i<=domare;i++){
		max = fmax(poang[i],max);	//tar reda p� den h�gsta po�ngen
		min = fmin(poang[i],min);	//tar reda p� den l�gsta po�ngen
		resultat += poang[i];  			//adderar all po�ng till variabeln resultat
	}
	resultat -= (max + min); //plockar bort de st�rsta och l�gsta po�ngen fr�n resultatet
	resultat /= (domare - 2); //medelv�rdet av domarnas resultat (minus tv� domare)
	resultat *= svarighet * 3;
	printf("\nResultat f�r hopp %d: %.2f\n", hopp, resultat);
	hopp++; //l�gger till 1 till hopp #, och k�r om while-satsen (nytt hopp)
}
return 0;
}