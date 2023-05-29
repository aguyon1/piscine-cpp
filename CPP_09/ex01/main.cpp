#include "RPN.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		try
		{
			std::cout << rpn(av[1]) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	return (0);
}
