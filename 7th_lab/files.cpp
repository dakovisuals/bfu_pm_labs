#include <iostream>

const int N_MaxN = 100;
const int N_MaxM = 100;
void In(int matrix[N_MaxN][N_MaxM], int& n, int& m)
{
    std::cin >> n, m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            std::cin >> matrix[i][j];

}

int SumOfNums(int x)
{
    int sm = 0;
    while(x>0){
        sm += x%10;
        x /= 10;
    }
    return sm;
}

bool AreMaxMinEqual(int matrix[N_MaxN][N_MaxM], int n, int m)
{
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] > mx)
                mx = matrix[i][j];
            else if(matrix[i][j] < mn)
                mn = matrix[i][j];
        }
    
    if(SumOfNums(mx) == SumOfNums(mn))
        return true;
    else
        return false;
    }
}

void Sort(int matrix[N_MaxN][N_MaxM], int n, int m)
{ 
    for(int i=0;i<n-1;i++)
    {   
        for(int k=i+1;k<n;k++)
        {
            int sm_j = 0;
            int sm_i = sm_j;
            for(int j=0;j<m;j++)
                sm_i += matrix[i][j];
            for(int j=0;j<m;j++)
                sm_j += matrix[i][j];
            if(sm_)
        }

            
    }
}

int main()
{

    In();
    if(AreMaxMinEqual)
    {
        Sort();
    }

    return 0;
}
