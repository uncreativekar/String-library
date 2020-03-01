#include <iostream>

#include "String.h"

int main()
{
	String str("Hey Andy");

	String subStr = str.substr(4, 4);

	printf("str: %s\n", subStr.c_str());
}