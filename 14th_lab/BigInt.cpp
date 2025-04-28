#include <math.h>
#include <iostream>
const int N_Max = 1000;

class BigInt {

    // fields
    private:
        char m_digits[N_Max];
        unsigned short m_size;


    public:
        //ctor
        BigInt(const std::string& digits) {
            std::cout << "/ctor" << std::endl;

            unsigned long long len = digits.length();

            for(int i=0; i<len; i++)
                m_digits[i] = digits[len-i-1] - '0';

            for(int i=len; i<N_Max; i++)
                m_digits[i] = 0;
            
            m_size = len;
        }

        /*
        //copy ctor
        BigInt(const BigInt& other) {
            std::cout << "/copy_ctor" << std::endl;
            std::copy(other.m_digits, other.m_digits+m_size, m_digits);
        }
        */
        
        //dtor
        ~BigInt() {
            std::cout << "/dtor" << std::endl;
        }

        //operators
        
        //...//


    
    friend std::ostream& operator<<(std::ostream& out, const BigInt& other);

};


//istream
std::istream& operator>>(std::istream& in, BigInt& other) {
    std::string s;
    in >> s;
    other = BigInt(s);
    return in;
}

//ostream
std::ostream& operator<<(std::ostream& out, const BigInt& other) {
    for(int i=0;i<other.m_size;i++) {
        out << static_cast<unsigned short>(other.m_digits[other.m_size - i - 1]);
    }
    return out;
}


int main()
{   
    BigInt X("30");
    BigInt Y("150");
    BigInt Z = X + Y;
    std::cout << "Z: " << Z << std::endl;

    std::cout << "X: " << X << std::endl;
    X += "10";
    std::cout << "X+=10: " << X << std::endl;
    X++;
    std::cout << "X++: " << X << std::endl;

    if (X < Y)
		std::cout << "X < Y" << std::endl;

    return 0;
}
