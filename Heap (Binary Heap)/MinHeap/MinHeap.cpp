#include <iostream>
#include<vector>
#include <cassert>
#include <queue>
#include <unordered_map>
using namespace std;


class MinHeap
{
    int* array{};
    int size{};
    int _capacity{};

public:
    MinHeap(int capacity)
    {
        array = new int[capacity];
        _capacity = capacity;
        size = 0;
    }
    ~MinHeap() {
        delete[] array;
    }
    
    int left(int node_index)
    {
        int p = node_index * 2 + 1;
        if (p >= size)
            return -1;
        return p;
    }

    int right(int node_index)
    {
        int p = node_index * 2 + 2;
        if (p >= size)
            return -1;
        return p;
    }

    int parent(int node_index)
    {
        if (node_index == 0)
            return -1;
        return (node_index - 1) / 2;
    }

    bool empty()
    {
        return size == 0;
    }

    void heapify_up(int child_pos)
    {
        int par_pos = parent(child_pos);
        if (child_pos == 0 || array[par_pos] < array[child_pos])
            return;
        swap(array[child_pos], array[par_pos]);
        heapify_up(par_pos);
    }

    void heapify_down(int pos = 0)
    {
        int child_pos = left(pos);
        int r = right(pos);

        if (child_pos == -1)
            return;

        if (r != -1 && array[r] < array[child_pos])
            child_pos = r;

        if (array[pos] > array[child_pos])
        {
            swap(array[pos], array[child_pos]);
            heapify_down(child_pos);
        }
    }

    void push(int key)
    {
        assert(size + 1 <= _capacity);
        array[size++] = key;
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
        heapify_down();
    }

    void print_less_than(int val)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] < val) cout << array[i] << " ";
        }
    }

    bool is_heap(int parent_pos)
    {
        if (parent_pos == -1)
            return true;

        int left_child = left(parent_pos);
        int right_child = right(parent_pos);
        if (left_child != -1 && array[left_child] < array[parent_pos])
            return false;
        if (right_child != -1 && array[right_child] < array[parent_pos])
            return false;

        return is_heap(left_child) && is_heap(right_child);
    }
};

class MaxHeap {
    MinHeap heap;
public:
    MaxHeap(): heap(1000)
    {
    }
    MaxHeap(const vector<int> &v) : heap(v.size())
    {
        for (auto it : v)
            heap.push(-it);
    }

    bool empty()
    {
        return heap.empty();
    }

    void push(int val)
    {
        heap.push(-val);
    }

    void pop()
    {
        heap.pop();

    }

    int top()
    {
        return -heap.top();
    }
};

class PriorityQueue {
private:
    int capacity{ 1000 };
    int* key{};
    int* value{};
    int size{};

    int left(int node) {
        int p = 2 * node + 1;
        if (p >= size)
            return -1;
        return p;
    }
    int right(int node) {
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }
    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    void heapify_up(int child_pos) {
        // stop when parent is smaller (or no parent)
        int par_pos = parent(child_pos);
        if (child_pos == 0 || key[par_pos] > key[child_pos])
            return;

        swap(key[child_pos], key[par_pos]);
        swap(value[child_pos], value[par_pos]);
        heapify_up(par_pos);
    }

    void heapify_down(int parent_pos) {	// O(logn)
        int child_pos = left(parent_pos);
        int right_child = right(parent_pos);

        if (child_pos == -1) // no children
            return;
        // is right bigger than left?
        if (right_child != -1 && key[right_child] > key[child_pos])
            child_pos = right_child;

        if (key[parent_pos] < key[child_pos]) {
            swap(key[parent_pos], key[child_pos]);
            swap(value[parent_pos], value[child_pos]);
            heapify_down(child_pos);
        }
    }
public:

    PriorityQueue() {
        key = new int[capacity] {};
        value = new int[capacity] {};
        size = 0;
    }

    ~PriorityQueue() {
        delete[] key;
        delete[] value;
    }

    int top() {
        assert(!isempty());
        return value[0];
    }

    void enqueue(int data, int priority) {
        assert(size + 1 <= capacity);
        value[size] = data;
        key[size++] = priority;
        heapify_up(size - 1);
    }

    int dequeue() {
        assert(!isempty());
        int ret = value[0];
        key[0] = key[--size];
        value[0] = value[size];

        heapify_down(0);
        return ret;
    }

    bool isempty() {
        return size == 0;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;
    for (auto it : matrix)
    {
        for (auto x : it)
        {
            if (pq.size() < k)
            {
                pq.push(x);
            }
            else if (pq.top() > x)
            {
                pq.pop();
                pq.push(x);
            }
        }
    }
    return pq.top();
}

int main()
{
}

