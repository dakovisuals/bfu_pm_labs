#include <iostream>
#include <fstream>

class object {

    // Fields
    private:
        int a_side;
        int b_side;
        int height_a;
        int height_b;
        int area;

    public:
        void set_sides(int a, int b, int c, int d) {
            if(a*b*c*d <= 0) {
                std::cout << "Error: sides cant be negative" << std::endl;
            }
            int a_side = a;
            int b_side = b;
            if(c < b || d < a) {
                
            }
        
        }

        void set_heights(int a, int b) {
            if(a <= 0 || b <= 0) {
                std::cout << "Error: heights cant be negative" << std::endl;
            }
            if(a < a_side)

            else {
                int height = a;
                int b_height = b;
            }
        }


    
};


int main()
{   




    return 0;
}
