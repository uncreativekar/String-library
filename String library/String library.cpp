#include <iostream>

#include "String.h"

int main()
{
	String name("Andy fuck :)");

	name.replace("fuck", "");



	printf("Name: %s\n", name.c_str());
}