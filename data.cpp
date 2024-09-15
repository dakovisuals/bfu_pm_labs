#include <iostream>
#include <limits>

int main()
{
	std::cout << "Hello, Michael Tarachkov!" << std::endl;
	std::cout << "I've made my 1st lab: Main data types in C++" << std::endl;
	std::cout << "----------------------------------------" << std::endl;


	std::cout << "Integer" << std::endl;
	int a {1};
	int b {17};
	int c {a + b};
	std::cout << "Size of int: " << sizeof(int) << std::endl;
	std::cout << "Min/Max values: " << std::numeric_limits<int>::min() << " / " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Example a + b / 1 + 17: " << c << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << "Character" << std::endl;
	char grade = 'AAA';
	std::cout << "Size of chr: " << sizeof(char) << std::endl;
	std::cout << "Min/Max values: " << std::numeric_limits<char>::min() << " / " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Example: " << grade << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << "Boolean" << std::endl;
	bool status {true};
	bool status_2 {false};
	std::cout << "Size of bool: " << sizeof(bool) << std::endl;
	std::cout << "Min/Max values: " << status_2 << " / " << status << std::endl;
	std::cout << "Example: " << status << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << "Floating point" << std::endl;
	float f {0.01};
	float g {0.02}; 
	float h {f + g};
	std::cout << "Size of float: " << sizeof(float) << std::endl;
	std::cout << "Min/Max values: " << std::numeric_limits<float>::min() << " / " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Example f + g / 0.01 + 0.02: " << h << std::endl;

	return 0;
}