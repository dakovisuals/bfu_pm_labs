#include <iostream>
#include <fstream>
const int N_Max = 5;
using ull = unsigned long long;


//1.
int f(int x)
{
    //std::cout << x/10 << " /// " << x%10 << std::endl;
    if (x < 10)
        return x;

    else 
    {
        int next = f(x/10);
        int digit = x%10;
    
        if(digit > next)
            return digit;
        else
            return next;
    }
}


//2.
void swap(int numbers[N_Max], ull a, ull b)
{
    ull tmp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = tmp;
}


void qsort(int numbers[], ull start, ull end)
{
    // начальный индекс должен быть меньше конечного индекса для массива из 2 и более элементов
    if (start >= end)
        return;
    // проверяем все элементы относительно элемента с индексом start
    ull current = start;
    for (ull i=start+1; i <= end; i++)
    {
        // если i-ый элемент меньше начального
        if (numbers[i] < numbers[start]) 
            swap(numbers, current=current+1, i); // меняем его с левым
    }

    swap(numbers, start, current); // Меняем выбранный (start) и последний обмененный элементы

    if (current > start) 
        qsort(numbers, start, current-1); // Сортируем элементы слева

    if (end > current+1) 
        qsort(numbers, current+1, end); // Сортируем элементы справа
}


//3.
void Search(int i, int j, int step, int n, int m, char field[100][100], 
    int table[100][100]) 
    {
    if(step >= table[i][j])
    return;

    table[i][j] = step;

    if(field[i][j] == 'E')
    return;
    
    //diagonal directions
    if(i + 1 < n && j + 1 < n && field[i+1][j+1] != '#')
    Search(i+1,j+1,step+1,n,m,field,table);
    if(i - 1 < n && j + 1 < n && field[i-1][j+1] != '#')
    Search(i-1,j+1,step+1,n,m,field,table);
    if(i - 1 < n && j - 1 < n && field[i-1][j-1] != '#')
    Search(i-1,j-1,step+1,n,m,field,table);
    if(i + 1 < n && j - 1 < n && field[i+1][j-1] != '#')
    Search(i+1,j-1,step+1,n,m,field,table);
    
    //straight directions
    if(i + 1 < n && field[i+1][j] != '#')
    Search(i+1,j,step+1,n,m,field,table);
    if(i - 1 >= 0 && field[i-1][j] != '#')
    Search(i-1,j,step+1,n,m,field,table);
    if(j + 1 < m && field[i][j + 1] != '#')
    Search(i,j+1,step+1,n,m,field,table);
    if(j - 1 >= 0 && field[i][j - 1] != '#')
    Search(i,j-1,step+1,n,m,field,table);
    }


int main()
{   
    //1.
    int N;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> N;

    std::cout << "Max digit is: " << f(N) << std::endl;


    //2.
    int numbers[N_Max];
    for(int i=0; i<N_Max; i++)
        std::cin >> numbers[i];
    
    qsort(numbers, 0, N_Max-1);

    for(int i=0; i<N_Max; i++)
        std::cout << numbers[i] << " ";


    //3.
    char field[100][100];
    int table[100][100];

    std::ifstream in("input.txt");
    int n, m, i_start, j_start, i_end, j_end;
    in >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            table[i][j] = INT_MAX;
            in >> field[i][j];
            if(field[i][j] == 'S') {
                i_start = i;
                j_start = j;
            }
            else if(field[i][j] == 'E') {
                i_end = i;
                j_end = j;
            }
        }

    Search(i_start, j_start, 0, n, m, field, table);
    std::cout << table[i_end][j_end] << std::endl;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            std::cout << field[i][j] << ' ';
        std::cout << std::endl;
    }
    
    return 0;
}
