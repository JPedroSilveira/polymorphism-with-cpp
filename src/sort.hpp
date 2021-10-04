#ifndef SORT
#define SORT

#include <vector>
#include <iostream>
#include "comparable.hpp"
#include "pessoa.hpp"

namespace sort {
    namespace {
        template<typename T> int partition(std::vector<T>& items, int low, int high)
        { 
            const T& pivot = items[high];   
            int i = (low - 1); 
        
            for (int j = low; j <= high - 1; j++)
            {
                if (items[j].compares_to(pivot) < 0)
                {
                    i++;   
                    std::swap(items[i], items[j]);
                }
            }
            std::swap(items[i + 1], items[high]);
            return (i + 1);
        }

        template<typename T> void executeQuickSort(std::vector<T>& items, int low, int high)
        {
            if (low < high)
            {
                int pi = partition(items, low, high);

                executeQuickSort(items, low, pi - 1);
                executeQuickSort(items, pi + 1, high);
            }
        }
    }

    template<typename T> void quickSort(std::vector<T>& items)
    {
        executeQuickSort(items, 0, items.size() - 1);
    }
}

#endif