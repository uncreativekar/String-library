#include <iostream>

#include "String.h"

int main()
{
	String name = "Andy";

	if (!name)
	{
		printf("No name!\n");
	}
	else
	{
		printf("%s\n", name.c_str());
	}

	std::string(name);
}