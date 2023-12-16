#include <iostream>
#include <random>
#include <ctime>
#include "linkedList.hpp"

int main()
{
    LinkedList<int> list;
    std::cout<<"output:-\t";
    // random number generator engine
    std::mt19937 rng(static_cast<unsigned>(time(nullptr)));

    std::uniform_int_distribution<int> distribution(1,100);

    for(int i = 0;  i<10; i++){
        list.append(distribution(rng));
    }

   std::cout<<list;

    return 0;
}
