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
//
//template<class T>
//class CursorIterator;

using namespace std;
template<class T, unsigned int SIZE> // Type T for CursorList template!

class CursorList {
	typedef T value_type;


private:
	//using entry = std::tuple<T,int,int>; // Tupel aus (T, prev, next)

	typedef struct entry {
		T data;
		int prev;
		int next;
	} entryT;

	entryT entryList[SIZE];
	static constexpr int data = 0; //Defines them as Constant Expression at Compiletime.
	static constexpr int prev = 1;
	static constexpr int next = 2;
	static constexpr int nullIndex = -1;
	int start_free = 0;	// Start der freien Liste im Array.
	int start_list = 0;	// Start der CursorListe im Array.
public:
	// Initialisiert die Vor- und Nachfolger der EntryList.
	void initList() {

		entryList[0].prev = nullIndex;
		// andere Schreibweise.

		entryList[0].prev = nullIndex;
		// bessere Schreibweise #readablility

		entryList[0].next = 1;
		for (int i = 1; i < 20; i++) {
			//get<prev>(entryList[i]) = (i - 1);
			entryList[i].prev = (i - 1);
			//get<next>(entryList[i]) = i + 1;
			entryList[i].next = i + 1;

			cout << "INDEX: " << i << " PREV: " << entryList[i].prev
					<< " NEXT:" << entryList[i].next << endl;
		}

		entryList[20].prev = 19;
		entryList[20].next = nullIndex;
		start_free = 0;
		start_list = 0;

	}
// Konstructor
	CursorList() {
		initList();
	}
	virtual ~CursorList() {

	}

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

	T& getListElement(int index) {
		return std::get<data>(entryList[index]);
	}

	int size() const {
		return SIZE;
	}

	bool empty() const {
		return start_list == start_free;
	}

	T& front() {
		return entryList[start_list].data;
	}

	//füge neues Element am Anfang der Liste hinzu.
	void push_front(const T& t) {
		int tmp_free = entryList[start_free].next;
		// Wenn schon Elemente in der Liste liegen!
		if (!empty()) {
			entryList[start_free].next = start_list;
			entryList[start_list].prev = start_free;
		}
		entryList[start_free].data = t;
		entryList[start_free].prev = nullIndex;
		// Start der Listen neu setzen.
		start_list = start_free;
		start_free = tmp_free;
		entryList[start_free].prev = nullIndex;

	}

	void pop_front() {
		delete get<data>(entryList[start_list]);
		entryList[start_free].prev = start_list;
		start_free = start_list;
		entryList[start_free].prev = nullIndex;
		start_list = std::get<next>(entryList[start_list]);
		entryList[start_list].prev = nullIndex;
	}
	// Iterator und methoden

	//Innere Klasse Cursor Iterator!!
		class CursorIterator {
			friend CursorList;
			typedef CursorIterator iterator;
		private:
			int cursorIndex = -1;
			CursorList<T, SIZE>& cursorList;
		public:

			CursorIterator() {

			}

			CursorIterator(CursorList<T, SIZE>& list)  : cursorList(list) {
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
				if (cursorList.getNextElement(cursorIndex) == nullIndex)
					return nullptr;

				this->cursorIndex = this->cursorList.getNextElement();
				return this;

			}
			iterator operator ++(int) {
				if (cursorList.getNextElement(cursorIndex) == nullIndex)
					return nullptr;

				this->cursorIndex = this->cursorList.getNextElement();
				return this;
			}

			virtual ~CursorIterator();

		};
	typedef CursorIterator iterator;




	iterator begin() const {
		return CursorIterator(this);
	}

	iterator end() const {
		iterator tmp = this->begin();
		for (iterator it = this->begin(); it.getCursorList().getNextElement() != nullIndex; it ++) {
			tmp++;
		}
		return tmp;

	}

	//insert befor itr
	iterator insert(iterator itr, const T& value) {
		//vorheriges next ändern;
		//diesem element prev ändern!
	}
	iterator erase(iterator start, iterator stop);	//stop exclusive
	iterator erase(iterator itr);					//return ++itr

};

#endif /* CURSORLIST_H_ */
