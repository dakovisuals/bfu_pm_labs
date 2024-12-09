#pragma once

namespace A
{
    //7_lab
    const int N_MaxN = 100;

    void Read(int matrix[N_MaxN][N_MaxN], int& n);
    int SumOfNums(int x);
    bool AreMaxMinEqual(int matrix[N_MaxN][N_MaxN], int n);
    void Sort(int matrix[N_MaxN][N_MaxN], int n);
    void Write(int matrix[N_MaxN][N_MaxN], int n);

    //8_lab
    std::string to_lower(const std::string& s);

}