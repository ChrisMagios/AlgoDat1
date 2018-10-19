/*
 * CursorList.h
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */

#include <stdio.h>
#include "CursorIterator.h"
#ifndef CURSORLIST_H_
#define CURSORLIST_H_


template <class T> // Type T for CursorList template!

class CursorList {

public:

	typedef T value_type;
	typedef  CursorIterator <T> iterator;
	int arraySize = 20;
	T arrayList[arraySize][2];

	int data = 0;
	int prev = 1;
	int next = 2;
	int start_free;		// Start der freien Liste im Array.
	int start_list;		// Start der CursorListe im Array.

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

	}

	iterator begin() const {

		return arrayList[start_list][data];
	}

	iterator end() const;

	//insert befor itr
	iterator instert(iterator itr, const T& value) {
		//vorheriges next ändern;
		//diesem element prev ändern!
	}
	iterator erase(iterator start, iterator stop);	//stop exclusive
	iterator erase(iterator itr);					//return ++itr

	virtual ~CursorList();
};

#endif /* CURSORLIST_H_ */
