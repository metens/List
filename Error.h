
/* Author: Nathan Metens
 *
 * This is the header file for the
 * Error class used for exception
 * handling possible errors in the
 * List class.
 */

#pragma once
#include "String.h"

class Error {
	public:
		Error();
		Error(String errorMessage);
		void display() const;
	private:
		String message;
};
