#include <iostream>

int main()
{    
	int x = 1000;
	int* p = &x;

	unsigned char* c = reinterpret_cast<unsigned char*>(p);
	std::cout << static_cast<int>(*c) << std::endl;
	std::cout << static_cast<int>(*(c+1)) << std::endl;
	std::cout << static_cast<int>(*(c+2)) << std::endl;
	std::cout << static_cast<int>(*(c+3)) << std::endl;


    return 0;
}
