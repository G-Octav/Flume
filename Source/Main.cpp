#include "Application.hpp"
#include <iostream>

int main() 
{
	try
	{
		Application Flume;
		Flume.run();
	}
	catch(std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	return EXIT_SUCCESS;
}