#pragma once

#include <iostream>

class String
{
public:
	/* Constructor */
	String();

	/* Copy constructor */
	String(const String& obj);

	/* Assignment operator */
	String& operator=(const String& obj);

	/* Constructor */
	String(char const* str);

	/* Destructor */
	~String();

	/* returns the size of the string, ends on null terminator */
	int size() const;

	/* returns true if the string is empty */
	bool empty() const;

	/* Substring function, returns part of string */
	String substr(int start, int length = -1) const;

	/* Returns the underlying string buffer */
	char const* c_str() const;
private:
	char* m_buffer = 0;

};

