#define PNAMN_LANGD 30
#define N 30

struct person{
	char  fornamn[PNAMN_LANGD], efternamn[PNAMN_LANGD];
	int fodd_ar;
};

struct bil{
	struct person *agare; //pekare till struct person
	char regNr[8], fabrikat[N];
	int arsModell, tjansteVikt, motorEffekt;
};

//Deklaration av funktion
void skrivUtStructMedPekare(struct bil *p);
