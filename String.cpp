
#include "String.h"
#include <cstring>

String::String(): str(nullptr), len(0) {}
String::String(const char* string): str(nullptr), len(strlen(string)) {
	str = new char[len + 1];
	strcpy(str, string);
}
String::String(const String &string): str(nullptr), len(string.len) {
	str = new char[len + 1];
	strcpy(str, string.str);
}
String::~String() {
	if (str) delete [] str;
	str = nullptr;
	len = 0;
}
String &String::operator=(const String &string) {
	if (this != &string) {
		len = string.len;
		if (str) delete [] str;
		str = new char[len + 1];
		strcpy(str, string.str);
	}
	return *this;
}
String &String::operator=(const char* string) {
	if (strcmp(str, string) != 0) {
		len = strlen(string);
		if (str) delete [] str;
		str = new char[len + 1];
		strcpy(str, string);
	}
	return *this;
}

String &String::operator+=(const String &string) {
	// Copy this str:
	String temp;
	temp.len = len;
	temp.str = new char[len + 1];
	if (str) strcpy(temp.str, str);

	// Concatinate temp and string to this str:
	len = len + string.len;
	if (str) delete [] str;
	str = new char[len + 1];
	strcpy(str, temp.str);
	strcat(str, string.str);
	return *this;
}
String &String::operator+=(const char* string) {
	String temp;
	temp.len = len;
	temp.str = new char[len + 1];
	if (str) strcpy(temp.str, str);

	len = len + strlen(string);
	if (str) delete [] str;
	str = new char[len + 1];
	strcpy(str, temp.str);
	strcat(str, string);
	return *this;
}

ostream &operator<<(ostream &out, const String &string) {
	out << string.str;
	return out;
}
istream &operator>>(istream &in, String &string) {
	char newString[100];
	in.getline(newString, 100);
	in.clear();
	if (string.str) delete [] string.str;
	string.len = strlen(newString);
	string.str = new char[string.len + 1];
	strcpy(string.str, newString);
	return in;
}
String String::operator+(const String &string) {
	String temp;
	temp.len = this->len + string.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, this->str);
	strcat(temp.str, string.str);
	return temp;
}
String String::operator+(const char* string) {
	String temp;
	temp.len = this->len + strlen(string);
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, this->str);
	strcat(temp.str, string);
	return temp;	
}
String operator+(const char* string1, const String &string2) {
	String temp;
	temp.len = strlen(string1) + string2.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, string1);
	strcat(temp.str, string2.str);
	return temp;
}

