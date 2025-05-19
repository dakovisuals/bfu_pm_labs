#include <math.h>
#include <iostream>


const int N_Max = 1000;

class BigInt {
	private:
		char m_digits[N_Max]; // цифры в обратном порядке
		unsigned short m_size; // количество цифр
		bool m_sign; // true - положительное, false - отрицательное

	public:
		BigInt() : m_sign(true), m_size(0) {
			for (int i = 0; i < N_Max; i++) {
				m_digits[i] = 0;
			}
		}

		// ctor
		BigInt(const std::string& digits) {

			// Обработка знака
			size_t start_idx = 0;
			if (!digits.empty() && digits[0] == '-') {
				m_sign = false;
				start_idx = 1;
			} 
			else 
				m_sign = true;

			size_t len = digits.length() - start_idx;
			m_size = len;

			for(int i = 0; i < len; i++) {
				m_digits[i] = digits[len - i - 1 + start_idx] - '0'; // в реверсивном порядке
			}

			for(int i = len; i < N_Max; i++) {
				m_digits[i] = 0;
			}
		}

		bool abs_less(const BigInt& other) const {
			if (m_size != other.m_size)
				return m_size < other.m_size;
			for (int i = m_size - 1; i >= 0; i--) {
				if (m_digits[i] != other.m_digits[i])
					return m_digits[i] < other.m_digits[i];
			}
			return false; 
		}

		// Операция сложения с учетом знаков
		BigInt& operator+=(const BigInt& other) {
			if (m_sign == other.m_sign) {
				// одинаковый знак: складываем абсолютные значения
				unsigned short new_size = std::max(m_size, other.m_size);
				int carry = 0;
				for (int i=0; i<new_size || carry; i++) {
					int sum = m_digits[i] + other.m_digits[i] + carry;
					m_digits[i] = sum % 10;
					carry = sum /10;
					if (i >= m_size) m_size++;
				}
				m_sign = this->m_sign; // знак остается прежним
			} 
			
			else {
				// разные знаки: вычитаем больший из меньшего по абсолюту
				if (!abs_less(other)) {
					for(int i=0;i<m_size;i++){
						if(m_digits[i] < other.m_digits[i]){
								m_digits[i+1] -= 1;
								m_digits[i] = m_digits[i] + 10 - other.m_digits[i];
							} 

						else 
							m_digits[i] -= other.m_digits[i];
						}

					// Удаляем ведущие нули
					while(m_size>1 && m_digits[m_size-1]==0)
						m_size--;
					
					if(m_size==1 && m_digits[0]==0){
						m_sign=true; // ноль считается положительным
						this->m_sign = other.m_sign; // знак берется большего 
					} 
				}
			}
			return *this;
		}

		// Вычитание с учетом знаков
		BigInt& operator-=(const BigInt& other) {
			BigInt tmp = (other);
			tmp.m_sign = !other.m_sign;
			*this += tmp;

			return *this;
		}

		// Операторы + и -
		BigInt operator+(const BigInt& other) const {
			BigInt result(*this);
			result += other;
			return result;
		}

		BigInt operator-(const BigInt& other) const {
			BigInt result(*this);
			result -= other;
			return result;
		}

		bool operator<(const BigInt& other) const {
			if (m_sign != other.m_sign)
				return !m_sign;

			if (m_sign) { 
				// оба положительные: сравниваем абсолютные значения
				if (m_size != other.m_size)
					return m_size < other.m_size;

				for(int i=m_size-1;i>=0;i--) {
					if(m_digits[i]<other.m_digits[i])
						return true;
					else if(m_digits[i]>other.m_digits[i])
						return false;
				}
				return false; 
			} 
			
			else { 
				// оба отрицательные: сравниваем абсолютные значения, но логика обратная
				if (m_size != other.m_size)
					return m_size > other.m_size;

				for(int i=m_size-1;i>=0;i--) {
					if(m_digits[i]<other.m_digits[i])
						return false; 
					else if(m_digits[i]>other.m_digits[i])
						return true; 
				}
				return false; 
			}
		}

		bool operator>=(const BigInt& other) const {
			return !(*this<other);
		}

		friend std::ostream& operator<<(std::ostream& out, const BigInt& num);
};

// оператор вывода с учетом знака
std::ostream& operator<<(std::ostream& out, const BigInt& num) {
    if (!num.m_sign && !(num.m_size==1 && num.m_digits[0]==0))
        out << '-';
    for(int i=num.m_size-1;i>=0;i--) {
        out << static_cast<short>(num.m_digits[i]);
    }
    return out;
}

std::istream& operator>>(std::istream& in, BigInt& num) {
    std::string s;
    in >> s;
    num=BigInt(s);
    return in;
}

int main()
{   
    BigInt a("2001");
    BigInt b("-11");
    
	/*BigInt c = a+b;
	std::cout <<"a+b = " << c  << std::endl;*/

	//BigInt d("10");
	a += b;
	std::cout <<"a+=b = " << a  << std::endl;

	if(a<b)
		std::cout<<"a < b"<<std::endl;
	else
		std::cout<<"a >= b"<<std::endl;

	return 0;
}
