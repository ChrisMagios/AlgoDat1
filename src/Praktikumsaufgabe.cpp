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
				"Heinrich vier ", "hennry fuenf " , "markus sechs " , "thorsten sieben " , "helmut acht "};
		for (int i = 0; i < 8; i++) {
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
				li.toString();
				istrstr.clear();
			}

		}
	}

	cout << "The List is ready!!" << endl;
	cout << "The following commands are available" << endl;

	cout << "\"insert name surname mart bday\" - Inserts a new student to the list" << endl;
	cout << "\"push_front name surname mart bday\"" << endl;
	cout << "\"pop_front\"" << endl;
	cout << "\"erase\"" << endl;
	cout << "\"erase_from start iterator stop\"" << endl;
	cout << "\"find\" (martikelno.)" << endl;
	cout << "\"show\" - displays the list" << endl;

	bool loop = true;
	std::string command, name, surname, mart, bday;
	while (loop) {

		command.clear();
		istrstr.clear();
		string tmp = "";
		getline(cin, tmp);
		istrstr.str(tmp);
		istrstr >> command >> name >> surname >> mart >> bday;


		if (command == "insert") {
			Student s;
			istrstr.clear();
			tmp = "";
			std::stringstream ss;
			ss << name << " " << surname << " " << mart << " " << bday;
			tmp = ss.str();
			istrstr.str(tmp);
			istrstr >> s;
			li.insert(it, s);
		}

		if (command == "show") {
			li.toString();

		}

		if (command == "push_front") {
			istrstr.clear();
			tmp = "";
			std::stringstream ss;
			ss << name << " " << surname << " " << mart << " " << bday;
			tmp = ss.str();
			Student s;
			istrstr.str(tmp);
			istrstr >> s;
			li.push_front(s);

		}
		if(command == "pop_front"){
			li.pop_front();
			cout << "new front! " << *li.begin() << endl;

		}

		if (command == "erase") {
			li.erase(it);

		}

		if (command == "erase_from") {
			CursorList<Student, 20>::iterator startIT(li);
			CursorList<Student, 20>::iterator stopIT(li);

			startIT = li.begin();
			stopIT = li.begin();
			for (int i = 1; i < stoi(name); i++) {
				startIT++;
			}
			for (int i = 1; i < stoi(surname); i++) {
				stopIT++;
			}
			li.erase(startIT, stopIT);

		}
		if(command == "find"){
			CursorList<Student, 20>::iterator startIT(li);
			CursorList<Student, 20>::iterator stopIT(li);

			startIT = li.begin();
			stopIT = li.end();

			Student s ("Max" , "Mustermann", stoi(name) , 11112011);
			cout << *find(startIT, stopIT, s) << endl;
		}

		if (command == "exit") {
			loop = false;
		}

	}

}
