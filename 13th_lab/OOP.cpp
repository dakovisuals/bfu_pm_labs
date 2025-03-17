// m initializer list
//object(int side_a, int side_b, int angle, double height):
    //m_side_a(side_a), m_side_b(side_b), m_angle(angle)
//{
    //std::cout << "ctor" << std::endl;
//}

#include <math.h>
#include <iostream>

class object {
    // fields
    private:
        int m_side_a;
        int m_side_b;
        int m_angle;
        bool check;
        
    
    public:
        // ctor
        object(int a, int b, int angle) {
            std::cout << "//ctor" << std::endl;
            m_side_a = a;
            m_side_b = b;
            m_angle = angle;

            if(m_side_a <= 0 || m_side_b <= 0 || m_angle <= 0 || m_angle >= 180)
            {
                std::cout << "Error: Parallelogram can't be defined" << std::endl;
                check = 0;
            }
        }

        // dtor
        ~object() {
            std::cout << "//dtor" << std::endl;
        }

        // methods
        void calc_perimeter() {
            if(check) {
                std::cout << "Perimeter is " << 2*(m_side_a + m_side_b) << std::endl;
            }
            else {
                std::cout << "Error: Perimeter is not defined" << std::endl;
            }
            

        }

        void calc_area() { 
            if(check) {
                std::cout << "Area is " << m_side_a * (std::sin(3.14159265359*m_angle/180)*m_side_b) << std::endl;
            }
            else {
                std::cout << "Error: Area is not defined" << std::endl;
            }
        }
};


int main()
{   
    int a = 10;
    int b = 5;
    int angle = 30;

    object X(a, b, angle);
    
    X.calc_perimeter();
    X.calc_area();

    return 0;
}
