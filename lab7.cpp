#include "func.hpp"

int main()
{
    int n;
    int matrix[aa::N_MaxN][aa::N_MaxN];
    aa::Read(matrix, n);
    if(aa::AreMaxMinEqual(matrix, n))
        aa::Sort(matrix, n);
    aa::Write(matrix, n);

    return 0;
}