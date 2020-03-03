#include "String.h"

#include <ctype.h>
#include <locale>

String::String()
{
	
}

String::String(const String& obj)
{
	m_buffer = (char*)malloc(obj.size() + 1);
	if (m_buffer == 0)
		throw std::runtime_error("Nullptr exception in String::String(const String&)");
	memset(m_buffer, 0, obj.size() + 1);
	memcpy(m_buffer, obj.m_buffer, obj.size());
}

String& String::operator=(const String& obj)
{
	m_buffer = (char*)malloc(obj.size() + 1);
	if (m_buffer == 0)
		throw std::runtime_error("Nullptr exception in String::String(const String&)");
	memset(m_buffer, 0, obj.size() + 1);
	memcpy(m_buffer, obj.m_buffer, obj.size());

	return *this;
}

String::String(char const* str)
{
	if (str == 0)
		return;

	int iSize = strlen(str);

	if (iSize < 1)
		return;

	m_buffer = (char*)malloc(iSize + 1);
	if (m_buffer == 0)
		throw std::runtime_error("Nullptr exception in String::String(char const*)");
	memset(m_buffer, 0, iSize + 1);
	memcpy(m_buffer, str, iSize);

}

String::~String()
{
	free(m_buffer);
}

size_t String::size() const
{
	if (m_buffer == 0)
		return 0;

	return strlen(m_buffer);
}

bool String::empty() const
{
	return this->size() < 1;
}

String String::substr(int start, int length) const
{
	if (length == -1)
		length = (this->size()) - start;

	/* Create temporary buffer */
	char* buffer = (char*)malloc(length + 1);
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::substr(int,int)");
	memset(buffer, 0, length + 1);
	memcpy(buffer, m_buffer + start, length);

	String obj(buffer);
	free(buffer);
	return obj;
}

bool String::compare(String const& obj) const
{
	if (this->size() != obj.size())
		return false;

	for (size_t index = 0; index < this->size(); ++index)
	{
		if (this->m_buffer[index] != obj.m_buffer[index])
			return false;
	}

	return true;
}

String String::lower() const
{
	char* buffer = (char*)malloc(this->size() + 1); /* Create temporary buffer */
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::lower()");
	memset(buffer, 0, this->size() + 1);

	for (size_t index = 0; index < this->size(); ++index)
	{
		buffer[index] = _Tolower(m_buffer[index], 0);
	}

	String str(buffer);
	free(buffer);
	return str;
}

String String::upper() const
{
	char* buffer = (char*)malloc(this->size() + 1); /* Create temporary buffer */
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::lower()");
	memset(buffer, 0, this->size() + 1);

	for (uint64_t index = 0; index < this->size(); ++index)
	{
		buffer[index] = _Toupper(m_buffer[index], 0);
	}
	
	String str(buffer);
	free(buffer);
	return str;
}

void String::replace_one(String const& to_replace, String const& NewString)
{
	if (this->find(to_replace) == -1)
		return;


	int new_size = (this->size() - to_replace.size()) + NewString.size();

	char* buffer = (char*)malloc(new_size + 1);
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::replace_one(String const&, String const&)");
	memset(buffer, 0, new_size + 1);

	memcpy(buffer, m_buffer, this->find(to_replace));

	if(!NewString.empty())
		strcat(buffer + this->find(to_replace), NewString.c_str());
	strcat(buffer + this->find(to_replace) + NewString.size(), m_buffer + this->find(to_replace) + to_replace.size());

	free(m_buffer);
	m_buffer = buffer;
}

void String::replace(String const& to_replace, String const& NewString)
{

	while (this->find(to_replace) != -1)
	{
		this->replace_one(to_replace, NewString);
	}
}

size_t String::find(String const& to_find, int start_pos) const
{
	if (this->size() < to_find.size())
		return -1;


	for (size_t index = start_pos; index < this->size(); ++index)
	{
		if (memcmp(m_buffer + index, to_find.c_str(), to_find.size()) == 0)
		{
			return index;
		}
	}

	return -1;
}

size_t String::find_last(String const& to_find, int start_pos) const
{
	size_t pos = start_pos;
	size_t lpos = start_pos;
	while (this->find(to_find, pos) != -1) {
		lpos = this->find(to_find, pos);
		++pos;
	}

	return lpos;
}

char const* String::c_str() const
{
	return (char const*)m_buffer;
}

std::vector<String> String::split(String const& delimiter) const
{
	std::vector<String> Strings;

	size_t prev = 0, pos = 0;
	do
	{
		pos = this->find(delimiter, prev);
		if (pos == -1) pos = this->size();
		String token = this->substr(prev, pos - prev);
		if (!token.empty())
			Strings.push_back(token);
		prev = pos + delimiter.size();
	} while (pos < this->size() && prev < this->size());

	return Strings;
}

String String::getline(std::istream& is, const char& end) const
{
	int bufsize = 1024;

	char* buffer = (char*)malloc(bufsize + 1);
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::getline(std::istream&, const char&)");
	memset(buffer, 0, bufsize + 1);

	String retvalue;

	while (true)
	{
		is.get(buffer, bufsize);

		for (unsigned int index = 0; index < strlen(buffer); ++index)
		{
			if (buffer[index] == end) {

				buffer[index + 1] = 0;
			}
		}

		if (strlen(buffer) > 1) {
			retvalue.append(buffer);
		}
		else
			break;

	}
	return retvalue;
}

bool String::is_number() const
{
	for (unsigned int index = 0; index < this->size(); ++index)
	{
		if(!std::isdigit(m_buffer[index], std::locale()))
			return false;
	}

	return true;
}

void String::append(String const& obj)
{
	char* buffer = (char*)malloc(this->size() + obj.size() + 1);
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::append(String const&)");
	memset(buffer, 0, this->size() + obj.size() + 1);

	memcpy(buffer, m_buffer, this->size());
	strcat(buffer + this->size(), obj.m_buffer);

	free(m_buffer);
	m_buffer = buffer;
}

void String::append(char c)
{
	char buf[2] = { c, 0 };
	this->append((char const*)&buf);
}

void String::pop_back()
{
	char* buffer = (char*)malloc(this->size());
	if (buffer == 0)
		throw std::runtime_error("Nullptr exception in String::pop_back");
	memset(buffer, 0, this->size());
	memcpy(buffer, m_buffer, this->size() - 1);

	free(m_buffer);
	m_buffer = buffer;
}

bool String::operator==(String const& obj) const
{
	return this->compare(obj);
}

bool String::operator!=(String const& obj) const
{
	return !this->compare(obj);
}

bool String::operator<(String const& obj) const
{
	return this->size() < obj.size();
}

bool String::operator<=(String const& obj) const
{
	return this->size() <= obj.size();
}

bool String::operator>(String const& obj) const
{
	return this->size() > obj.size();
}

bool String::operator>=(String const& obj) const
{
	return this->size() >= obj.size();
}

String String::operator*(size_t times) const
{
	String str;

	for (size_t index = 0; index < times; ++index)
	{
		str.append(*this);
	}

	return str;
}

void String::operator*=(size_t times)
{
	if (times > 1)
		--times;

	String original(m_buffer);
	for (int index = 0; index < times; ++index)
	{
		this->append(original);
	}
}

String String::operator+(String const& obj) const
{
	String NewString(m_buffer);
	NewString.append(obj);

	return NewString;
}

void String::operator+=(String const& obj)
{
	this->append(obj);
}

bool String::operator!() const
{
	return this->empty();
}

String::operator std::string() const
{
	return std::string(m_buffer);
}

std::ostream& operator<<(std::ostream& outstream, String const& obj)
{
	outstream << obj.m_buffer;
	return outstream;
}
