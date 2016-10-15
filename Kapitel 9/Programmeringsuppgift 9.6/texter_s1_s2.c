#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 9.6, Sida 215

Skriv en funktion som f�r tv� texter, 's1' & 's2', samt ett heltal 'n'
Funktionen ska kopiera texten fr�n s2 till s1, men texten som l�ggs
i s1 ska alltid ha l�ngden n. OM texten i s2 �r l�ngre �n n s� skall
resultatet inneh�lla de sista n tecknen i s2. annars ska resultatet
inneh�lla texten i s2 'h�gerjusterad'.
Man skall allts� fylla ut med ett l�mpligt antal blanka tecken till v�nster */

void texter(char *s1, char *s2, int n){
	int i, j=0;
	//om s2 �r kortare �n n s�tts i till 0, annars till l�ngd av s2 - n
	i = (strlen(s2)<n) ? 0 : strlen(s2)-n ;
	//om n �r l�ngre �n s2, s�tts mellanslag till s1, tills j �r st�rre �n l�ngd av s2 - n
	if(n>strlen(s2)){
		while(j<n-strlen(s2)){
		s1[j++] = ' '; //OBS enkla citationstecken f�r skrivning av enskilt tecken
		}	
	}
	/*
	text skrivs fr�n s2 till s1, medans ett nolltecken inte hittas i s2
	j b�rjar p� en h�gre siffra �n i, om mellanslag har satts i s1, enl ovan
	*/
	while(s2[i]!='\0'){
		s1[j++] = s2[i++];
	}
	s1[j] = '\0';
}

int main(){
	char s1[100]; 
	//char s2[100] = "l�ng textremsa att kopiera fr�n s2 till s1, endast slutet ska synas om l�ngre �n n";
	char s2[100] = "kort text <n - h�gerjustera!";
	int n = 10;
	//printf("n: %d, s1: %s, s2: %s",n,s1,s2);
	texter(s1,s2,n);
	printf("\nEfter funktion:\nn: %d\ns1: %s\ns2: %s",n,s1,s2);
	printf("\nstrlen(s1): %d",strlen(s1));
}