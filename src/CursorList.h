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


class CursorIterator;
using namespace std;
// Gibt erste Position mit dem Wert value bzw. stop bei erfolgloser Suche.
template<typename Iterator, typename T>
Iterator find(Iterator start, Iterator stop, const T& value) {
	for (Iterator it = start; it != stop;it++) {
		if (*it == value) {
			return it;
		}
	}
	return stop;
}

template<class T, unsigned int SIZE> // Type T for CursorList template!
class CursorList {
	typedef T value_type;

private:
	typedef struct entry {
		T data;
		int prev;
		int next;
	} entryT;

	entryT entryList[SIZE];
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
		return entryList[index].next;

	}

	int getPrevElement(int index) {
		return entryList[index].prev;
	}

	T& getListElement(int index) {
		return entryList[index].data;
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
		delete entryList[start_list].data;
		entryList[start_free].prev = start_list;
		start_free = start_list;
		entryList[start_free].prev = nullIndex;
		start_list = entryList[start_list].next;
		entryList[start_list].prev = nullIndex;
	}

	//Innere Klasse Cursor Iterator!!
	class CursorIterator {
			typedef CursorIterator iterator;
		private:
			int cursorIndex = -1;
			CursorList<T, SIZE> &cursorList;
		public:

			CursorIterator() {
				cursorList = CursorList();
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

			int getNextIteratorElement() {
				return this->cursorList.getNextElement(cursorIndex);
			}

			int getPrevIteratorElement() {
							return this->cursorList.getPrevElement(cursorIndex);
			}

			T& operator *() {
				return this->cursorList.getListElement(cursorIndex);
			}

			iterator& operator =(const iterator& rhs) {
				this->cursorIndex = rhs.cursorIndex;
				this->cursorList = rhs.cursorList;
				return this;
			}

			bool operator !=(iterator& rhs) {
				return this->operator *() != rhs.operator *();
			}
			bool operator ==(iterator& rhs) {
				return this->operator *() == rhs.operator *();
			}

			iterator& operator++() {
				if (cursorList.getNextElement(cursorIndex) == nullIndex)
					return nullptr;

				this->cursorIndex = this->cursorList.getNextElement();
				return this;

			}
			iterator operator ++(int) {
				if (cursorList.getNextElement(cursorIndex) == nullIndex) {

				}

				this->cursorIndex = this->cursorList.getNextElement(cursorIndex);
				return *this;
			}

			virtual ~CursorIterator() {

			}

		};
	typedef CursorIterator iterator;




	iterator begin() {
		return CursorIterator(*this);
	}

	iterator end() {
		iterator tmp = this->begin();
		while (tmp.getNextIteratorElement() != nullIndex) {
			tmp++;
		}
		return tmp;

	}

	//insert befor itr
	iterator insert(iterator itr, T value) {
		//Falls die Liste noch leer ist oder der Iterator auf das erste Element Zeigt !
		if(itr.getCursorIndex() == start_list) {
			push_front(value);
			return itr;
		}
		//neues Element an Start der Freelist einfügen.
		entryList[start_free].data = value;
		entryList[start_free].prev = itr.getPrevIteratorElement();
		entryList[start_free].next = itr.getCursorIndex();

		//Prev. des Iterator Elements ändern.
		entryList[itr.getCursorIndex()].prev = start_free;
		start_free = entryList[start_free].next;
		return itr;

	}
	iterator erase(iterator start, iterator stop);	//stop exclusive
	iterator erase(iterator itr);


};
#endif /* CURSORLIST_H_ */
