/*
 * CursorList.cpp
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */
#include "CursorList.h"
#include "Student.h"
template <class T>
CursorList<T>::CursorList() {
	CursorList::start_free = 0;
	CursorList::start_list = 0;
}

template <class T>
CursorList<T>::~CursorList(){

}
