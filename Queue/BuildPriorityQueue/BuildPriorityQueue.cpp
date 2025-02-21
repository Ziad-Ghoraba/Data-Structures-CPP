#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
    int data;
    Node* next; //Pointer to SAME type

    Node(int data) : data(data) {}
    //~Node() {
    //    cout << "Destroy value: " << data << " at address" << this << "\n";
    //}
};

class LinkedList {
private:
    Node* tail;
    Node* head;
    int length = 0;


public:
    LinkedList(Node* Nhead, Node* Ntail) : head(Nhead), tail(Ntail) {
        for (Node* newNode = head; newNode; newNode = newNode->next) {
            ++length;
        }
    }
    LinkedList(int val) {
        Node* newNode = new Node(val);
        head = tail = newNode;
        ++length;
    }
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    int Length()
    {
        return length;
    }

    void print() { //O(1) memory - O(n) time
        Node* newNode = head;
        while (newNode != nullptr)
        {
            cout << newNode->data << newNode << " => ";
            newNode = newNode->next;
        }
        cout << endl;
    }

    void print_for() //O(1) memory - O(n) time
    {
        for (Node* newNode = head; newNode; newNode = newNode->next) {
            cout << newNode->data << " => ";
        }
        cout << endl;
    }

    void insert_end(int value) //O(1) memory - O(1)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
            ++length;
            return;
        }
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
        ++length;
    }

    void insert_front(int value) //O(1) memory - O(1) time
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
            ++length;
            return;
        }
        newNode->next = head;
        head = newNode;
        ++length;

    }

    int delete_front() //O(1) memory - O(1) time
    {
        if (!head)
            cout << "There are no nodes";
        assert(head);


        if (head == tail)
        {
            int temp = head->data;
            delete head;
            tail = head = nullptr;
            --length;

            return temp;
        }
        int temp = head->data;
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        --length;
        return temp;
    }

    int search(int value) //O(1) memory - O(n) time
    {
        int indx = 0;
        for (Node* newNode = head; newNode; newNode = newNode->next, ++indx) {
            {
                if (newNode->data == value)
                    return indx;
            }
        }
        return -1;
    }

    int front()
    {
        if (head)
            return head->data;
    }

};

class Queue
{
    LinkedList list;
public:
    void enqueue(int value)
    {
        list.insert_end(value);
    }

    int dequeue()
    {
        return list.delete_front();
    }

    void display()
    {
        list.print();
    }

    bool is_empty()
    {
        return list.Length() == 0;
    }

    int front()
    {
        return list.front();
    }


};

class PriorityQueue
{
private:
    Queue priority1;
    Queue priority2;
    Queue priority3;
    int added_elements{};
    int size;
public:
    PriorityQueue(int size) : size(size) {
        priority1 = Queue();
        priority2 = Queue();
        priority3 = Queue();
    };

    bool is_full()
    {
        return added_elements == size;
    }

    bool is_empty()
    {
        return added_elements == 0;
    }

    void enqueue(int value, int priority)
    {
        assert(!is_full());
        assert(priority <= 3 || priority >= 1);
        if (priority == 1)
            priority1.enqueue(value);

        if (priority == 2)
            priority2.enqueue(value);

        if(priority == 3)
            priority3.enqueue(value);
        ++added_elements;
    }

    int dequeue()
    {
        assert(!is_empty());
        --added_elements;
        if (!priority1.is_empty())
            return priority1.dequeue();

        if (!priority2.is_empty())
            return priority2.dequeue();

        if (!priority3.is_empty())
            return priority3.dequeue();

    }


};
int main()
{
    PriorityQueue task(8);
    task.enqueue(1, 1);
    task.enqueue(2, 2);
    task.enqueue(3, 3);
    task.enqueue(4, 1);
    task.enqueue(5, 3);

    while (!task.is_empty()) {
        cout << task.dequeue();
    }

}

