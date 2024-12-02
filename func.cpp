#include "func.hpp"
#include <iostream>

namespace aa
{

    void Read(int matrix[N_MaxN][N_MaxN], int& n)
    {
        std::cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                std::cin >> matrix[i][j];

    }

    int SumOfNums(int x)
    {
        int sm = 0;
        while(x>0)
        {
            sm += x%10;
            x /= 10;
        }
        return sm;
    }

    bool AreMaxMinEqual(int matrix[N_MaxN][N_MaxN], int n)
    {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] > mx)
                    mx = matrix[i][j];
                else if(matrix[i][j] < mn)
                    mn = matrix[i][j];
            }
        }
        
        if(SumOfNums(mx) == SumOfNums(mn))
            return true;
        else
            return false;
    }

    void Sort(int matrix[N_MaxN][N_MaxN], int n)
    { 
        int local[N_MaxN];
        for(int i=0;i<n-1;i++) // проходимся по строкам [0, n-2], т.к анализируем i и i+1
        {   
                int sm_1 = 0;
                int sm_2 = 0;
                for(int j=0;j<n;j++)
                    sm_1 += matrix[i][j];
                for(int j=0;j<n;j++)
                    sm_2 += matrix[i+1][j];
                
                if(sm_1 > sm_2)
                {
                    for(int k=0;k<n;k++)
                        local[k] = matrix[i][k];
                    
                    for(int k=0;k<n;k++)
                        matrix[i][k] = matrix[i+1][k];
                    
                    for(int k=0;k<n;k++)
                        matrix[i+1][k] = local[k];
                } 
        }
    }

    void Write(int matrix[N_MaxN][N_MaxN], int n)
    {
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    std::cout << matrix[i][j] << " ";

                std::cout << std::endl;
            }
    }

}