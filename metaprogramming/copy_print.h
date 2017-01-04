#ifndef COPY_PRINT_H_
#define COPY_PRINT_H_

#include <iostream>
#include <string>

template<size_t NUM>
void copyPrint(const std::string& str)
{
	for(auto i=0; i<NUM; i++)
	{
		std::cout << str << std::endl;
	}
}

/** Usage:
* copyPrint<3>(someString);      <- prints 3 times someString
*/

#endif
