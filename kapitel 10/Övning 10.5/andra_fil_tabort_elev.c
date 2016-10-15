#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100

/* Övning 10.5, Sida 235

Antag att man ska kunna ta bort elever från resultatfilen.
Det ska man kunna göra genom att på tangentbordet bara
skriva elevens namn utan poäng efter.

Föreslå vilka justeringar man kan göra i programmet för att
astadkomma detta.

Tips: Undersök om det finns några tecken efter namnet på den
inmatade raden. 

Programmet för att byta i resultatfilen finns på sida 233 och 234

resultatfil.txt
Linda Olsson 12 20 15 5
Mikael Bergman 15 30
Karin Jansson Fernandez 19 30 10 10
Daniel Lindman 10 28 20
*/

/* Författaren har en funktion (Sida 199) som han använder ofta, 
Den kollar om sista tecknet i en sträng är newline '\n', om detta är fallet 
byts tecknet ut till ett nolltecken '\0'. 
(funktionen fgets kan ibland innehålla newline) 
Om newline tas bort returneras 1 (strängen är komplett med nolltecken i slutet)
Annars 0 (det kan finnas text kvar i buffert)
*/
_Bool removeNewLine(char a[]){
	int i = strlen(a) -1; //näst sista bokstaven i strängen
	if (a[i] == '\n'){
		a[i] = '\0';
		return 1;
	}
	//printf("\nTest: removeNewLine returnerar 0, det kan finnas text i buffer!\n");
	return 0;
}

/* En annan funktion författaren använder (Sida 190) 
Om man skriver in en längre text än x i fgets(string, x, stdin) så läggs
resterande i en buffert som läggs in i nästa inläsning, om man använder denna funktion
så rensas bufferten */
void clearBuffer(void){
	int i;
	while ((i = getchar()) != '\n' && i != EOF)
		;
}

//Liknande funktionen clearBuffer, fast för läsning från textfil
void clearBufferFil(FILE *f){
	int i;
	while ((i = fgetc(f)) != '\n' && i != EOF)
		;
}

/* för att slippa använda
	if (!removeNewLine(sträng))
		clearBuffer();
efter varje inläsning med fgets har författaren byggt en egen inläsningsfunktion (Sida 200)

Funktionen ger returvärdet 1 vid en lyckad inläsning, annars 0 (vid EOF)
den får parametrarna: strängen som ska läsas in, och 'n' för fgets(sträng, n, stdin)
*/
_Bool radInput(char a[], int n){
	//fgets returnerar NULL vid misslyckad inläsning
	if (fgets(a, n, stdin) == NULL){
		return 0;	
	}
	/*om removeNewLine returnerar 0 (!inverterat) finns det text kvar i buffert, 
	och clearBuffer-funktionen anropas */
	if (!removeNewLine(a)){ 
		clearBuffer();	
	}
	return 1;
}

//Funktion som läser text från textfil till textsträng, returnerar 0 vid avslut
_Bool textfilTillString(char *a, int n, FILE *f){
	if (fgets(a, N, f) == NULL){
		return 0;
	}
	if (!removeNewLine(a)){ 
		clearBufferFil(f);
	}
	return 1;
}

//funktion plockar ut elevnamnet från den inmatade raden. Inmatad rad kan se ut som "Kalle Karlsson 12 33 44 22"
void hittaNamn(const char *inmatning, char *namn_ut){
	/*strcspn(x,y) - anger hur många tecken som finns i x innan ett tecken i y hittas
	Anger i detta fall hur många tecken som finns i den inmatade strängen, innan en siffra hittas
	Ett mellanslag kommer hittas om det slogs in efter det inmatade namnet*/
	int antalTecken = strcspn(inmatning, "0123456789");
	//Temp-variabel för hållare av namn, sätts till antal tecken innan siffra i inmatning (+1 för nolltecken)
	char temp[antalTecken+1];
	//Sätter temp till lika med inmatningen, 0 till antalTecken tecken, sätter nolltecken efter 
	strncpy(temp, inmatning, antalTecken);
	temp[antalTecken] = '\0';
	//Om temp har sista tecknet som mellanslag tas det bort (bygg om för om användare matar in flera mellanslag?)
	if(isspace(temp[antalTecken-1])){;
			temp[antalTecken-1] = '\0';
		}
	int i = 0;
	//temp kopieras till namn_ut ett tecken i taget, som görs om till lowercase (gemen)
	for(; i<strlen(temp);i++){
		namn_ut[i] = tolower(temp[i]);
	}
	namn_ut[i] = '\0';
}

//Egen version av programmet på sida 233
int main(){
	FILE *resultatfil = fopen("resultatfil.txt", "r");
	char tempfil_namn[N], elevInput[N], elevNamn[N], s[N], elevNamnFil[N];
	_Bool NyElev;
	/* tmpnam genererar ett randomiserat namn. Av någon anledning innehåller namnet alltid "\" 
	i början, vilket innebär att filen kommer hamna i roten på den disk som denna fil ligger i (sant?) */
	tmpnam(tempfil_namn);
	//jag väljer att byta ut första tecknet i tempfilen, så att den hamnar i samma katalog som c-filen.
	tempfil_namn[0] = 'A';
	FILE * tempfil = fopen(tempfil_namn, "w");
	printf("Ange Elevnamn och poäng: ");
	radInput(elevInput, N);
	//Plocka ut namnet från inmatningen med funktionen hittaNamn
	hittaNamn(elevInput, elevNamn);
	//printf("hittat och Konverterat namn: %s\n",elevNamn);
	//textfilTillString läser in texten från resultatfil till s, en rad i taget eller till N tecken lästs
	NyElev = 0;
	while(textfilTillString(s, N, resultatfil)){
		//printf("while: %s\n", s); //test
		//jämför inmatat namn med rad från texten, strcmp returnerar 0 om strängarna är samma (!inverterat i if-satsen)
		hittaNamn(s, elevNamnFil);
		/* om den inmatade elevens namn hittas i textfilen skrivs hela inmatade raden till temp-filen
		då returtecken tas bort från strängarna med funktionen removeNewLine, så skrivs ett \n i fprintf för att få nyrad
		efter varje elev */
		if (!strcmp(elevNamnFil, elevNamn)){
			/*strpbrk(x,y) returnerar position av det första tecknet som hittas i x, av något av tecknen i y
			om tecknet inte hittas returneras NULL. I detta fall kollas om elevInput innehåller en siffra, om
			ingen siffra hittas ska elevens namn raderas från texfilen */
			if (strpbrk(elevInput, "0123456789") != NULL){
				fprintf(tempfil, "%s\n", elevInput);
				NyElev = 1;
			}
			//om ingen siffra hittas sätts NyElev till 1 för att eleven inte ska skrivas till temp 
			else{
				NyElev = 1;
			}
		}
		else {
			fprintf(tempfil, "%s\n", s);
		}

	}
	//för att få in den nya inmatningen till tempfilen (om den inte hittades i textfilen)
	if(!NyElev){
	fprintf(tempfil, "%s\n", elevInput); //som if-satsen i while-loopen ovan
	}
	/*kopiera innehållet från temp-filen till resultatfilen 
	Resultatfilen är öppnad som "r" -readonly, och temp som "w". Med freopen stänger programmet
	och öppnar filen igen, man kan då sätta andra parametrar. 
	freopen(filnamn, läsning, FILE variabel)
	*/
	freopen(tempfil_namn, "r", tempfil);
	freopen("resultatfil.txt", "w", resultatfil);
	//läs text från tempfilen till s, och skriv över resultatfilen med s
	while(textfilTillString(s, N, tempfil)){
		fprintf(resultatfil, "%s\n", s);
	}
	//Stänger och raderar temp-filen, notera att filens namn ska användas i remove();
	fclose(tempfil);
	//system("pause");
	remove(tempfil_namn);
}