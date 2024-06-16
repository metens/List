
/* Author: Nathan Metens
 * 
 * This is the implementation file for
 * the List class template methods:
 */

template <typename TYPE>
List<TYPE>::List(): head(nullptr) {}

template <typename TYPE>
List<TYPE>::List(const List &srcList): head(nullptr) {
	if (srcList.head) copy(head, srcList.head);
}

template <typename TYPE>
void List<TYPE>::copy(Node<TYPE>* &head, Node<TYPE>* srcHead) {
	if (!srcHead) return;
	head = new Node<TYPE>(srcHead->getData());
	copy(head->getNext(), srcHead->getNext());
}

template <typename TYPE>
List<TYPE>::~List() { if (head) deleteList(head); }

template <typename TYPE>
void List<TYPE>::deleteList(node_ptr &head) {
	while (head) {
		Node<TYPE>* next = head->getNext();
		delete head;
		head = next;
	}
}

template <typename TYPE>
List<TYPE> &List<TYPE>::operator=(const List &srcList) {
	if (this != &srcList) {
		if (head) deleteList(head);
		copy(head, srcList.head);
	}
	return *this;
}

template <typename TYPE>
void List<TYPE>::insert(TYPE &data) { insert(data, head); }

template <typename TYPE>
void List<TYPE>::insert(TYPE &data, Node<TYPE>* &head) {
	if (!head) {
		head = new Node<TYPE>(data);
		return;
	}
	insert(data, head->getNext());
}

template <typename TYPE>
void List<TYPE>::display() const { display(head); cout << "\n"; }

template <typename TYPE>
void List<TYPE>::display(Node<TYPE>* head) const {
	if (!head) return;
	cout << head->getData() << " ";
	display(head->getNext());
}

template <typename TYPE>
TYPE &List<TYPE>::operator[](const int &index) {
	if (index < 0)
		throw(Error("Invalid index."));
	int count = 0;
	Node<TYPE>* curr = head;
	while (count != index && curr) {
		curr = curr->getNext();
		++count;
	}
	if (count != index)
		throw(Error("Index out of range."));
	return curr->getData();
}
