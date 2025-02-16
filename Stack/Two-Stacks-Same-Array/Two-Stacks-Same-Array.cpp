#include <iostream>
using namespace std;

class stack
{
private:
	int top1, top2, size;
	int* array;

public:
	stack(int size) : size(size), top1(-1), top2(size) //Time Complexity O(1) & Space Complexity O(1)
	{
		array = new int[size];
	}

	bool is_full() //Time Complexity O(1) & Space Complexity O(1)
	{
		return (top2 - top1) == 1;
	}

	bool is_empty() //Time Complexity O(1) & Space Complexity O(1)
	{
		return top1 == -1 && top2 == size;
	}

	void push(int id, int value) //Time Complexity O(1) & Space Complexity O(1)
	{
		if (is_full())
		{
			cout << "Stack is full\n";
			return;
		}
		if (id == 1)
			array[++top1] = value;
		else
			array[--top2] = value;
	}

	void pop(int id) //Time Complexity O(1) & Space Complexity O(1)
	{
		if (is_empty())
			return;
		if (id == 1 && top1 > -1)
			cout << array[top1--] << " ";
		else if (id == 2 && top2 < size)
			cout << array[top2++] << " ";
		else
			cout << "Stack " << id << " is empty";
	}

	void peek(int id) //Time Complexity O(1) & Space Complexity O(1)
	{
		if (is_empty())
			return;
		if (id == 1 && top1 > -1)
			cout << array[top1] << " ";
		else if (id == 2 && top2 < size)
			cout << array[top2] << " ";
		else
			cout << "Stack" << id << "is empty";
	}

	void display() //Time Complexity O(n) & Space Complexity O(1)
	{
		for (int i = top1; i >=0 ; i--)
			cout << array[i]<<" ";
		cout << "\n";
		for (int i = top2; i < size; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
	
};

int main()
{

}

