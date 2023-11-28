/***************************************************************************
 *   Copyright (C) 2016 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"
#include <iostream>

template<class T>
class Linked_list;

template< class T >
class List_node{
	friend class Linked_list<T>;
 private:
	T _value;
	List_node<T> * _pPrev;
	List_node<T> * _pNext;

 public:
 	static void swap_node(List_node< T >*);
	bool operator<(const List_node<T> &);
	bool operator>(const List_node<T> &);
	bool operator<=(const List_node<T> &);
	List_node<T>& operator=(const List_node<T> &);
};


template< class T>
bool List_node<T>::operator<(const List_node<T> & To_compare){
	bool greaterthan = ( this._pvalue < To_compare->_value)? 1 : 0;
	return greaterthan;
}

template< class T>
bool List_node<T>::operator>(const List_node<T> & To_compare){
	bool lessthan = ( this._pvalue > To_compare->_value)? 1 : 0;
	return lessthan;
}

template< class T>
bool List_node<T>::operator<=(const List_node<T> & To_compare){
	bool lessOrEqualthan = ( this._pvalue <= To_compare->_value)? 1 : 0;
	return lessOrEqualthan;
}

template< class T>
List_node<T>& List_node<T>::operator=(const List_node<T> & To_compare){
	this->_value = To_compare._value;
	return *this;
}

template <class T>
void List_node<T>::swap_node(List_node<T> *toinvert)
{
    List_node< T > * temp;

	temp = toinvert->_pNext;
	toinvert->_pNext = toinvert->_pPrev;
	toinvert->_pPrev = temp;
}

template< class T >
class Linked_list : public Linear_list<T, List_node<T>*>{
 public:
	
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_node<T>*>::position position;

	// costruttori
	Linked_list();
	Linked_list(int);
	// costruttore per copia
	Linked_list(const Linked_list<T>& );
	//distruttore
	~Linked_list();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	int length() const;
    void insert(const value_type &, position);
	void push_back(const value_type &);
	void push_front(const value_type &);
	void erase(position);
	Linked_list< T >* reverse();
    bool isPalindrome();
    bool swap_next(position p);

    int size() const {
		return _length;
	};

	// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
	bool operator==(const Linked_list<T> &) const; // tests two list for equality

 private:
	
	List_node<T> * _pHead;
	int _length; // the length of the list
};

template< class T >
Linked_list< T >::Linked_list() {
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
};


template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) {
    _length = L.size();

	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

	if (!L.empty()){
		position p = L.last();
		for (int i=0; i <= L._length; i++){
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
};


template< class T >
Linked_list< T >::~Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
};

template< class T >
void Linked_list< T >::create(){
	if (empty())
			_length = 0;
};

template< class T >
bool Linked_list< T >::empty() const {
	return(_pHead == _pHead->_pNext);
};

template< class T >
typename Linked_list< T >::position
Linked_list< T >::begin() const {
	return (_pHead->_pNext);
};

template< class T >
typename Linked_list< T >::position
Linked_list< T >::last() const {
	return (_pHead->_pPrev);
};


template< class T >
typename Linked_list< T >::position
Linked_list< T >::next(position p) const {
	return(p->_pNext);
};

template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const {
	if (p != _pHead)
		return(p->_pPrev);
	else
		return NULL;
};

template< class T >
bool Linked_list< T >::end(position p) const {
	return(p == _pHead);
};

template< class T >
typename Linked_list< T >::value_type
Linked_list< T >::read(position p) const {
	if (!end(p))
		return(p->_value);
};

template< class T >
void Linked_list< T >::write(const value_type &a, position p) {
	if (!end(p))
        p->_value = a;
	//else
		//throw(new exception("Index out of bound"));

};

template< class T>
int Linked_list< T >::length() const{
    return _length;
};

template< class T >
void Linked_list< T >::insert(const value_type &a, position p){
	position t = new List_node<T>;
	t->_value = a;

	t->_pNext = p;
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
};

template <class T>
void Linked_list<T>::push_back(const value_type &a){
	position lastnode = this->last();
	position to_insert = new List_node<T>;

	to_insert->_value = a;

	to_insert->_pPrev = lastnode;
	lastnode->_pNext = to_insert;
	to_insert->_pNext = _pHead;
	_pHead->_pPrev = to_insert;

	_length++;
}

template <class T>
void Linked_list<T>::push_front(const value_type &a){
	position p = this->begin();
	this->insert(a, p);
}

template< class T >
void Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
		_length--;
	}
};

template< class T>
Linked_list< T >* Linked_list< T >::reverse(){
	if (!empty())
	{
		position current;
		List_node<T>::swap_node(_pHead);
		current = _pHead->_pNext;
		do
		{
			List_node<T>::swap_node(current);
			current = next(current);
		} while (!end(current));
	}
	return this;
}

template< class T>
bool Linked_list<T>::isPalindrome(){
	Linked_list<T> clone;
	clone = *this;
	clone.reverse();
	bool palindrome =(clone == *this) ? true : false;

	return palindrome;
} 

template< class T>
bool Linked_list<T>::swap_next(position p){
	if (!end(p))
	{
		T temp;
		 
	}
	
}

//OPERATORI
template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
    if (this != &L){
	
	    // deallocare tutta la lista this
	
	    while (!empty())
		{
			erase(begin());
		}
		delete _pHead;
	
		//_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
	if (L.size() != _length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
};

#endif // _LINKED_LIST_H