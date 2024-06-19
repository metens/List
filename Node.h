
/* Author: Nathan Metens
 *
 * This is the Node class that holds the data
 * and a pointer to the next node. The methods
 * are constructors, a destructor, setters, 
 * and getters for the data.
 */

#pragma once
#include "Error.h"

template <class TYPE>
class Node {
	public:
		typedef Node<TYPE>* node_ptr;

		Node();
		Node(TYPE data);
		~Node();

		TYPE &getData();
		void setData(TYPE data);

		node_ptr &getNext();
		void setNext(node_ptr &next);
		
	private:
		TYPE data;
		node_ptr next;
};

#include "Node.tpp"
