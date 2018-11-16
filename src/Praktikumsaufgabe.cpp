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
	string line;
	CursorList<Student, 20> li;

//	while (getline(cin, line)) {
//		if(line.empty()) {
//			break;
//		}

//-----Test-----
	Student s0;
	"Ich glaub so hat er es gemeint!" >> s0;
//--------------
	for(int  i = 0; i <= 20; i++) {
		Student s0;
		s0.read(std::cin);

	}






}
