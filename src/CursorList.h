/*
 * CursorList.h
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */



#ifndef CURSORLIST_H_
#define CURSORLIST_H_

#include <stdio.h>
template <class T>
class CursorIterator;

template <class T> // Type T for CursorList template!

class CursorList {


private:

	T arrayList[20][2];
	int data = 0;
	int prev = 1;
	int next = 2;
	int start_free;		// Start der freien Liste im Array.
	int start_list;		// Start der CursorListe im Array.

public:

	typedef T value_type;
	typedef  CursorIterator<T> iterator;

//Innere Klasse Cursor Iterator!!
	class CursorIterator {

	private:
		int cursorIndex = 0;
		CursorList <T> cursorList;
	public:

		CursorIterator();

		CursorIterator( CursorList <T>& list ) {
			cursorList = list;
			cursorIndex = cursorList.getStart_list();
		}

		T& operator *() {
			return *this->cursorList.getListElement(cursorIndex);
		}

		iterator& operator = (const iterator& rhs) {
			this->cursorIndex = rhs.cursorIndex;
			this->cursorList = rhs.cursorList;
			return *this;
		}

		bool operator != (const iterator& rhs) const {
			return this->cursorIndex != rhs.cursorIndex;
		}
		bool operator == (const iterator& rhs) const {
			return this->cursorIndex == rhs.cursorIndex;
		}

		iterator& operator++() {
			this->cursorIndex = this->cursorList.getNextElement();
			return *this;

		}
		iterator operator ++(int);						//postfix operator, dummy parameter

		virtual ~CursorIterator();

	};


// Anfang Member Methoden Cursor Iterator!
// Konstructor

	CursorList() {
		start_free = 0;
		start_list = start_free;
	}

// Getters und Setters

	int getStart_list() {
		return start_list;
	}

	int getStart_free() {
			return start_free;
	}

	int getNextElement(int index) {
		return arrayList[index][next];
	}

	int getPrevElement(int index) {
		return arrayList[index][prev];
	}


	T getListElement(int index) {
		return arrayList[index][data];
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
		return 0;
	}

	bool empty() const {
		return size() == 0;
	}

	T& front() const {
		return arrayList[start_list][data];
	}

	//füge neues.
	void push_front(const T& t) {
		if (!empty()) {
			arrayList[start_free][data] = t;
			arrayList[start_free][next] = start_list;	// Setze Nachfolger des neuen ersten Elements.
			arrayList[start_list][prev] = start_free;	// Setze Vorgänger des alten ersten Elements.

			start_list = start_free;
			start_free = arrayList[start_free][next];	// Neuer freier Listen anfang.
		}
	}

	void pop_front() {
		if (!empty()) {

		}
	}



	iterator begin() const {

	}

	iterator end() const;

	//insert befor itr
	iterator instert(iterator itr, const T& value) {
		//vorheriges next ändern;
		//diesem element prev ändern!
	}
	iterator erase(iterator start, iterator stop);	//stop exclusive
	iterator erase(iterator itr);					//return ++itr

	void list_setData(int index) {

	}


	virtual ~CursorList();
};

#endif /* CURSORLIST_H_ */
