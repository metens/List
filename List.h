
/* Author: Nathan Metens
 *
 * This is the List class header file.
 * The implementation file is included
 * at the bottom which holds all the 
 * methods in this class.
 */

#pragma once
#include "Node.h"
#include <iostream>
using std::cout;
using std::ostream;

template<class TYPE>
class List {
	public:
		typedef Node<TYPE>* node_ptr;
		List();
		List(const List &srcList);
		~List();
		List &operator=(const List &srcList);

		void insert(TYPE &data);
		void display() const;

		template <typename T>
		friend ostream &operator<<(ostream &out, const List<T> &list);
		TYPE &operator[](const int &index);

	private:
		node_ptr head;

		void copy(node_ptr &head, node_ptr srcHead);
		void deleteList(node_ptr &head);
		void insert(TYPE &data, node_ptr &head);
		void display(node_ptr head) const;
};

#include "List.tpp"

template <typename T>
ostream &operator<<(ostream &out, const List<T> &list) {
	list.display();
	return out;
}
