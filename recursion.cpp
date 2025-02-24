#include <iostream>
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


    return 0;
}
