#include <iostream>
#include<vector>
#include <cassert>
using namespace std;

class MaxHeap
{
    int *array{};
    int size{};
    int _capacity{};
public:
    MaxHeap(int capacity)
    {
        array = new int[capacity];
        _capacity = capacity;
        size = 0;
    }
    ~MaxHeap() {
        delete[] array;
    }


    int left(int node_index)
    {
        int l = node_index * 2 + 1;
        if (l >= size)
            return -1;
        return l;
    }

    int right(int node_index)
    {
        int r = node_index * 2 + 2;
        if (r >= size)
            return -1;
        return r;
    }

    int parent(int node_index) //with zero index
    {
        int p = (node_index + 1) / 2 - 1;
        if (p < 0)
            return -1;
        return p;
    }

    bool empty()
    {
        return size == 0;
    }

    void heapify_up(int node_index)
    {
        int par = parent(node_index);
        if (par == -1 || array[par] >= array[node_index])
            return;
        swap(array[node_index], array[par]);
        heapify_up(par);
    }

    void heapify_down(int node_index)
    {
        int l = left(node_index);
        int r = right(node_index);
        int largest = node_index;

        if (l != -1 && array[l] > array[largest])
            largest = l;
        if (r != -1 && array[r] > array[largest])
            largest = r;

        if (largest != node_index)
        {
            swap(array[node_index], array[largest]);
            heapify_down(largest);
        }

    }

    void push(int val)
    {
        assert(size + 1 <= _capacity);
        array[size++] = val;
        heapify_up(size - 1);
    }

    int top()
    {
        assert(!empty());
        return array[0];
    }

    void pop()
    {
        assert(!empty());
        array[0] = array[size - 1];
        size--;
        heapify_down(0);
    }


};

int main()
{
    MaxHeap heap(5);
    heap.push(10);
    heap.push(30);
    heap.push(20);

    cout << heap.top() << endl; //print 30
    heap.pop();
    cout << heap.top() << endl; //print 20

}

