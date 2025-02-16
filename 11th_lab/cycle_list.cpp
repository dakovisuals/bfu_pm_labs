#include <iostream>
#include <func.hpp>

int main()
{
    mt::Node* sent = new mt::Node;
    sent->next = sent;
    sent->prev = sent;
    
    std::cout << "Enter a quantatiy of numbers:" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Enter " << n << " numbers: " << std::endl;
    for(int i=0;i<n;i++) 
    {
        int a;
        std::cin >> a;
        AddBack(sent, a);
    }

    /*if(mt::TwoEqualNums(sent, n))
        mt::Sort(sent);
    else {
        mt::DeleteThree(sent);
        mt::DuplicateSeven(sent);
    }*/

    mt::Sort(sent, n);
    mt::Print(sent);
    mt::Clear(sent);

    delete sent;
    return 0;
}
