#pragma once

class List
{
private:
    int tail;
    int max;
    int* array;
    void swap(const int& a, const int& b);
    int part_sort(int begin, int end);
    void heapify(int size, int root);

public:
    List();
    List(const int& size);
    ~List();
    void clear();
    bool isEmpty();
    bool isFull();
    int size();
    void print();
    void push_back(const int& data);
    int pop_back();
    void unshift(const int& data);
    int shift();
    int remove(const int& data);
    int search(const int& data);
    void resize(const int& newSize);
    void replace(const int& original, const int& substitute);
    void quick_sort(const int& begin, const int& end);
    void heap_sort();
};
