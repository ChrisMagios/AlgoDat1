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

template<class T>
class CursorIterator;

template<class T>
class CursorElement;

using namespace std;
template <class T> // Type T for CursorList template!

class CursorList {
	typedef T value_type;
	typedef CursorIterator<T> iterator;

	private:
		using entry = std::tuple<T,int,int>; // Tupel aus (T, prev, next)
		entry entryList[20];
		int data = 0;
		int prev = 1;
		int next = 2;
		int start_free;		// Start der freien Liste im Array.
		int start_list;		// Start der CursorListe im Array.
	public:

		// Konstructor
		CursorList();

		virtual ~CursorList();

		//Innere Klasse Cursor Iterator!!
		class CursorIterator {

		private:
			int cursorIndex = 0;
			CursorList<T> cursorList;
		public:

			CursorIterator() {

			}

			CursorIterator(CursorList<T>& list) {
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

			iterator& operator =(const iterator& rhs) {
				this->cursorIndex = rhs.cursorIndex;
				this->cursorList = rhs.cursorList;
				return this;
			}

			bool operator !=(const iterator& rhs) const {
				return *this != *rhs;
			}
			bool operator ==(const iterator& rhs) const {
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

// Anfang Member Methoden Cursor Iterator!

// Getters und Setters

		int getStart_list() {
			return start_list;
		}

		int getStart_free() {
			return start_free;
		}

		int getNextElement(int index) {
			int i = std::get<2>(entryList[index]);
			return entryList[i]; // Bisher wird das Tupel zurückgegeben

		}

		int getPrevElement(int index) {
			int i = std::get<1>(entryList[index]);
			return entryList[i]; // Bisher wird das Tupel zurückgegeben
		}

		T getListElement(int index) {
			return std::get<0>(entryList[index]); // gibt den eintrage an der ersten Stelle des Tupels wieder
		}										// dabei handelt es sich um <T>

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
			return entryList[start_list];

		}

		//füge neues.
		void push_front(const T& t) {
			if (!empty()) {
				std::get<0>(entryList[start_free]) = t;
				std::get<2>(entryList[start_free]) = start_list;
				std::get<1>(entryList[start_list]) = start_free;
				//arrayList[start_free][data] = t;
				//arrayList[start_free][next] = start_list;	// Setze Nachfolger des neuen ersten Elements.
				//arrayList[start_list][prev] = start_free;	// Setze Vorgänger des alten ersten Elements.

				//start_list = start_free;
				//start_free = arrayList[start_free][next];	// Neuer freier Listen anfang.
			}
		}

		void pop_front() {
			if (!empty()) {

			}
		}

		iterator begin() const {

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
