#include <iostream>
#include <random>
#include "list.hpp"

int main()
{
    std::random_device random;
    std::mt19937 mersenne(random());

    List list;

    for(int i(0); i < 30; ++i)
    {
        list.push_back( (mersenne() % 100) + 1 );
    }

    std::cout << "Unsorted:\n";
    list.print();
    std::cout <<'\n';

    list.heap_sort();

    std::cout << "Sorted:\n";
    list.print();
    std::cout <<'\n';

    return 0;
}