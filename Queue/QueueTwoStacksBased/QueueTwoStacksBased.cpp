#include <iostream>
#include <cassert>
#include<stack>
using namespace std;

class Queue
{
private:
    int size;
    int added_elements{};
    stack<int> s1;
    stack<int> s2;
public:
    void enqueue(int value) //Time Complexity O(n) & Space Complexity O(n)
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(value);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(value);
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    bool is_empty()
    {
        return s1.empty() && s2.empty();
    }

    int dequeue() //O(1)
    {
        if (is_empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        int p;
        if (!s1.empty())
        {
            p = s1.top();
            s1.pop();
            return p;
        }

        p = s2.top();
        s2.pop();
        return p;
    }

};

class QueueTwo
{
private:
    int size;
    int added_elements{};
    stack<int> s1;
    stack<int> s2;
public:
    void enqueue(int value) //Time Complexity O(n) & Space Complexity O(n)
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(value);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(value);
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    bool is_empty()
    {
        return s1.empty() && s2.empty();
    }

    int dequeue() //O(1)
    {
        if (is_empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        int p;
        if (!s1.empty())
        {
            p = s1.top();
            s1.pop();
            return p;
        }

        p = s2.top();
        s2.pop();
        return p;
    }

};

int main()
{
    Queue qu = Queue();
    for (int i = 0; i < 6; i++)
        qu.enqueue(i);
    qu.enqueue(8);
    while (!qu.is_empty())
        cout << qu.dequeue() << " ";
}