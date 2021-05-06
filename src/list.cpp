#include "list.hpp"
#include <iostream>

List::List()
{
    tail = -1;
    max = 0;
    array = nullptr;
}

List::List(const int& size)
{
    tail = -1;
    max = size;
    array = new int[size];
}

List::~List()
{
    clear();
}

void List::clear()
{
    tail = -1;
    max = 0;
    delete[] array;
    array = nullptr;
}

inline bool List::isEmpty()
{
    return (tail == -1);
}

inline bool List::isFull()
{
    return (tail == max - 1);
}

inline int List::size()
{
    return (tail + 1);
}

void List::print()
{
    if(isEmpty())
    {
        std::cout << "<EMPTY>" << std::endl;
    }
    else
    {
        for(int i = 0; i <= tail; ++i)
        {
            std::cout << array[i] << ", ";
        }
        std::cout << '\n';
    }
}

void List::push_back(const int& data)
{
    if(isFull())
    {
        if(isEmpty())
        {
            resize(1);
        }
        else
        {
            resize(size() * 2);
        }
    }

    ++tail;

    array[tail] = data;
}

int List::pop_back()
{
    if(isEmpty())
    {
        return int();
    }
    else
    {
        int result = array[tail];
        array[tail] = int();
        --tail;
        return result;
    }

    if(!isEmpty())
    {
        resize(1);
    }
    else if(max > 2 * size())
    {
        resize(2 * size());
    }
}

void List::unshift(const int& data)
{
    if(isFull())
    {
        if(isEmpty())
        {
            resize(1);
        }
        else
        {
            resize(size() * 2);
        }
    }

    for(int i = tail; i >= 0; --i)
    {
        array[i + 1] = array[i];
    }

    array[0] = data;

    ++tail;
}

int List::shift()
{
    if(isEmpty())
    {
        return int();
    }
    else
    {
        int result = array[0];

        for(int i = 0; i < tail; ++i)
        {
            array[i] = array[i + 1];
        }

        array[tail] = int();

        --tail;

        if(!isEmpty())
        {
            resize(1);
        }
        else if(max > 2 * size())
        {
            resize(2 * size());
        }

        return result;
    }
}

int List::remove(const int& data)
{
    if(!isEmpty())
    {
        int* first = array;
        int* result = array;

        while(first <= array + tail)
        {
            if(*first != data)
            {
                *result = *first;
                ++result;
            }

            ++first;
        }

        while(result != first)
        {
            *result = int();
            --tail;
            ++result;
        }

        if(!isEmpty())
        {
            resize(1);
        }
        else if(max > 2 * size())
        {
            resize(2 * size());
        }
    }

    return size();
}

int List::search(const int& data)
{
    for(int i = 0; i < size(); ++i)
    {
        if(array[i] == data)
        {
            return i;
        }
    }

    return -1;
}

void List::resize(const int& newSize)
{
    if(newSize != max)
    {
        if(newSize == 0)
        {
            clear();
        }
        else if(newSize > 0)
        {
            array = (int*)realloc(array, sizeof(int) * newSize);
            max = newSize;

            if(newSize < tail)
            {
                tail = newSize - 1;
            }
            else
            {
                for(int i = size(); i < newSize; ++i)
                {
                    array[i] = int();
                }
            }
        }
        else
        {
            std::cout << "<REALLOC ERROR>\n";
        }
    }
}

void List::replace(const int& original, const int& substitute)//--------------------task 2
{
    for(int i = 0; i < size(); ++i)
    {
        if(array[i] == original)
        {
            array[i] = substitute;
        }
    }
}

inline void List::swap(const int& a, const int& b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int List::part_sort(int begin, int end)
{
    int pivot = begin;

    --end;

    while(true)
    {
        while(array[begin] <= array[pivot])
        {
            ++begin;

            if(begin == size())
                break;
        }

        while(array[end] > array[pivot])
        {
            --end;

            if(end == -1)
                break;
        }

        if(begin < end)
            swap(begin, end);
        else
            break;
    }

    swap(end, pivot);

    return end;
}

void List::quick_sort(const int& begin, const int& end)
{
    if(end - begin < 2)
        return;

    int median = part_sort(begin, end);
    quick_sort(begin, median);
    quick_sort(median + 1, end);
}

void List::heapify(int size, int root)
{
    int max = root;
    int left = 2 * root + 1;
    int right = left + 1;

    if(left < size && array[left] > array[max])
    {
        max = left;
    }

    if(right < size && array[right] > array[max])
    {
        max = right;
    }

    if(max != root)
    {
        swap(root, max);
        heapify(size, max);
    }
}

void List::heap_sort()
{
    for(int i = size() / 2 - 1; i >= 0; --i)
    {
        heapify(size(), i);
    }

    for (int i = size() - 1; i > 0; --i)
    {
        swap(0, i);
        heapify(i, 0);
    }
    
}