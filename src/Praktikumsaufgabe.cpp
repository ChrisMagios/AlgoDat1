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
using namespace std;
typedef basic_istream<char> istream;
int main() {
	CursorList<Student, 20> li;
	CursorList<Student, 20>::iterator it(li);
	cout
			<< "Bitte Name, Vorname, Martikelnummer(6-stellig) und Geburtsdatum(MMDDJJJJ) eingeben!"
			<< endl;
	cout << "Abbruch erfolgt durch Eingabe von Exit." << endl;
	string cond;
	for (int i = 0; i <= 1; ++i) {
		Student s;
		cin >> s;
		li.insert(it, s);
	}
	Student sFind("Chris", "Magios", 123456, 27021996);
	cout << "Start "<< li.getStart_list() << "free "<< li.getStart_free() << endl;
	cout << "Begin " << *li.begin() << endl;
	cout << "Iterator " << *it << endl;
	cout << "Test Find "<< *find(li.begin(), it, sFind) << endl;

}
