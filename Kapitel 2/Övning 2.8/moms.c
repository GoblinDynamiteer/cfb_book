#include <stdio.h>

int main()
{
	float pris; //Pris inklusive moms, kan vara ett decimaltal
	int momssats; //momssats, hela antal procent
	printf("Ange pris inklusive moms: ");
	scanf("%f", &pris); //Input för pris, ex 199,99
	printf("Ange momssats i hela antal procent: "); 
	scanf("%d", &momssats);//Input för momssats, ex 25
	float pris_utan_moms = pris - momssats / 100.0 * pris; //Beräknar priset utan moms, till var pris_utan_moms
	float moms = momssats / 100.0 * pris; //Beräknar momsen
	printf ("Pris utan moms: %.2f kr, moms: %.2f kr", pris_utan_moms, moms); //Skriver ut pris utan moms, samt momsen
	return 0;
}

/*
Ex. Output:
Ange pris inklusive moms: 199.99
Ange momssats i hela antal procent: 25
Pris utan moms: 149.99 kr, moms: 50.00 kr
*/