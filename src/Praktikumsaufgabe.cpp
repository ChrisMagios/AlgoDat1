//============================================================================
// Name        : Praktikumsaufgabe.cpp
// Author      : Chris, Alex
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

	std::stringstream istrstr;
	bool takeList = false;
	bool correctInput = true;

	cout << "For entering students type \"students\" " << endl;
	cout << "For using a list of five students type \"list\" " << endl;

	while (correctInput) {
		string tmp;
		getline(cin, tmp);
		cin.clear();

		if (tmp == "students") {
			cout << "Please type in Data in the following form: " << endl;
			cout
					<< "[Name, Surname, Martikelno. with 6 digets, birthdate in DDMMJJJJ]"
					<< endl;

			cout << "If you are finished adding students type \"exit\"" << endl;
			takeList = false;
			correctInput = false;
		} else if (tmp == "list") {
			takeList = true;
			correctInput = false;
		} else {
			cout << "Your input was wrong! Are you sure " << tmp
					<< " is correct? Try again..." << endl;
		}
	}

	if (takeList) {
		string name[] = { "Alex eins ", "Thomas zwei ", "Paul drei ",
				"Heinrich vier ", "hennry fuenf " };
		for (int i = 0; i < 5; i++) {
			Student s;
			string tmp = "";
			tmp.append(name[i]);
			string index = std::to_string(i + 1);
			tmp.append(index);
			tmp.append(" ");
			tmp.append(index);

			istrstr.str(tmp);
			istrstr >> s;
			li.insert(it, s);
			istrstr.clear();
		}
	} else {
		for (int i = 0; i <= 20; ++i) {

			Student s;
			string tmp;
			tmp = "";
			getline(cin, tmp);

			if (tmp == "exit") {
				break;
			}

			if (tmp != "show") {
				istrstr.str(tmp);
				istrstr >> s;
				li.insert(it, s);
				istrstr.clear();
			}
			if (tmp == "show") {
				li.toString2();
				istrstr.clear();
			}

		}
	}

	cout << "The List is ready!!" << endl;
	cout << "The following commands are available" << endl;
	cout << "";

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

}
