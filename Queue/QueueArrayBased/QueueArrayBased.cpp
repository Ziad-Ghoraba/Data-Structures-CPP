#include <iostream>
#include <cassert>
using namespace std;


class Queue
{
private:
	int size{};
	int front{ 0 };
	int rear{ 0 };
	int added_elements{0};
	int* array{};

public:
	Queue(int size) : size(size) {
		array = new int[size];
	};

	int next(int idx) //Time Complexity O(1) & Space Complexity O(1)
	{
		//return (idx +1 ) % size; //It takes more computer resources

		++idx;
		if (idx == size)
			return 0;
		return idx;
	}

	int prev(int idx)
	{
		--idx;
		if (idx == -1)
		{
			return 6;
		}
		return idx;
	}


	bool is_empty() //Time Complexity O(1) & Space Complexity O(1)
	{
		return added_elements == 0;
	}

	bool is_full()  //Time Complexity O(1) & Space Complexity O(1)
	{
		return added_elements == size;
	}

	//Normal Queue For the queue
	void enqueue_rear(int value) //Time Complexity O(1) & Space Complexity O(1)
	{
		if (!is_full())
		{
			++added_elements;
			array[rear] = value;
			rear = next(rear);
		}
		else
		{
			cout << "Queue Is FULL!";
		}
	}

	void enqueue_front(int value) //Time Complexity O(1) & Space Complexity O(1)
	{
		if (!is_full())
		{
			++added_elements;
			front = prev(front);
			array[front] = value;
		}
		else
		{
			cout << "Queue Is FULL!";
		}
	}

	//Normal Queue For the queue
	int dequeue_front() //Time Complexity O(1) & Space Complexity O(1)
	{
		assert(!is_empty());
		int temp = front;
		--added_elements;
		front = next(front);
		return array[temp];
	}

	int dequeue_rear() //Time Complexity O(1) & Space Complexity O(1)
	{
		assert(!is_empty());
		rear = prev(rear);
		--added_elements;
		return array[rear];
	}

	void display() //Time Complexity O(n) & Space Complexity O(1)
	{
		cout << "Front: " << front << " - Rear: " << rear << "\t";
		if (is_full())
			cout << "Full";
		else if (is_empty())
		{
			cout << "Empty \n";
			return;
		}
		cout << endl;
		int temp = front;
		for (int i = 0; i < added_elements; i++)
		{
			cout << array[temp] << " ";
			temp = next(temp);
		}
		cout << endl;
	}

};

int main()
{
	Queue que = Queue(7);
	que.enqueue_front(3);
	que.enqueue_front(2);
	que.enqueue_rear(4);
	que.enqueue_front(1);
	que.display();
	cout << que.dequeue_rear() <<endl;
	cout << que.dequeue_front() << endl;
	que.display();
	cout << que.dequeue_rear() <<endl;
	cout << que.dequeue_front() << endl;
	que.display();
	que.enqueue_front(7);
	que.display();

}

