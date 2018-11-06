/*
 * CursorList.h
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */

#ifndef CURSORLIST_H_
#define CURSORLIST_H_
#include <stdio.h>
#include "Student.h"
#include <tuple>

template<class T>
class CursorIterator;

using namespace std;
template<class T, unsigned int SIZE> // Type T for CursorList template!

class CursorList {
	typedef T value_type;
	typedef CursorIterator<T> iterator;

private:
	using entry = std::tuple<T,int,int>; // Tupel aus (T, prev, next)
	entry entryList[SIZE];
	static constexpr int data = 0; //Defines them as Constant Expression at Compiletime.
	static constexpr int prev = 1;
	static constexpr int next = 2;
	static constexpr int nullIndex = -1;
	int start_free;	// Start der freien Liste im Array.
	int start_list;	// Start der CursorListe im Array.
public:

// Konstructor
	CursorList();
	virtual ~CursorList();

//Innere Klasse Cursor Iterator!!
	class CursorIterator {

	private:
		int cursorIndex = 0;
		CursorList<T, SIZE> cursorList;
	public:

		CursorIterator() {

		}

		CursorIterator(CursorList<T, SIZE>& list) {
			cursorList = list;
			cursorIndex = cursorList.getStart_list();
		}

		CursorList<T, SIZE> getCursorList() {
			return this->cursorList;
		}

		int getCursorIndex() {
			return this->cursorIndex;
		}

		T& operator *() {
			return this->cursorList.getListElement(cursorIndex);
		}

		iterator& operator =(const iterator& rhs) {
			this->cursorIndex = rhs.cursorIndex;
			this->cursorList = rhs.cursorList;
			return this;
		}

		bool operator !=(const iterator& rhs) const {
			return *this != *rhs;
		}
		bool operator ==(const iterator& rhs) const {
			return *this == *rhs;
		}

		iterator& operator++() {
			if (cursorList.getNextElement(cursorIndex) == nullptr)
				return nullptr;

			this->cursorIndex = this->cursorList.getNextElement();
			return this;

		}
		iterator operator ++(int) {
			if (cursorList.getNextElement(cursorIndex) == nullptr)
				return nullptr;

			this->cursorIndex = this->cursorList.getNextElement();
			return this;
		}

		virtual ~CursorIterator();

	};

// Anfang Member Methoden Cursor Iterator!

// Getters und Setters

	int getStart_list() {
		return start_list;
	}

	int getStart_free() {
		return start_free;
	}

	int getNextElement(int index) {
		return std::get<next>(entryList[index]);

	}

	int getPrevElement(int index) {
		return std::get<prev>(entryList[index]);
	}

	T getListElement(int index) {
		return std::get<data>(entryList[index]); // gibt den eintrage an der ersten Stelle des Tupels wieder
	}

	//
	int size() const {
		/*iterator it = begin();
		 while (it != end()) {
		 size++;
		 it++;
		 }
		 return size;
		 */
		return SIZE;
	}

	bool empty() const {
		return start_list == start_free;
	}

	T& front() const {
		if (!(this->empty())) {
			return std::get<data>(entryList[start_list]);
		}

	}

	//füge neues Element am Anfang der Liste hinzu.
	void push_front(const T& t) {
		if (this->empty()) {
			initList();
			cout << "First START_FREE: "<< start_free << endl;

			start_free = get<next>(entryList[start_free]);
			std::get<prev>(entryList[start_free]) = nullIndex;

			std::get<data>(entryList[start_list]) = t;
			std::get<next>(entryList[start_list]) = nullIndex;


			cout << start_free << endl;
		} else {
			cout << start_free << endl;
			// New Element
			std::get<data>(entryList[start_free]) = t;
			std::get<prev>(entryList[start_free]) = nullIndex;
			std::get<next>(entryList[start_free]) = start_list;
			std::get<prev>(entryList[start_list]) = start_free;

			// start to new Positions!
			//start_list = start_free;
			cout << "Vermuteter Fehler: "<< get<next>(entryList[start_free])<< endl;
			start_free = get<next>(entryList[start_free]);
			std::get<prev>(entryList[start_free]) = nullIndex;
			cout << start_free << endl;

		}

	}

	void pop_front() {
		start_list = std::get<next>(entryList[start_list]);
	}

	iterator begin() const {

	}

	iterator end() const {

	}

	//insert befor itr
	iterator insert(iterator itr, const T& value) {
		//vorheriges next ändern;
		//diesem element prev ändern!
	}
	iterator erase(iterator start, iterator stop);	//stop exclusive
	iterator erase(iterator itr);					//return ++itr

	void initList() {
		get<prev>(entryList[0]) = nullIndex;
		get<next>(entryList[0]) = 1;
		for (int i = 1; i < 20; i++) {
			get<prev>(entryList[i]) = (i - 1);
			get<next>(entryList[i]) = i + 1;
			cout << "INDEX: " << i << " PREV: " << get<prev>(entryList[i])
					<< " NEXT:" << get<next>(entryList[i]) << endl;
		}
		get<prev>(entryList[20]) = 19;
		get<next>(entryList[20]) = nullIndex;
		start_free = 0;
		start_list = 0;

	}

};

#endif /* CURSORLIST_H_ */
