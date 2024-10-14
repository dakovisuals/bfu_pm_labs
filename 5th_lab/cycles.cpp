#include <iostream>

int main()
{   
    // 1
    int mn = INT_MAX;
    int sm = 0;
    int num = 0;

    int n, x;
    std::cout << "Input n: " << std::endl;
    std::cin >> n;
    
    for(int i=0; i<n; i++)
    {
        std::cout << "Input value " << i << std::endl; 
        std::cin >> x;
        if((x % 3 == 0) || (x % 7 == 0))
        {
            if (x < mn)
            {
                mn = x;
                num = i+1;
            }
            sm += x;
        }
    }

    std::cout << "Sum: " << sm << std::endl;
    std::cout << "Min x % 3 or x % 7: " << mn << std::endl;
    std::cout << "Number of that x: " << num << std::endl;


    // 2
    int mult = 1;

    int N, y;
    std::cout << "Input N: " << std::endl;
    std::cin >> N;
    
    while(N>0)
    {
        y = N%10;
        if(y%2==0)
            mult *= y;
        N = N / 10;
    }

    if(mult == 1)
        std::cout << "No any y % 2" << std::endl;

    else
        std::cout << "Multiplication is " << mult << std::endl;

    return 0;
}
