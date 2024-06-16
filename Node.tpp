
/* Author: Nathan Metens
 *
 * This is the implementation of the 
 * Node class methods:
 */

template <typename TYPE>
Node<TYPE>::Node(): data(0), next(nullptr) {}

template <typename TYPE>
Node<TYPE>::Node(TYPE data): data(data), next(nullptr) {}
	
template <typename TYPE>
Node<TYPE>::~Node() {
	data = 0;
	if (next) next = nullptr;
}

template <typename TYPE>
TYPE &Node<TYPE>::getData() { return data; }
	
template <typename TYPE>
void Node<TYPE>::setData(TYPE data) { this->data = data; }

template <typename TYPE>
Node<TYPE>* &Node<TYPE>::getNext() { return next; }
	
template <typename TYPE>
void Node<TYPE>::setNext(Node<TYPE>* &next) { this->next = next; }
