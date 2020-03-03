#pragma once

#include <iostream>

#include <vector>
#include <string>

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
	size_t size() const;

	/* returns true if the string is empty */
	bool empty() const;

	/* Substring function, returns part of string */
	String substr(int start, int length = -1) const;

	/* Compare function, returns true if the strings are equal */
	bool compare(String const& obj) const;

	/* returns lowercase string */
	String lower() const;

	/* returns uppercase string */
	String upper() const;

	/* replaces one occurrence of string */
	void replace_one(String const& to_replace, String const& NewString);

	/* replaces all occurrences of string */
	void replace(String const& to_replace, String const& NewString);

	/* returns the position of first occurence in string*/
	size_t find(String const& to_find, int start_pos = 0) const;

	/* returns the position of last found occurence in string*/
	size_t find_last(String const& to_find, int start_pos = 0) const;

	/* Returns the underlying string buffer */
	char const* c_str() const;

	/* Split function, returns vector of strings */
	std::vector<String> split(String const& delimiter) const;

	/* to_number function template */
	template <typename T>
	T to_number(unsigned int base = 10) const
	{
		return std::stoi(std::string(m_buffer),0, base);
	}

	/* to_number double function template */
	template <>
	double to_number(unsigned int base) const
	{
		return std::stod(std::string(m_buffer));
	}

	/* to_number unsigned int function */
	template <>
	unsigned long to_number(unsigned int base) const
	{
		return std::stoul(std::string(m_buffer), 0, base);
	}

	/* to_number long long short function */
	template <>
	long long to_number(unsigned int base) const
	{
		return std::stoll(std::string(m_buffer), 0, base);
	}

	/* to_number function template */
	template <>
	unsigned long long to_number(unsigned int base) const
	{
		return std::stoull(std::string(m_buffer), 0, base);
	}

	/* Append function */
	void append(String const& obj);

	/* Append function overloaded */
	void append(char c);

	/* Pops back character */
	void pop_back();

	/* LShift operator overload */
	friend std::ostream& operator<<(std::ostream& outstream, String const& obj);

	/* Comparison operator */
	bool operator==(String const& obj) const;

	/* Comparison operator */
	bool operator!=(String const& obj) const;

	/* Comparison operator */
	bool operator<(String const& obj) const;

	/* Comparison operator */
	bool operator<=(String const& obj) const;

	/* Comparison operator */
	bool operator>(String const& obj) const;

	/* Comparison operator */
	bool operator>=(String const& obj) const;

	/* Mathematic operators */
	String operator*(size_t times) const;

	/* Mathematic operator */
	void operator*=(size_t times);

	/* Mathematic operator */
	String operator+(String const& obj) const;

	/* Mathematic operator */
	void operator+=(String const& obj);

	/* Boolean operator */
	bool operator!() const;

	/* std::string cast */
	operator std::string() const;
private:
	char* m_buffer = 0;

};

