#include <math.h>
#include <iostream>
const int N_Max = 1000;

class BigInt {
    // fields
    private:
        char m_digits[N_Max];
        unsigned short m_size;

    public:
        BigInt() = default;

        //ctor
        BigInt(const std::string& digits) {

            unsigned long long len = digits.length();
            m_size = len;

            for(int i=0; i<len; i++) // в реверсивном порядке
                m_digits[i] = digits[len-i-1] - '0'; 

            for(int i=len; i<N_Max; i++)
                m_digits[i] = 0;
            
            
        }

        //operators
        BigInt& operator+=(const BigInt& other) {
            unsigned short new_size = std::max(m_size, other.m_size);
            for(int i=0; i<new_size; i++) {
                m_digits[i] += other.m_digits[i];
                if(m_digits[i] > 9) {
                    m_digits[i] -= 10;
                    m_digits[i+1]++;

                    // на всякий случай проверка размера
                    if(i+1 == new_size) {
                        new_size++;
                    }
                }
            }
            m_size = new_size;
            return *this;
        }

        BigInt operator+(BigInt& other) {
            BigInt result(*this);
            result += other;
            return result;
        }



        bool operator<(const BigInt& other) {
            if(m_size < other.m_size)
                return true;
            else if(m_size > other.m_size)
                return false;
            else {
                for(int i=m_size-1; i>=0; i--) {
                    if(m_digits[i] < other.m_digits[i])
                        return true;
                    else if(m_digits[i] > other.m_digits[i])
                        return false;
                }
                return false;
            }
        }

        bool operator>=(const BigInt& other) {
            return !(*this < other);
        }

        BigInt& operator*(const BigInt& other) {
            BigInt result("0");
            for(BigInt i("0"); i<other; i+=BigInt("1"))
                result += *this;

            return result;
        }

        BigInt& operator*=(const BigInt& other) {
            *this = *this * other;
            return *this;
        }
    
    //функция ostream имеет доступ к приватным полям
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
    for(int i=0; i<other.m_size; i++) {
        out << static_cast<short>(other.m_digits[other.m_size - i - 1]);
    }
    return out;
}


int main()
{   
    BigInt None;
    BigInt X("30");
    BigInt Y("4");

    //X += BigInt("10");
    //std::cout << "X += 10: " << X << std::endl;


    BigInt Z;
    Z = X + Y;
    std::cout << "Z: " << Z << std::endl;

    if (X < Y)
		std::cout << "X < Y" << std::endl;

    return 0;
}
