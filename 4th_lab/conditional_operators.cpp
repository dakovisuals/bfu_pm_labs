#include <iostream>

int main()
{
    // 1)
    std::cout << "1)" << std::endl;

    int A, B, C, ans1;
    std::cout << "*All values must be natural " << std::endl;
    std::cout << "Input A value: ";
    std::cin >> A;
    std::cout << "Input B value: ";
    std::cin >> B;
    std::cout << "Input C value: ";
    std::cin >> C;
    
    if((A%B==0) && (B>C))
        ans1 = A/B + C;

    else if((A%B==0) && (B<C))
        ans1 = A/B - C;

    else
        ans1 = (A+B) * C;

    std::cout << ans1 << std::endl;


    // 2)
    std::cout << "--------------" << std::endl;
    std::cout << "2)" << std::endl;

    int N;
    std::cout << "Input N value: ";
    std::cin >> N;

    switch(N)
    {
    case 1: std::cout << "Monday" << std::endl;
        break;
    case 2: std::cout << "Tuesday" << std::endl;
        break;
    case 3: std::cout << "Wednesday" << std::endl;
        break;
    case 4: std::cout << "Thursday" << std::endl;
        break;
    case 5: std::cout << "Friday" << std::endl;
        break;
    case 6: std::cout << "Saturday" << std::endl;
        break;
    case 7: std::cout << "Sunday" << std::endl;
        break;
    
    default:std::cout << "Error: N not in [1, 7]" << std::endl;
    }


    // 3)
    std::cout << "--------------" << std::endl;
    std::cout << "3)" << std::endl;

    int X;
    std::cout << "Input X value (-1 or 1) : " << std::endl;
    std::cin >> X;
    
    if((X != 1) && (X != -1))
        std::cout << "Error: X must be 1 or -1";

    else if(X==1)
        std::cout << "Positive number";
    
    else
        std::cout << "Negative number";


    return 0;
}
