#include <iostream>
using namespace std;

struct Node
{
	double data{};
	Node* next{};

	Node(double data) : data(data) {}
	//~Node() { cout << "Destroy value " << data << ", At address " << this << endl; }
};

class stack
{
private:
	Node* head{};
public:
	stack()
	{
		head = nullptr;
	}
	stack(Node* newNode)
	{
		head = newNode;
	}
	stack(double value) {
		Node* newNode = new Node(value);
		head = newNode;
	}

	void push(double value) //Time Complexity O(1) and Space Complexity O(1)
	{
		Node* newNode = new Node(value);
		if(head){
			newNode->next = head;
			head = newNode;
		}
		else
		{
			head = newNode;
		}

	}

	double peek() //Time Complexity O(1) and Space Complexity O(1)
	{
		if (head)
			return head->data;
	}

	double pop() //Time Complexity O(1) and Space Complexity O(1)
	{
		if (head)
		{
			double value = head->data;
			Node* temp = head;
			head = head->next;
			delete temp;
			return value;
		}
	}

	bool is_empty() //Time Complexity O(1) and Space Complexity O(1)
	{
		return !head;
	}

	void Display() //With Middle in format [ m ]
	{
		Node* slow = head;
		Node* fast = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		for (Node* temp = head; temp ;temp = temp->next )
		{
			if (temp != slow)
				cout << temp->data << " ";
			else
				cout << "[" << slow->data << "]" << " ";
		}
		cout << endl;



	}

};	

double Evaluate(double x1, double x2, char c)
{
	if (c == '/')
	{
		return x2 / x1;
	}
	else if (c == '+')
	{
		return x2 + x1;
	}
	else if (c == '-')
	{
		return x2 - x1;
	}
	else if (c == '*')
	{
		return x2 * x1;
	}
	else if (c == '^')
	{
		return pow(x2, x1);
	}
}


double postfix_evaluation(string postfix)
{
	
	stack st = stack();
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isdigit(postfix[i]))
			st.push(postfix[i] - '0');
		else
		{
			double x1, x2;
			x1 = st.pop();
			x2 = st.pop();
			st.push(Evaluate(x1, x2, postfix[i]));
		}
	}
	return st.pop();
}


int main()
{
	cout << postfix_evaluation("135*+72/-") << endl;
	cout << postfix_evaluation("432^^") << endl;

	cout << "-------------------------------" << endl;

	stack st = stack();
	for (int i = 0; i < 10;i++)
	{
		st.push(i);
		st.Display();
	}
	while (!st.is_empty())
	{
		st.pop();
		st.Display();
	}
	
}

