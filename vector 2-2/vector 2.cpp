#include <iostream>
#include <vector>
#include <algorithm>


int ErrorofEnter()//проверка ввода от 1 до 20 для элементов вектора
{
    while (true)
    {
        int n;
        std::cout << "Введите n-элемент вектора от 1 до 20 включительно" << std::endl;
        std::cin >> n;
        if ((n > 0)& (n < 21))
            return(n);
        else
            std::cout << "Ошибка ввода" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}
int ErrorofEnter1()//проверка ввода по верхней планке int
{
    while (true)
    {
        int n;
        std::cout << "Введите n-размер вектора от 1 до 2147483647 включительно" << std::endl;
        std::cin >> n;
        if ((n > 0)& (n < 2147483648))
            return(n);
        else
            std::cout << "Ошибка ввода" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}
//1)
void fill(std::vector<int> &v)
{   
    int s=0;
    for (int i = 0; i < v.size(); i++)              //итак мой план очень прост
    {                                               //1)
        std::cout << "Введите элемент вектора: ";   //заполняем массив n элементов вектора
        v[i]= ErrorofEnter();                            //2)
        if (v[i] > s)                               //расширяем вектор на 1 элемент больший макс введенного на 1, О(1) сложность
        {                                           //сортируем массив встроенной функцией вектора О(n) сложность
            s = v[i];                               //3)
        }                                           //в функции проверяем i==i+1 на равенство, в сортированном массиве
    }                                               //если равны меняем счетчик на 1
 //2)                                               //если не равны выводим значения числа и их количество в массиве
    v.push_back(s+1);                               //чтобы не выйти за границу массива пробег цикла v.size() - 1
    std::sort(v.begin(), v.end());                  //добавленный элемент расширенного вектора не учитывается
}  
//3
void print(std::vector<int>& v)
{
    int z = 1;      //счётчик кол-ва чисел массива
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            z = z + 1;
        }
        else
        {
            std::cout << v[i] << ":" << z << std::endl;
            z = 1;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    n=ErrorofEnter1();
    std::vector<int> v(n);
    fill(v);
    print(v);
    return(0);
}