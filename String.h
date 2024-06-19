
/* Author: Nathan Metens
 *
 * This is the string header file.
 * The data in the string class 
 * consists of a pointer to a char,
 * and the length of the string.
 * Basic assignment and concat methods
 * are also implemented to simulate
 * the STL string class.
 */

#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class String {
	public:
		String();
		String(const char* string);
		String(const String &string);
		~String();

		String &operator=(const String &string);
		String &operator=(const char* string);

		String &operator+=(const String &string);
		String &operator+=(const char* string);

		friend ostream &operator<<(ostream &out,
				const String &string);
		friend istream &operator>>(istream &in,
				String &string);

		String operator+(const String &string);
		String operator+(const char* string);
		friend String operator+(const char* string1,
				const String &string2);
	private:
		char* str;
		int len;
};
