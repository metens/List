
/* Author: Nathan Metens
 *
 * This is the main file that runs tests for
 * the List class.
 */

#include "List.h"
#include "String/String.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	List<int> list;

	int arr[7] = {3, 5, 2, 9, 4, 1, 8};
	for (int i=0; i<7; ++i)
		list.insert(arr[i]);

	cout << list;

	List<int> list2(list);
	cout << list2;

	String name = "Nathan";
	cout << name << endl;
	String asdf = "asdf";
	cout << asdf << endl;
	name = asdf;
	asdf = "Metens";
	cout << name << endl;
	String name2(asdf);
	cout << name2 << endl;

	String nathan = "Nathan " + name2;
	String leah = asdf + " Leah";
	cout << nathan << endl;
	cout << leah << endl;
	String names = nathan + leah;
	cout << names << endl;

	try {
		cout << "List[6]: " << list[6] << endl;
	} catch(Error e) {
		e.display();
	}

	return 0;
}
