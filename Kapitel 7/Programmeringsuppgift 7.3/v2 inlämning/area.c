#include "area.h"
//Returnerar arean av en cirkel, från inmatad parameter, radie
double area_cirkel(double r){
	return	M_PI*r*r;
}

//Returnerar arean av en triangel, från inmatade parametrar bas och höjd
double area_triangel(double b, double h){
	return b*h/2;
}

//Returnerar arean av en rektangel, från inmatade parametrar bas och höjd
double area_rektangel(double b, double h){
	return b*h;
}