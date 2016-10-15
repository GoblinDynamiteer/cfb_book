#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100

/* �vning 10.5, Sida 235

Antag att man ska kunna ta bort elever fr�n resultatfilen.
Det ska man kunna g�ra genom att p� tangentbordet bara
skriva elevens namn utan po�ng efter.

F�resl� vilka justeringar man kan g�ra i programmet f�r att
astadkomma detta.

Tips: Unders�k om det finns n�gra tecken efter namnet p� den
inmatade raden. 

Programmet f�r att byta i resultatfilen finns p� sida 233 och 234

resultatfil.txt
Linda Olsson 12 20 15 5
Mikael Bergman 15 30
Karin Jansson Fernandez 19 30 10 10
Daniel Lindman 10 28 20


*/

/* F�rfattaren har en funktion (Sida 199) som han anv�nder ofta, 
Den kollar om sista tecknet i en str�ng �r newline '\n', om detta �r fallet 
byts tecknet ut till ett nolltecken '\0'. 
(funktionen fgets kan ibland inneh�lla newline) 
Om newline tas bort returneras 1 (str�ngen �r komplett med nolltecken i slutet)
Annars 0 (det kan finnas text kvar i buffert)
*/
_Bool removeNewLine(char a[]){
	int i = strlen(a) -1; //n�st sista bokstaven i str�ngen
	if (a[i] == '\n'){
		a[i] = '\0';
		return 1;
	}
	//printf("\nTest: removeNewLine returnerar 0, det kan finnas text i buffer!\n");
	return 0;
}

/* En annan funktion f�rfattaren anv�nder (Sida 190) 
Om man skriver in en l�ngre text �n x i fgets(string, x, stdin) s� l�ggs
resterande i en buffert som l�ggs in i n�sta inl�sning, om man anv�nder denna funktion
s� rensas bufferten */
void clearBuffer(void){
	int i;
	while ((i = getchar()) != '\n' && i != EOF)
		;
}

//liknande funktionen clearBuffer, fast f�r l�sning fr�n textfil
void clearBufferFil(FILE *f){
	int i;
	while ((i = fgetc(f)) != '\n' && i != EOF)
		;
}


/* f�r att slippa anv�nda
	if (!removeNewLine(str�ng))
		clearBuffer();
efter varje inl�sning med fgets har f�rfattaren byggt en egen inl�sningsfunktion (Sida 200)

Funktionen ger returv�rdet 1 vid en lyckad inl�sning, annars 0 (vid EOF)
den f�r parametrarna: str�ngen som ska l�sas in, och 'n' f�r fgets(str�ng, n, stdin)
*/
_Bool radInput(char a[], int n){
	//fgets returnerar NULL vid misslyckad inl�sning
	if (fgets(a, n, stdin) == NULL){
		return 0;	
	}
	/*om removeNewLine returnerar 0 (!inverterat) finns det text kvar i buffert, 
	och clearBuffer-funktionen anropas*/
	if (!removeNewLine(a)){ 
		clearBuffer();	
	}
	return 1;
}


//funktion som l�ser text fr�n textfil till textstr�ng, returnerar 0 vid avslut
_Bool textfilTillString(char *a, int n, FILE *f){
	if (fgets(a, N, f) == NULL){
		return 0;
	}
	if (!removeNewLine(a)){ 
		clearBufferFil(f);
	}
	return 1;
}


void hittaNamn(const char *inmatning, char *namn_ut){
	/*strcspn(x,y) - anger hur m�nga tecken som finns i x innan ett tecken i y hittas
	Anger i detta fall hur m�nga tecken som finns i den inmatade str�ngen, innan en siffra hittas
	Ett mellanslag kommer hittas om det slogs in efter det inmatade namnet*/
	int antalTecken = strcspn(inmatning, "0123456789");
	//temp-variabel f�r h�llare av namn, s�tts till antal tecken innan siffra i inmatning (+1 f�r nolltecken)
	char temp[antalTecken+1];
	//s�tter temp till inmatningen, 0 till antalTecken tecken, s�tter nolltecken efter 
	strncpy(temp, inmatning, antalTecken);
	temp[antalTecken] = '\0';
	//om temp har sista tecknet som mellanslag tas det bort (bygg om f�r om anv�ndare matar in flera mellanslag?) ev g�r detta p� namn_ut ist�llet
	if(isspace(temp[antalTecken-1])){
			//printf("Funktion: Hittade mellanslag i slutet av temp!\n");
			temp[antalTecken-1] = '\0';
		}
	//printf("Funktion:  Temp: %s\n",temp);
	int i = 0;
	//temp kopieras till namn_ut ett tecken i taget, som g�rs om till lowercase (gemen)
	for(; i<strlen(temp);i++){
		namn_ut[i] = tolower(temp[i]);
	}
	namn_ut[i] = '\0';
	//printf("Funktion: namn_ut: %s \n",namn_ut);
}



//Jag f�rs�ker bygga en egen version av programmet
int main(){
	FILE *resultatfil = fopen("resultatfil.txt", "r");
	char tempfil_namn[N], elevInput[N], elevNamn[N], s[N], elevNamnFil[N];
	_Bool NyElev;
	/* tmpnam genererar ett randomiserat namn. Av n�gon anledning inneh�ller namnet alltid "\" 
	i b�rjan, vilket inneb�r att filen kommer hamna i roten p� den disk som denna fil ligger i (sant?) */
	tmpnam(tempfil_namn);
	//jag v�ljer att byta ut f�rsta tecknet i tempfilen, s� att den hamnar i samma katalog som c-filen.
	tempfil_namn[0] = 'A';
	FILE * tempfil = fopen(tempfil_namn, "w");
	printf("Ange Elevnamn och po�ng: ");
	radInput(elevInput, N);
	//Plocka ut namnet fr�n inmatningen med funktionen hittaNamn
	hittaNamn(elevInput, elevNamn);
	//printf("hittat och Konverterat namn: %s\n",elevNamn);
	//textfilTillString l�ser in texten fr�n resultatfil till s, en rad i taget eller till N tecken l�sts
	while(textfilTillString(s, N, resultatfil)){
		NyElev = 0;
		//printf("while: %s\n", s); //test
		//j�mf�r inmatat namn med rad fr�n texten, strcmp returnerar 0 om str�ngarna �r samma (!inverterat i if-satsen)
		hittaNamn(s, elevNamnFil);
		/* om den inmatade elevens namn hittas i textfilen skrivs hela inmatade raden till temp-filen
		d� returtecken tas bort fr�n str�ngarna med funktionen removeNewLine, s� skrivs ett \n i fprintf f�r att f� nyrad
		efter varje elev */
		if (!strcmp(elevNamnFil, elevNamn)){
			printf("Namnet hittades i textfilen!!!\n");
			fprintf(tempfil, "%s\n", elevInput);
			NyElev = 1;
		}
		else {
			fprintf(tempfil, "%s\n", s);
		}
	}
	//f�r att f� in den nya inmatningen till tempfilen (om den inte hittades i textfilen)
	if(!NyElev){
		fprintf(tempfil, "%s\n", elevInput); //som if-satsen i while-loopen ovan
		}
		/*kopiera inneh�llet fr�n temp-filen till resultatfilen 
		Resultatfilen �r �ppnad som "r" -readonly, och temp som "w". Med freopen st�nger programmet
		och �ppnar filen igen, man kan d� s�tta andra parametrar. 
		freopen(filnamn, l�sning, FILE variabel)
		*/
	freopen(tempfil_namn, "r", tempfil);
	freopen("resultatfil.txt", "w", resultatfil);
	//l�s text fr�n tempfilen till s, och skriv �ver resultatfilen med s
	while(textfilTillString(s, N, tempfil)){
		fprintf(resultatfil, "%s\n", s);
	}
	//st�nger och raderar temp-filen
	fclose(tempfil);
	//system("pause");
	remove(tempfil_namn);
}