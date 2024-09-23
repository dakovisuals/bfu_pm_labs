#include <iostream>

int main()
{
    int number;
    int index;
    std::cin >> number;
    std::cin >> index;
    number = (number & -(1 << index));
    std::cout << number << std::endl;

    return 0;

}
