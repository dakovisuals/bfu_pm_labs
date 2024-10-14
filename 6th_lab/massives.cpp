#include <iostream>

int main()
{
    const int N_Max = 10;
    int mas[N_Max];

    int n;
    std::cin >> n;

    for(int i=0;i<n;i++)
        std::cin >> mas[i];
    

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(mas[i] < mas[j])
            {
                int local = mas[i];
                mas[i] = mas[j];
                mas[j] = mas[i];
            }
  

    for(int i=0;i<n;i++)
        std::cout << mas[i];

    return 0;
}
