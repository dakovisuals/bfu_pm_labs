#include <iostream>

int SumOfDigits(int x)
{   
    int sm = 0;
    while(x > 0)
    {
        sm += (x%10);
        x /= 10;
    }

    return sm;
}

bool Palindrome(int x)
{   
    int true_x = x;
    int mirrored_x = 0;
    if(x < 11)
        return 0;
    while(x>0)
    {   
        mirrored_x = ((mirrored_x*10) + x%10);
        x /= 10;
    }  

    return true_x == mirrored_x;
}

int main()
{
    const int N_Max = 20000;
    int mas[N_Max];
    int n;
    std::cin >> n;

    //In
    for(int i=0;i<n;i++)
        std::cin >> mas[i];


    //Deleting
    int j = 0;
    for(int i=0;i<n;i++)
    {
        if(SumOfDigits(mas[i]) == 10)
            continue;
        mas[j] = mas[i];
        j++;
    }
    n = j;


    //Duplicating
    for(int i=0;i<n;i++)
    {
	    if(Palindrome(mas[i]))
	    {
        n++;
		    for(int j=n-1;j>i;j--)
                {
                    mas[j+1] = mas[j];
			        mas[j] = mas[j-1];                    
                }
	    i++;
	    }
    }

    //Out
    for(int i=0;i<n;i++)
        std::cout << mas[i] << std::endl;
    return 0;
}
