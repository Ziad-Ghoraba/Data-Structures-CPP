#include <iostream>
#include <cassert>
#include<unordered_set>
using namespace std;

struct Node {
	int data{ };
	Node* next{ };
	Node(int data) :
		data(data) {
	}
};

class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;
public:
	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
		++length;
	}
	void create_cycle() {
		for (int i = 0; i < 4; ++i)
			insert_end(i);
		Node* now = tail;
		for (int i = 0; i < 3; ++i)
			insert_end(14 + i);
		tail->next = now;// cycle
	}

	void remove_cycle()
	{
		unordered_set<Node*> s;

		Node* cur = head;
		Node* prev = nullptr;
		while (cur)
		{
			if (!s.count(cur))
				s.insert(cur);
			else
				break;
			prev = cur;
			cur = cur->next;
		}
		if(prev)
			prev->next = nullptr;
	}

};

int main()
{
	LinkedList lst;
	lst.create_cycle();
	lst.remove_cycle();
	lst.print();
}