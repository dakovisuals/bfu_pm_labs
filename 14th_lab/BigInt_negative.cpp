#include <math.h>
#include <iostream>
#include <string>

const int N_Max = 1000;

class BigInt {
    // fields
private:

public:
    char m_digits[N_Max];
    unsigned short m_size;
    bool m_is_negative; 

    BigInt() = default;
    // ctor
    BigInt(const std::string& digits) {
        unsigned long long len = digits.length();
        m_size = len;
        
        if(m_digits[0] == '-') {
            m_is_negative = 1;

            for(int i = 0; i < m_size; i++) // в реверсивном порядке
                m_digits[i] = digits[m_size-i-1] - '0';

            for (int i = m_size; i < N_Max; i++)
                m_digits[i] = 0;
        }

        else {
            m_is_negative = 0;

            for(int i = 0; i < m_size; i++) // в реверсивном порядке
                m_digits[i] = digits[m_size-i-1] - '0';

            for(int i = m_size; i < N_Max; i++)
                m_digits[i] = 0;
        }
    }

    // operators
    
    bool operator<(const BigInt& other) {
        if (m_is_negative && !other.m_is_negative)
            return true;
    }
        /*
        else if (!m_is_negative && other.m_is_negative)
            return false;

        if(m_is_negative==1 && other.m_is_negative==1) {
            std::cout << "check";
            if (m_size > other.m_size)
                return true;
            else if (m_size < other.m_size)
                return false;

            else {
                for(int i=m_size-1; i>0; i--) {
                    if(m_digits[i] < other.m_digits[i])
                    return false;

                    else if(m_digits[i] > other.m_digits[i])
                        return true;

                }
                return true;
            }
        }

        else if(m_is_negative==0 && other.m_is_negative==0) {
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
    }

    bool operator>=(const BigInt& other) const {
        return !(*this < other);
    }
    
   
    BigInt& operator+=(const BigInt& other) {
        unsigned short new_size = std::max(m_size, other.m_size);
        if(!m_is_negative && !other.m_is_negative) {
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
        }  
        else {

        }
        m_size = new_size;
        return *this;
    }


    BigInt operator+(const BigInt& other) const {
        BigInt result(*this);
        result += other;
        return result;
    }




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
    if (other.m_is_negative)
        out << '-';

    for (int i = 0; i < other.m_size; i++) {
        out << static_cast<short>(other.m_digits[other.m_size - i - 1]);
    }

return out;
*/
}

int main() {   
    BigInt X("-1");
    BigInt Y("2");

    //BigInt Z = X + Y;

    //std::cout << "Z: " << Z << std::endl;

    if (X >= Y)
		std::cout << "X >= Y" << std::endl;
    else if (X < Y)
        std::cout << "X < Y" << std::endl;


	return 0;
}
