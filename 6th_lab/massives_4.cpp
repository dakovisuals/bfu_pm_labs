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
    int mirrored_x = 0;
    while(x>0)
    {
        mirrored_x = mirrored_x*10 + x%10;
        x /= 10;
    }  
    return x == mirrored_x;
}

int main()
{
    const int N_Max = 20000;
    int mas[N_Max];
    int n;
    std::cin >> n;

    for(int i=0;i<n;i++)
        std::cin >> mas[i];


    // Deleting
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
		    for(int j=n;j>i;j--)
		    {
			    mas[j] = mas[j-1];
		    }
	    i++;
	    n++;
	    }
    }

    for(int i=0;i<n;i++)
        std::cout << mas[i] << std::endl;
    return 0;
}
