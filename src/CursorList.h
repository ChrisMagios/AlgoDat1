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

template <class T>
class CursorIterator;

template <class T>
class CursorElement;

using namespace std;
template <class T> // Type T for CursorList template!

class CursorList {
	typedef T value_type;
	typedef  CursorIterator<T> iterator;

	//Innere Klasse CursorElement, für die Verwaltung der normalen und der FreeList;
		class CursorElement {
			private:
				int* mPrev = nullptr;
				int* mNext = nullptr;
				T mElement;
			public:

				CursorElement() {

				}

				CursorElement(int prev, int next , T& element) {
					mPrev =prev;
					mNext = next;
					mElement = element;
				}

				int getNext() {
					return this->mNext;
				}

				int getPrev() {
					return this->mPrev;
				}


				virtual ~CursorElement();

			T getElement() const {
				return mElement;
			}

			void setElement(T element) {
				mElement = element;
			}

			void setNext(int next = nullptr) {
				mNext = next;
			}

			void setPrev(int prev = nullptr) {
				mPrev = prev;
			}
		};

		//Innere Klasse Cursor Iterator!!
			class CursorIterator {

				private:
					int cursorIndex = 0;
					CursorList <T> cursorList;
				public:

					CursorIterator() {

					}

					CursorIterator( CursorList <T>& list ) {
						cursorList = list;
						cursorIndex = cursorList.getStart_list();
					}

					CursorList<T> getCursorList() {
						return this->cursorList;
					}

					int getCursorIndex() {
						return this->cursorIndex;
					}

					T& operator *() {
						return this->cursorList.getListElement(cursorIndex);
					}

					iterator& operator = (const iterator& rhs) {
						this->cursorIndex = rhs.cursorIndex;
						this->cursorList = rhs.cursorList;
						return this;
					}

					bool operator != (const iterator& rhs) const {
						return *this != *rhs;
					}
					bool operator == (const iterator& rhs) const {
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


private:
	const int length = 20;
	CursorElement arrayList[20];
	int start_free;		// Start der freien Liste im Array.
	int start_list;		// Start der CursorListe im Array.

public:

	// Konstructor
	CursorList();

	virtual ~CursorList();


// Anfang Member Methoden Cursor Iterator!


// Getters und Setters

	int getStart_list() {
		return start_list;
	}

	int getStart_free() {
			return start_free;
	}

	int getNextElement(int index) {
		return arrayList[index];
	}

	int getPrevElement(int index) {
		return arrayList[index];
	}


	T getListElement(int index) {
		return arrayList[index];
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
		return *arrayList[start_list];
	}

	//füge neues.
	void push_front(const T& t) {
		if (!empty()) {
			CursorElement tmp = arrayList[start_free];
			tmp.setElement(t);
			tmp.setNext(start_list);
			tmp = arrayList[start_list];
			tmp.setPrev(start_free);
			start_list = start_free;
			start_free = tmp.getNext();	// Neuer freier Listen anfang.
		}
	}

	void pop_front() {
		if (!empty()) {

		}
	}



	iterator begin() const {
		return new iterator(arrayList);
	}

	iterator end() const {


	}

	//insert befor itr
	iterator instert(iterator itr, const T& value) {
		//vorheriges next ändern;
		//diesem element prev ändern!
	}
	iterator erase(iterator start, iterator stop);	//stop exclusive
	iterator erase(iterator itr);					//return ++itr

	void initList() {

	}




};

#endif /* CURSORLIST_H_ */
