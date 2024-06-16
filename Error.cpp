
/* Author: Nathan Metens
 *
 * This is the implementation file for the
 * Error class.
 */

#include "Error.h"
#include <iostream>
using std::cout;
using std::endl;

Error::Error(): message("") {}

Error::Error(String errorMessage): message(errorMessage) {}

void Error::display() const {
	String red = "\033[31m";
	String reset = "\033[0m";
	cout << red << message << reset << endl;
}
