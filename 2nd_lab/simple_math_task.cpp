#include <iostream>
#include <math.h>

int main()
{

    std::cout << "Variant #7." << std::endl;

    int A;
    int B;
    int C;
    
    std::cout << "*All values should be in (0 ; 3*10^4)" << std::endl;
    std::cout << "Input A side: ";
    std::cin >> A; 
    std::cout << "Input B side: ";
    std::cin >> B;
    std::cout << "Input C side: ";
    std::cin >> C;

    float diag = 0;
    diag = pow(pow(A, 2) + pow(B, 2) + pow(C, 2), 0.5);
    std::cout << "The diagonal of a rectangular parallelepiped is " << diag << std::endl;

    return 0;

}
