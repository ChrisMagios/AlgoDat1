//============================================================================
// Name        : Praktikumsaufgabe.cpp
// Author      : Chris
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Student.h"
#include "CursorList.h"
#include "CursorList.cpp"
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main() {
	CursorList<Student, 20> li;
	CursorList<Student, 20>::iterator it(li);
	cout
			<< "Bitte Name, Vorname, Martikelnummer(6-stellig) und Geburtsdatum(MMDDJJJJ) eingeben!"
			<< endl;
	cout << "Abbruch erfolgt durch Eingabe von Exit." << endl;

	std::stringstream istrstr;

	for (int i = 0; i <= 8; ++i) {

		Student s;
		//cin >> s;

		string tmp;
		tmp = "";
		getline(cin,tmp);

		if(tmp == "Exit"){
			break;
		}
		istrstr.str(tmp);
		istrstr >> s;

		li.insert(it, s);
		istrstr.clear();
	}

	Student sFind("Chris", "Magios", 123456, 27021996);
	//cout << "Start "<< li.getStart_list() << "free "<< li.getStart_free() << endl;
	//cout << "Begin " << *li.begin() << endl;
	//cout << "Iterator " << *it << endl;
	//cout << "Test Find "<< *find(li.begin(), it, sFind) << endl;

	//li.erase(it);
	//cout << "Test earase: " << *it << endl;

	//li.toString2();

	//Alexander First 846515 45421325
	//Thomas Second 456985 52136853
	//Pablo Third 125469 52426328
	//Emanuel Fourth 122238 41126598
	//Till Fith 157968 45682156
	//Harry Sixed 115599 98653247
	li.toString2();
	li.erase(it);

	cout << "~~~~~~~~~~~~~AFTER ERASED~~~~~~~~~~~~~~~~~~~~~~" << endl;
	li.toString2();


}
