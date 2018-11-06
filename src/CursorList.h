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
<<<<<<< HEAD
#include <tuple>
=======

>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043
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

<<<<<<< HEAD

	using entry = std::tuple<T,int,int>; // Tupel aus (T, prev, next)
	entry entryList [20];


	int data = 0;
	int prev = 1;
	int next = 2;
	int start_free;		// Start der freien Liste im Array.
	int start_list;		// Start der CursorListe im Array.
=======
				}
>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043

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
<<<<<<< HEAD

		int i = std::get<2>(entryList[index]);
		return entryList[i]; // Bisher wird das Tupel zurückgegeben
=======
		return arrayList[index];
>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043
	}


	int getPrevElement(int index) {
<<<<<<< HEAD
		int i = std::get<1>(entryList[index]);
		return entryList[i]; // Bisher wird das Tupel zurückgegeben
=======
		return arrayList[index];
>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043
	}


	T getListElement(int index) {
<<<<<<< HEAD
		return std::get<0>(entryList[index]); 	// gibt den eintrage an der ersten Stelle des Tupels wieder
	}											// dabei handelt es sich um <T>
=======
		return arrayList[index];
	}
>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043


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
<<<<<<< HEAD
		return entryList[start_list];
		// return arrayList[start_list][data];
=======
		return *arrayList[start_list];
>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043
	}

	//füge neues.
	void push_front(const T& t) {
		if (!empty()) {
<<<<<<< HEAD

			std::get<0>(entryList[start_free]) = t;
			std::get<2>(entryList[start_free]) = start_list;
			std::get<1>(entryList[start_list]) = start_free;

			//arrayList[start_free][data] = t;
			//arrayList[start_free][next] = start_list;	// Setze Nachfolger des neuen ersten Elements.
			//arrayList[start_list][prev] = start_free;	// Setze Vorgänger des alten ersten Elements.

			//start_list = start_free;
			//start_free = arrayList[start_free][next];	// Neuer freier Listen anfang.
=======
			CursorElement tmp = arrayList[start_free];
			tmp.setElement(t);
			tmp.setNext(start_list);
			tmp = arrayList[start_list];
			tmp.setPrev(start_free);
			start_list = start_free;
			start_free = tmp.getNext();	// Neuer freier Listen anfang.
>>>>>>> 0698abddd07046869f6e02a5181ab232342e5043
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
