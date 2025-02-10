#include <iostream>

int main()
{    
	int x = 1000;
	int* p = &x;

	char* c = reinterpret_cast<char*>(p);
	std::cout << *(c) << std::endl;
	std::cout << *(c+1) << std::endl;
	std::cout << *(c+2) << std::endl;
	std::cout << *(c+3) << std::endl;


    return 0;
}
