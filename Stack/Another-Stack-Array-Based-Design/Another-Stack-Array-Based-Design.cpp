#include <iostream>
using namespace std;


class stack
{
private:
	int added_elements{};
	int size{};
	int* array{};

public:
	stack(int size) : size(size) {
		array = new int[size];
		added_elements = 0;
	};

	bool is_full()//Time Complexity O(1) & Space Complexity O(1)
	{
		return size == added_elements;
	}

	bool push(int value) //Time Complexity O(n) & Space Complexity O(1)
	{
		if (is_full())
			return false;

		for (int i = added_elements; i > 0; i--)
		{
			array[i] = array[i - 1];
		}
		array[0] = value;
		added_elements++;
		return true;
	}

	bool is_empty()//Time Complexity O(1) & Space Complexity O(1)
	{
		return added_elements != 0;
	}

	void display() //Time Complexity O(n) & Space Complexity O(1)
	{
		for (int i = 0; i < added_elements; i++)
			cout << array[i] << " ";
		cout << endl;
	}

	bool pop() //Time Complexity O(n) & Space Complexity O(1)
	{
		if (!is_empty())
			return false;
		cout << array[0];
		for (int i = 0; i < added_elements-1; i++)
		{
			array[i] = array[i + 1];
		}
		added_elements--;
		return true;
		
	}

	void peek()//Time Complexity O(1) & Space Complexity O(1)
	{
		cout << array[0];
	}



};

int main()
{

}


