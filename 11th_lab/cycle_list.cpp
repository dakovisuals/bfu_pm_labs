#include <iostream>
#include <func01.hpp>

int main()
{
    mt::Node* sent = new mt::Node;
    sent->next = sent;
    sent->prev = sent;
    
    
    //input
    std::cout << "Enter a quantatiy of numbers:" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Enter " << n << " numbers: " << std::endl;
    for(int i=0;i<n;i++) {
        int a;
        std::cin >> a;
        AddBack(sent, a);
    }

    //code
    if(mt::TwoEqualDatas(sent, n))
        mt::SortByLastDigit(sent, n);
    else {
        mt::DeleteThree(sent);
        mt::DuplicateSeven(sent);
    }

    //output
    mt::Print(sent);

    //delete data from heap
    mt::Clear(sent);
    delete sent;


    return 0;
}
