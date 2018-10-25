/*
 * CursorIterator.h
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */


#ifndef CURSORITERATOR_H_
#define CURSORITERATOR_H_

#include "CursorList.h"

template <typename Iterator, typename T> Iterator find(Iterator start, Iterator stop, const T& value) {};
template <class T>
class CursorIterator {
	typedef CursorIterator<T> iterator;

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


#endif /* CURSORITERATOR_H_ */
