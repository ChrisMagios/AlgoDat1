/*
 * CursorList.cpp
 *
 *  Created on: 15.10.2018
 *      Author: Chris
 */
#include "CursorList.h"
#include "Student.h"
template<class T, unsigned int SIZE>
CursorList<T, SIZE>::CursorList() {
	start_free = 0;
	start_list = 0;
}

template<class T, unsigned int SIZE>
CursorList<T, SIZE>::~CursorList() {

}
