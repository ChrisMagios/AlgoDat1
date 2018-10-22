/*
 * CursorList.h
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */

#include <stdio.h>
#ifndef CURSORLIST_H_
#define CURSORLIST_H_

#include "CursorIterator.h"
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


// Konstructor

	CursorList() {
		start_free = 0;
		start_list = start_free;
	}

	int size() const {
		iterator it = begin();
		while (it != end()) {
			size++;
			it++;
		}
		return size;
	}

	bool empty() const {
		return size() == 0;
	}

	T& front() const {
		return arrayList[start_list][data];
	}

	//add  a new value to the front of a list.
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
