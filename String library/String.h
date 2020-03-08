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

	/* get function */
	String getline(std::istream& is, const char& end = '\n') const;

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

	/* returns true if all characters are numbers */
	bool is_number() const;

	/* Append function */
	void append(String const& obj);

	/* Append function overloaded */
	void append(char c);

	/* Pops back character */
	void pop_back();

	/* LShift operator overload */
	friend std::ostream& operator<<(std::ostream& outstream, String const& obj);

	/* returns true if strings are equal */
	bool operator==(String const& obj) const;

	/* returns true if string are not equal  */
	bool operator!=(String const& obj) const;

	/* returns true if other string is less */
	bool operator<(String const& obj) const;

	/* returns true if other string is less or equal size */
	bool operator<=(String const& obj) const;

	/* retuns true if string is larger size than other string */
	bool operator>(String const& obj) const;

	/* returns true if string is larger or equal size to other string */
	bool operator>=(String const& obj) const;

	/* multiplies string by times */
	String operator*(size_t times) const;

	/* multiplies string by times */
	void operator*=(size_t times);

	/* appends other string */
	String operator+(String const& obj) const;

	/* appends other string */
	void operator+=(String const& obj);

	/* returns true if string is empty */
	bool operator!() const;

	/* std::string cast */
	operator std::string() const;
private:
	char* m_buffer = 0;

};


class wString
{
public:
	/* Constructor */
	wString();

	/* Copy constructor */
	wString(const wString& obj);

	/* Assignment operator */
	wString& operator=(const wString& obj);

	/* Constructor */
	wString(wchar_t const* str);

	/* Destructor */
	~wString();

	/* returns the size of the string, ends on null terminator */
	size_t size() const;

	/* returns true if the string is empty */
	bool empty() const;

	/* Substring function, returns part of string */
	wString substr(int start, int length = -1) const;

	/* Compare function, returns true if the strings are equal */
	bool compare(wString const& obj) const;

	/* returns lowercase string */
	wString lower() const;

	/* returns uppercase string */
	wString upper() const;

	/* replaces one occurrence of string */
	void replace_one(wString const& to_replace, wString const& NewString);

	/* replaces all occurrences of string */
	void replace(wString const& to_replace, wString const& NewString);

	/* returns the position of first occurence in string*/
	size_t find(wString const& to_find, int start_pos = 0) const;

	/* returns the position of last found occurence in string*/
	size_t find_last(wString const& to_find, int start_pos = 0) const;

	/* Returns the underlying string buffer */
	wchar_t const* c_str() const;

	/* Split function, returns vector of strings */
	std::vector<wString> split(wString const& delimiter) const;

	/* get function */
	wString getline(std::wistream& is, const wchar_t& end = '\n') const;

	/* to_number function template */
	template <typename T>
	T to_number(unsigned int base = 10) const
	{
		return std::stoi(std::wstring(m_buffer), 0, base);
	}

	/* to_number double function template */
	template <>
	double to_number(unsigned int base) const
	{
		return std::stod(std::wstring(m_buffer));
	}

	/* to_number unsigned int function */
	template <>
	unsigned long to_number(unsigned int base) const
	{
		return std::stoul(std::wstring(m_buffer), 0, base);
	}

	/* to_number long long short function */
	template <>
	long long to_number(unsigned int base) const
	{
		return std::stoll(std::wstring(m_buffer), 0, base);
	}

	/* to_number function template */
	template <>
	unsigned long long to_number(unsigned int base) const
	{
		return std::stoull(std::wstring(m_buffer), 0, base);
	}

	/* returns true if all characters are numbers */
	bool is_number() const;

	/* Append function */
	void append(wString const& obj);

	/* Append function overloaded */
	void append(wchar_t c);

	/* Pops back character */
	void pop_back();

	/* LShift operator overload */
	friend std::wostream& operator<<(std::wostream& outstream, wString const& obj);

	/* returns true if strings are equal */
	bool operator==(wString const& obj) const;

	/* returns true if string are not equal  */
	bool operator!=(wString const& obj) const;

	/* returns true if other string is less */
	bool operator<(wString const& obj) const;

	/* returns true if other string is less or equal size */
	bool operator<=(wString const& obj) const;

	/* retuns true if string is larger size than other string */
	bool operator>(wString const& obj) const;

	/* returns true if string is larger or equal size to other string */
	bool operator>=(wString const& obj) const;

	/* multiplies string by times */
	wString operator*(size_t times) const;

	/* multiplies string by times */
	void operator*=(size_t times);

	/* appends other string */
	wString operator+(wString const& obj) const;

	/* appends other string */
	void operator+=(wString const& obj);

	/* returns true if string is empty */
	bool operator!() const;

	/* std::string cast */
	operator std::wstring() const;
private:
	wchar_t* m_buffer = 0;

};