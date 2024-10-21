#include <iostream>


int main()
{
    const int N_Max = 100;
    const int M_Max = 100;

    int matrix[N_Max][M_Max];

    int n, m;
    std::cin >> n >> m;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            std::cin >> matrix[i][j];
            
    int sm;
    int mx = 0;
    int stroke = 0;
    for(int i=0;i<n;i++)
    {
        sm = 0;

        for(int j=0;j<m;j++)
            sm += matrix[i][j];

        if(sm > mx)
        {
            mx = sm;
            stroke = i;
        }
    }

    for(int j=0;j<m;j++)
        matrix[stroke][j]++;


for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
