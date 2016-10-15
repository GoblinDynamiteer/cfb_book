//från sida 280

#define PNAMN_LANGD 30

struct person{
	char  fornamn[PNAMN_LANGD], efternamn[PNAMN_LANGD];
	int fodd_ar;
	_Bool singel;
};

//Deklaration av funktioner
void las_person(struct person *p);
void skriv_person(struct person *p);
