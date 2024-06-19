
/* Author: Nathan Metens
 *
 * This is the main method to test the list
 * and String class methods.
 */

#include "String.h"
#include "List.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
	// Create String objects:
	//String name = "Nathan";
	String name1("Nathan");
	String name2(name1);
	String name3;
	name2 = "Metens";
	name3 = name1 + " " + name2; // Concatonate Strings

	// Outputing String objects:
	cout << "name1: " << name1 << endl;
	cout << "name2: " << name2 << endl;
	cout << "name3: " << name3 << endl;

	name3 += " Emmanuel";
	name3 += name2;
	cout << name3 << endl;

	List<String> list; // Creating a list object of type String
	// Creating a vector of String objects:
	vector<String> v = {"Moo", name1, name2, "Leah", "Sam"};
	for (auto string: v) list.insert(string); // Adding Strings to list
	cout << list << endl; // Display the list

	// Change the String at the corresponding index:
	list[1] = "NATHAN";
	list[3] = "SNIP";
	cout << list[1] << endl; // Display the object at index 1
	cout << list << endl;

	return 0;
}
