#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Vector
{

private:
    int *arr = nullptr; // Pointer to the dynamic array
    int size = 0;       // Current number of elements in the vector
    int capacity = 0;   // Maximum number of elements the vector can hold without resizing

    // Expands the vector's capacity by doubling it, reallocates memory, and copies existing elements
    void expand_capacity()
    {
        cout << "Capacity was " << capacity;
        capacity *= 2;
        cout << ", And become " << capacity << "\n";
        int *arr2 = new int[capacity];
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i];
        swap(arr2, arr);
        delete[] arr2;
    }

public:
    // Constructor to initialize a vector with a specific capacity
    Vector(int value)
    {
        if (value < 0)
            value = 1;
        capacity = value;
        arr = new int[capacity]{};
    }

    // Returns the element at the given index. Ensures the index is valid
    int get(int idx)
    {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    // Updates the value at the given index. Ensures the index is valid
    void set(int idx, int val)
    {
        assert(0 <= idx && idx < size);
        arr[idx] = val;
    }

    // Prints all elements in the vector
    void print()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i];
        cout << "\n";
    }

    // Returns the first element in the vector
    int get_front()
    {
        return arr[0];
    }

    // Returns the last element in the vector
    int get_back()
    {
        return arr[size - 1];
    }

    // Adds a new element at the end of the vector. Resizes if needed
    void push_back(int value)
    {
        if (capacity <= size)
            expand_capacity();
        arr[size++] = value;
    }

    // Inserts a new element at a specific index, shifting elements to the right
    void insert(int index, int value)
    {
        if (index == size)
        {
            push_back(value);
            return;
        }
        assert(index >= 0 && index < size);

        if (capacity == size)
            expand_capacity();

        for (int i = size - 1; i >= index; --i)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        ++size;
    }

    // Removes and returns the last element in the vector
    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        int popped = arr[size - 1];
        --size;
        arr[size] = 0;
        return popped;
    }

    // Performs a single right rotation on the vector
    void right_rotation()
    {
        int last_element = arr[size - 1];
        for (int i = size - 1; i >= 1; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last_element;
    }

    // Performs a single left rotation on the vector
    void left_rotation()
    {
        int first = arr[0];
        for (int i = 0; i < size - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first;
    }

    // Performs multiple right rotations based on the given number of steps
    void right_rotation(int steps)
    {
        steps %= size;
        while (steps--)
            right_rotation();
    }

    // Removes and returns the element at a specific index, shifting elements to fill the gap
    int pop(int indx)
    {
        assert(indx >= 0 && indx < size);

        int val = arr[indx];
        for (int i = indx; i < size - 1; ++i)
            arr[i] = arr[i + 1];

        --size;
        return val;
    }

    // Searches for an element, moves it closer to the front if found, and returns its index
    int find(int val)
    {
        for (int i = 0; i < size; ++i)
            if (arr[i] == val)
            {
                if (i == 0)
                    return 0;
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        return -1;
    }

    // Destructor to free dynamically allocated memory
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

#pragma region old push_back but with complexity O(n^2)
// void push_back(int value) {
//     // Number of steps will be n(n+1)/2 =~ n^2
//     int* arr2 = new int[size + 1];
//     for (int i = 0; i < size; ++i)
//         arr2[i] = arr[i];
//     arr2[size++] = value;
//     swap(arr2, arr);
//     delete[] arr2;
// }
#pragma endregion

#pragma region old push_front but with complexity O(n^2)
// void push_front(int value) {
//     // Number of steps will be n(n+1)/2 =~ n^2
//     int* arr2 = new int[size + 1];
//     for (int i = 1; i <= size; ++i)
//         arr2[i] = arr[i - 1];
//     arr2[0] = value;
//     ++size;
//     swap(arr2, arr);
//     delete[] arr2;
// }
#pragma endregion

#pragma region old find but with complexity O(n)
// int find(int val) {
//     for (int i = 0; i < size; ++i)
//         if (arr[i] == val)
//             return i;
//     return -1;
// }
#pragma endregion
};

int main()
{
}
/*
Note: Memory Cost and Amortized Analysis of Vector

When using a dynamic array like `Vector`, we can calculate the memory cost using amortized analysis.
Amortized analysis considers the total cost of operations over a sequence of actions, rather than individual operations.

Key Points for Amortized Analysis:
1. Expansion Cost:
   - When the vector reaches its current capacity, it doubles the capacity (e.g., from n to 2n).
   - This doubling ensures that frequent reallocation is avoided, making most push operations O(1).

2. Memory Usage:
   - The memory cost during resizing involves:
     a. Allocating a new array with double the capacity.
     b. Copying existing elements to the new array.
   - For n operations, the total cost of resizing is proportional to O(n), spread over all operations.

3. Amortized Cost:
   - Each `push_back` operation has an average cost of O(1) over a sequence of operations,
     even though some individual operations (like resizing) may take O(n).
*/
