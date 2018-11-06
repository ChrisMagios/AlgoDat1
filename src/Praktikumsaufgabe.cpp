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

	Student *s1 = new Student("Peter","Pflaume", 12345,54321);
	Student *s2 = new Student("Peter","Pflaume", 12345,54321);

	if(s1!=s2)std::cout <<	"Sind unterschiedliche Studenten!" << std::endl;
	std::cout << "Zeigen auf das gleiche Element" << std::endl;



}
