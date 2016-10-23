#define ABNAMN_LANGD 20

/* Programmeringsuppgift 12.6, Sida 311

Utöka programmet på sida 307 så att man kan 
ändra abonnemangsuppgifter som redan finns 
i filen

Tips: Använd fseek för att skriva till rätt position
i .dat-filen. */


//Struktdeklaration av ett telefon/data-abonnemang
struct abonnemang{
	char namn[ABNAMN_LANGD];
	double per_manad;
	int fria_min;
	double extra_min;
	double fria_gb;
	double extra_gb;
};