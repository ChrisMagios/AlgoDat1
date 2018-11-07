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
using namespace std;

int main() {

	Student s1("Peter","Pflaume", 12345,54321);
	Student s2("Kai", "Kleber", 54321, 23443);

	CursorList<Student, 20> li;
	li.push_front(s1);
	li.push_front(s2);
	cout << "Front: "<< li.front() << endl;




}
