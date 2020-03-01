#include "String.h"


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

int String::size() const
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

char const* String::c_str() const
{
	return (char const*)m_buffer;
}
