#include <iostream>

int SumOfDigits(int x)
{   
    int sm = 0;
    while(x > 0)
    {
        sm += x % 10;
        x /= 10;
    }

    return sm;
}
int MaxDigit(int y)
{   
    int mx = -1;
    while(y > 0)
    {
        if(y%10 > mx) 
            mx = y%10;
        y /= 10;
    }

    return mx;
}


int main()
{
    const int N_Max = 1000;
    int mas[N_Max];
    int n;
    std::cin >> n;
    
    for(int i=0;i<n;i++)
        std::cin >> mas[i];
    

    for(int i=0; i<n-1; i++)
    {
        int sm_i = SumOfDigits(mas[i]);
        int mx_i = MaxDigit(mas[i]);

        for(int j=i+1; j<n; j++)
        {
            int sm_j = SumOfDigits(mas[j]);
            int mx_j = MaxDigit(mas[j]);

            if(sm_i < sm_j)
            {
                int local = mas[i];
                mas[i] = mas[j];
                mas[j] = local;
            }

            else if((sm_i == sm_j) && (mx_i < mx_j))
            {
                int local = mas[i];
                mas[i] = mas[j];
                mas[j] = local;
            }
            
            else if(mas[i] < mas[j])
            {
                int local = mas[i];
                mas[i] = mas[j];
                mas[j] = local;
            }
        }
            
    }
    
    for(int i=0;i<n;i++)
        if (i == n-1)
            std::cout << mas[i] << ".";
        else
            std::cout << mas[i] << ", ";

    return 0;
}
