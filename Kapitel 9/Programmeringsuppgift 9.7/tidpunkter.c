#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 9.7, Sida 215

Skriv ett program som l�ser in tv� tidpunkter med formen tt.mm
Programmet ska visa hur m�nga minuter det �r mellan de tv�
tidpunkterna.

Tips: R�kna om de b�da tiderna till antal minuter som g�tt sedan
det aktuella dygnets start, och g�r en justering om den senare tidpunkten
infaller under det f�ljande dygnet. */

//En eventuell "raggarl�sning" med on�digt m�nga variabler f�r h�llare och konvertering
int main(){
	char tid1[7] = "09:35", tid2[7] = "01:30";
	char h1[3], h2[3];
	char m1[3], m2[3];
	int timme1,minut1,timme2,minut2, totaltminuter1, totaltminuter2;
	printf("Ange tidpunkt 1 (hh:mm): ");
	//fgets(tid1, 7, stdin);
	/*
	Jag f�r inte fgets att fungera n�r tv� variabler ska s�tta, scanf fungerar s� l�nge man inte ska sl� in mellanslag
	*/
	scanf("%s", tid1);
	printf("Ange tidpunkt 2 (hh:mm): ");
	//fgets(tid2, 7, stdin);
	scanf("%s", tid2);
	int i=0, j=0;
	//(xx:yy) - xx/yy i tid1 och tid2 s�tts till h1=xx h2=xx m1=yy m2=yy
	for(;i<2;){
		h1[i] =tid1[i];
		h2[i] =tid2[i];
		m1[i] =tid1[i+3];
		m2[i] =tid2[i+3];
		i++;
	}
	//nolltecken s�tts i slutet av str�ngarna f�r h1,h2,m1,m2
	h1[i] = '\0';
	h2[i] = '\0';
	m1[i] = '\0';
	m2[i] = '\0';
	/*str�ngarna h1,h2,m1,m2 l�ses in som %d till int-variablerna timme1, timme2, minut1, minut2
	sscanf fungerar som scanf, fast f�r input fr�n str�ng ist�llet f�r anv�ndare, f�rsta argumentet �r
	textstr�ngen sscanf(str�ng, "formattering", &tillvariabel);
	*/
	sscanf(h1, "%d", &timme1);
	sscanf(h2, "%d", &timme2);
	sscanf(m1, "%d", &minut1);
	sscanf(m2, "%d", &minut2);
	//Ber�knar minuter fr�n 0 (dagens start)
	totaltminuter1 = timme1*60 + minut1;
	totaltminuter2 = timme2*60 + minut2;
	/*
	om antal minuter fr�n 0 �r st�rre f�r den andra inmatade tidpunkten, inneb�r det att det ligger i dagen efter 
	i s� fall adderas en heldags minuter till summan 1 dygn = (24 * 60m) minuter
	*/
	if(totaltminuter2<=totaltminuter1){
		totaltminuter2 += 24*60;
	}
	printf("Det �r %d minuter mellan klockslagen [%s] och [%s]", totaltminuter2-totaltminuter1, tid1, tid2);
}

/* F�rfattarens l�sning, lite snyggare...
int main() {
   int t1, t2, m1, m2; //blir r�tt m�nga variabler h�r ocks�, +n1 och n2 som deklareras nedan. Han anv�nder inte char alls dock
   char punkt;
   printf("Starttid (tt.mm)? ");
   scanf("%d%c%d", &t1, &punkt, &m1); //<--- g�r tydligen g�ra s�, funkar f�r att en int kan h�lla ett enstaka tecken, spelar ingen roll vad man sl�r in mellan siffrorna, s� l�nge det �r ett enda tecken
   printf("Sluttid  (tt.mm)? ");
   scanf("%d%c%d", &t2, &punkt, &m2);
   int n1 = t1 * 60 + m1;    
   int n2 = t2 * 60 + m2; 
   if (n2 < n1)
     n2 = n2 + 60*24;	   
   printf("Tidsintervall: %d minuter\n", n2-n1);
 } */