#include "area.h"
//Returnerar arean av en cirkel, fr�n inmatad parameter, radie
double area_cirkel(double r){
	return	M_PI*r*r;
}

//Returnerar arean av en triangel, fr�n inmatade parametrar bas och h�jd
double area_triangel(double b, double h){
	return b*h/2;
}

//Returnerar arean av en rektangel, fr�n inmatade parametrar bas och h�jd
double area_rektangel(double b, double h){
	return b*h;
}