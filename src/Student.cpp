/*
 * Student.cpp
 *
 *  Created on: 08.10.2018
 *      Author: Chris
 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(){}

Student::Student(std::string vor, std::string nach, int matrikel, int geb) {
	strncpy(mVorname, vor.c_str(),10);		//strncpy und c_str zur konvertierung des Strings.
	strncpy(mName, nach.c_str(),10);
	mMatrikelnummer = matrikel;
	mGeburtsdatum = geb;
}


//Vergleich der Studenten über die Matrikelnummer
bool operator==(const Student &student1, const Student &student2) {

	return student1.mMatrikelnummer == student2.mMatrikelnummer;
}

bool operator!=(const Student &student1, const Student &student2) {

	return student1.mMatrikelnummer != student2.mMatrikelnummer;
}

bool operator<=(const Student &student1, const Student &student2) {

	return student1.mMatrikelnummer <= student2.mMatrikelnummer;
}

bool operator>=(const Student &student1, const Student &student2) {

	return student1.mMatrikelnummer >= student2.mMatrikelnummer;
}

bool operator>(const Student &student1, const Student &student2) {

	return student1.mMatrikelnummer > student2.mMatrikelnummer;
}

bool operator<(const Student &student1, const Student &student2) {

	return student1.mMatrikelnummer < student2.mMatrikelnummer;
}
// In- und Ouput
ostream& operator << (ostream& ostr, const Student& stud)
 {stud.write(ostr); return ostr;}

istream& operator >> (istream& istr, Student& stud)
 {stud.read(istr); return istr;}

Student::~Student() {

}


