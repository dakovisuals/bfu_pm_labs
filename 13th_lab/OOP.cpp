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
        
    
    public:
        // ctor
        object(int a, int b, int angle) {
            std::cout << "//ctor" << std::endl;
            m_side_a = a;
            m_side_b = b;
            m_angle = angle;
        }

        // dtor
        ~object() {
            std::cout << "//dtor" << std::endl;
        }

        // func's
        bool setup()
        {
            if(m_side_a <= 0 || m_side_b <= 0 || m_angle <= 0 || m_angle >= 180) {
                std::cerr << "Error: Parallelogram can't be defined" << std::endl;
                return 0;
            }
            else {
                std::cerr << "Object: Parallelogram" << std::endl;
                return 1;
            }
        }

        int calc_perimeter() {
            return 2*(m_side_a + m_side_b);
        }

        int calc_area() {
            return m_side_a * (std::sin(3.14159265359*m_angle/180)*m_side_b); 
        }
};


int main()
{   
    int a = 10;
    int b = 5;
    int angle = 30;

    object X(a, b, angle);
    if (X.setup()) {
        std::cout << "Perimeter: " << X.calc_perimeter() << std::endl;
        std::cout << "Area: " << X.calc_area() << std::endl;

    }


    return 0;
}
