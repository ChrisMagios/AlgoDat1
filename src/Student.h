/*
 * Student.h
 *
 *  Created on: 08.10.2018
 *      Author: Chris
 */
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#ifndef STUDENT_H_
#define STUDENT_H_
using namespace std;



class Student {

private:
	int mMatrikelnummer;
	char mVorname[10];
	char mName[10];
	int mGeburtsdatum;

public:

// Konstruktor und Destruktor
	Student();
	Student(std::string vor, std::string nach, int martikel, int geb);
	virtual ~Student();


// Getters und Setters
	int getMatrikelnummer(){
		return mMatrikelnummer;
	}

	void setMatrikelnummer(int matrikelnummer){
		mMatrikelnummer = matrikelnummer;
	}

	int getGeburtsdatum(){
		return mGeburtsdatum;
	}

	void setGeburtsdatum(int geburtsdatum){
		mMatrikelnummer = geburtsdatum;
	}

	char* getVorname(){
		return mVorname;
	}

	void setVorname(char* vorname ){
		strncpy(mVorname, vorname,10);
	}

	char* getName(){
		return mName;
	}

	void setName(char* name ){
		strncpy(mName, name,10);
	}



// Operatoren �berladen um vergleich der Studenten �ber die Matrikelnummer zu erm�glichen
	friend bool operator==(const Student &student1, const Student &student2);
	friend bool operator!=(const Student &student1, const Student &student2);
	friend bool operator<=(const Student &student1, const Student &student2);
	friend bool operator>=(const Student &student1, const Student &student2);
	friend bool operator>(const Student &student1, const Student &student2);
	friend bool operator<(const Student &student1, const Student &student2);

// In- und Output
	virtual void write(ostream& ostr)const {

	}
	virtual void read(istream& istr) {

	}



};

// Ein und Ausgabeoperatoren
ostream& operator << (ostream& ostr, const Student& stud);
istream& operator >> (istream& istr, Student& stud);

#endif /* STUDENT_H_ */
