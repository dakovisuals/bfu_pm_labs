#include <iostream>
#include <fstream>
const int N_Max = 5;

//1.
int f(int x)
{
    //std::cout << x/10 << " /// " << x%10 << std::endl;
    if (x < 10)
        return x;

    else 
    {
        int next = f(x/10);
        int current = x%10;
    
        if(current > next)
            return current;
        else
            return next;
    }
}


//2.
void swap(int numbers[N_Max], int a, int b)
{
    int tmp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = tmp;
}


void qsort(int numbers[], int start, int end)
{
    if (start == end)
        return;
    

    int pivot = start;
    for(int i=start+1; i <= end; i++)
        if (numbers[i] < numbers[start]) 
        {   
            pivot++;
            swap(numbers, pivot, i);
        }

    swap(numbers, start, pivot); 


    // [start ... pivot-1] pivot [pivot+1 ... end]
    if(start < pivot) 
        qsort(numbers, start, pivot-1);

    if(pivot < end) 
        qsort(numbers, pivot+1, end); 
}


//3.
void Search(int i, int j, int step, int n, int m, char field[100][100], int table[100][100]) 
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
    
    //quick sort
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
    return 0;
}
