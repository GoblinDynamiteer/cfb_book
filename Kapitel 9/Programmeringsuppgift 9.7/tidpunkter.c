#include <stdio.h>
#include <string.h>

/* Programmeringsuppgift 9.7, Sida 215

Skriv ett program som läser in två tidpunkter med formen tt.mm
Programmet ska visa hur många minuter det är mellan de två
tidpunkterna.

Tips: Räkna om de båda tiderna till antal minuter som gått sedan
det aktuella dygnets start, och gör en justering om den senare tidpunkten
infaller under det följande dygnet. */

//En eventuell "raggarlösning" med onödigt många variabler för hållare och konvertering
int main(){
	char tid1[7] = "09:35", tid2[7] = "01:30";
	char h1[3], h2[3];
	char m1[3], m2[3];
	int timme1,minut1,timme2,minut2, totaltminuter1, totaltminuter2;
	printf("Ange tidpunkt 1 (hh:mm): ");
	//fgets(tid1, 7, stdin);
	/*
	Jag får inte fgets att fungera när två variabler ska sätta, scanf fungerar så länge man inte ska slå in mellanslag
	*/
	scanf("%s", tid1);
	printf("Ange tidpunkt 2 (hh:mm): ");
	//fgets(tid2, 7, stdin);
	scanf("%s", tid2);
	int i=0, j=0;
	//(xx:yy) - xx/yy i tid1 och tid2 sätts till h1=xx h2=xx m1=yy m2=yy
	for(;i<2;){
		h1[i] =tid1[i];
		h2[i] =tid2[i];
		m1[i] =tid1[i+3];
		m2[i] =tid2[i+3];
		i++;
	}
	//nolltecken sätts i slutet av strängarna för h1,h2,m1,m2
	h1[i] = '\0';
	h2[i] = '\0';
	m1[i] = '\0';
	m2[i] = '\0';
	/*strängarna h1,h2,m1,m2 läses in som %d till int-variablerna timme1, timme2, minut1, minut2
	sscanf fungerar som scanf, fast får input från sträng istället för användare, första argumentet är
	textsträngen sscanf(sträng, "formattering", &tillvariabel);
	*/
	sscanf(h1, "%d", &timme1);
	sscanf(h2, "%d", &timme2);
	sscanf(m1, "%d", &minut1);
	sscanf(m2, "%d", &minut2);
	//Beräknar minuter från 0 (dagens start)
	totaltminuter1 = timme1*60 + minut1;
	totaltminuter2 = timme2*60 + minut2;
	/*
	om antal minuter från 0 är större för den andra inmatade tidpunkten, innebär det att det ligger i dagen efter 
	i så fall adderas en heldags minuter till summan 1 dygn = (24 * 60m) minuter
	*/
	if(totaltminuter2<=totaltminuter1){
		totaltminuter2 += 24*60;
	}
	printf("Det är %d minuter mellan klockslagen [%s] och [%s]", totaltminuter2-totaltminuter1, tid1, tid2);
}

/* Författarens lösning, lite snyggare...
int main() {
   int t1, t2, m1, m2; //blir rätt många variabler här också, +n1 och n2 som deklareras nedan. Han använder inte char alls dock
   char punkt;
   printf("Starttid (tt.mm)? ");
   scanf("%d%c%d", &t1, &punkt, &m1); //<--- går tydligen göra så, funkar för att en int kan hålla ett enstaka tecken, spelar ingen roll vad man slår in mellan siffrorna, så länge det är ett enda tecken
   printf("Sluttid  (tt.mm)? ");
   scanf("%d%c%d", &t2, &punkt, &m2);
   int n1 = t1 * 60 + m1;    
   int n2 = t2 * 60 + m2; 
   if (n2 < n1)
     n2 = n2 + 60*24;	   
   printf("Tidsintervall: %d minuter\n", n2-n1);
 } */