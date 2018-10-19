/*
 * CursorIterator.h
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */
#include "CursorList.h"
#ifndef CURSORITERATOR_H_
#define CURSORITERATOR_H_
template <typename Iterator, typename T> Iterator find(Iterator start, Iterator stop, const T& value) {};
template <class T>
class CursorIterator {
	typedef CursorIterator<T> iterator;
public:

	CursorIterator();

	T& operator *();
	iterator& operator = (const iterator& rhs);
	bool operator != (const iterator& rhs) const;
	bool operator == (const iterator& rhs) const;
	iterator& operator++();
	iterator operator ++(int);						//postfix operator, dummy parameter

	virtual ~CursorIterator();

};


#endif /* CURSORITERATOR_H_ */
