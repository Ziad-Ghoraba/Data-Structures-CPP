#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node* next; //Pointer to SAME type

    Node(int data) : data(data) {}
    ~Node() {
        cout << "Destroy value: " << data << " at address" << this << "\n";
    }
};

class LinkedList {
private:
    Node* tail ;
    Node* head ;
    int length = 0;


public:
    LinkedList(Node* Nhead, Node* Ntail) : head(Nhead), tail(Ntail) {
        for (Node* newNode = head; newNode;  newNode = newNode->next) {
            ++length;
        }
    }   
    LinkedList(int val) {
        Node* newNode = new Node(val);
        head = tail = newNode;
        ++length;
    }
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}
    ~LinkedList() { //O(1) memory - O(n) time
        Node* Next;
        while (head)
        {
           Next  = head->next;
           delete head;
           head = Next;
        }
        tail = nullptr;
    }

    void Length()
    {
        cout << length << "\n";
    }

    void print() { //O(1) memory - O(n) time
        Node* newNode = head;
        while (newNode != nullptr)
        {
            cout << newNode->data <<newNode << " => ";
            newNode = newNode->next;
        }
        cout << endl; 
    }

    void print_for() //O(1) memory - O(n) time
    {
        for (Node* newNode = head; newNode;  newNode = newNode->next) {
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
        debug_verify_data_integrity();
    }

    void delete_front() //O(1) memory - O(1) time
    {
        if (!head)
        {
            cout << "There are no nodes";
            return;
        }

        if (head == tail)
        {
            delete head;
            tail = head = nullptr;
            --length;
            debug_verify_data_integrity();
            return;
        }

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        --length;
        debug_verify_data_integrity();
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

    Node* get_nth(int number) { //O(1) memory - O(n) time
        int cnt = 1;
        for (Node* current = head; current; current = current->next)
            if (cnt++ == number)
               return current;
        return nullptr;
    }

    Node* get_nth_back(int number) //O(1) memory - O(n) time
    {
        int cnt = length - number + 1;
        return get_nth(cnt);
    }

    int improved_search(int value) { //O(1) memory - O(n) time
        int indx = 0;
        Node* previous = nullptr;
        for (Node* current = head; current; current = current->next, ++indx)
        { 
            if (current->data == value)
            { 
                if (!previous)
                    return indx;
                swap(previous->data, current->data);
                return indx - 1;
            }
            previous = current;
        }
        return -1;
    }

    void debug_verify_data_integrity()
    {
        if (length == 0)
        {
           assert(head == nullptr);
           assert(tail == nullptr);
           return;
        }
        assert(head != nullptr);
        assert(tail != nullptr);
        assert(tail->next == nullptr);

        if (length == 1)
        {
            assert(head == tail);
            return;
        }
        else
        {
            assert(head != tail);
            if (length == 2)
                assert(head->next = tail);
            else if(length == 3)
            {
                assert(head->next);
                assert(head->next->next == tail);
            }
            return;
        }

        int len = 0;
        Node* prev = nullptr;
        for (Node* cur = head; cur; prev = cur, cur = cur->next, len++)
            assert(len < 100000); //Consider as an infinite cycle
        
        assert(len == length);
        assert(prev == tail);
    }

    string debug_to_string() {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node* cur = head; cur; cur = cur->next) {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        oss << "\n";
        return oss.str();
    }

    Node* previous_node(Node* node) //O(1) memory - O(n) time
    {
        Node* prev = nullptr;
        for (Node* curr = head; curr != node;curr = curr->next)
            prev = curr;
        return prev;
    }

    void delete_node_with_key(int key) //O(1) memory - O(n^2) time
    {
        for (Node* cur = head; cur; cur = cur->next)
        {
            if (cur->data == key)
            { 
                delete_node(cur);
                return;
            }
        }
    }

    void delete_node(Node* &node) //O(1) memory - O(n) time
    {
        if (length == 0 )
        {
            cout << "There is no nodes to delete";
            return;
        }

        if (length == 1)
        {
            head = nullptr, tail = nullptr;
            delete node;
            --length;
            debug_verify_data_integrity();
            return;
        }

        if (head == node)
        {
            head = head->next;
            delete node;
            --length;
            debug_verify_data_integrity();
            return;
        }

        if (tail == node)
        {
            tail = previous_node(tail);
            tail->next = nullptr;
            delete node;
            --length;
            debug_verify_data_integrity();
            return;
        }
        Node* prev = previous_node(node);
        prev->next = node->next;
        --length;
        delete node;
        debug_verify_data_integrity();

    }

    void delete_node_num(int num) //O(1) memory - O(n) time
    {
        if (num > length || num < 1)
        {
            cout << "There is no node with this index.\n";
            return;
        }

        if (length == 1)
        {
            delete head;
            head = nullptr, tail = nullptr;
            --length;
            debug_verify_data_integrity();
            return;
        }

        Node* target = get_nth(num);
        if (target == head)
        {
            head = head->next;
            delete target;
            --length;
            debug_verify_data_integrity();
            return;
        }

        Node* prev = get_nth(num - 1);
        if (length == num) //deleting the tail
        {
            delete tail;
            prev->next = nullptr;
            tail = prev;
            --length;
            return;
        }

        prev->next = target->next;
        --length;
        delete target;
        debug_verify_data_integrity();
    }

    bool is_same(const LinkedList& linkedlist1) //O(1) memory - O(n) time
    {
        if (this->length != linkedlist1.length)
            return false;
        Node* head1 = linkedlist1.head;
        for (Node* head2 = head; head1 && head2; head1 = head1->next, head2 = head2->next)
            if (head1->data != head2->data)
                return false;
        return true;
    }

    void swap_pairs() //O(1) memory - O(n) time
    {
        if (!head)
            return;

        Node* current = head;
        Node* currentNext = head->next;
        while (current && currentNext)
        {
            swap(current->data, currentNext->data);
            current = currentNext->next;
            currentNext = current->next;
        }

    }

    void reverse() //O(1) memory - O(n) time
    {
        Node* prev = nullptr;
        Node* next;
        for (Node* cur = head; cur; cur = next)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
        }
        head = prev;
    }

    void  delete_even_positions() //O(1) memory - O(n) time
    {
        Node* prev = head;
        for (Node* cur = head->next; cur; cur = prev->next )
        {
            prev->next = cur->next;
            delete cur;
            prev = prev->next;
            if (!prev )
            {
                return;
            }
        }
    }

    void insert_sorted(int value)  //O(1) memory - O(n) time
    {
        Node* node = new Node(value);

        if (!head)
        {
            head = tail = node;
            ++length;
            return;
        }

        if (value < head->data)
        {
            node->next = head;
            head = node;
            ++length;
            return;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        while (curr)
        {
            if (node-> data < curr->data)
            {
                prev->next = node;
                node->next = curr;
                ++length;
                return;
            }
            curr = curr->next;
            prev = prev->next;

        }
        tail->next = node;
        tail = node;
        ++length;

    }

    void swap_head_tail() //O(1) memory - O(n) time
    {
        if (!head || !head->next) return;

        Node* temp1 = head;
        Node* temp2 = get_nth(length-1);
        tail->next = head->next;
        temp2->next = head;
        head->next = nullptr;
        head = tail;
        tail = temp1;
    }

    void left_roate(int k) //O(1) memory - O(n) time
    {
        if (!head || k%length == 0) return;

        int number_of_rotations = k % length;
        Node* target = get_nth(number_of_rotations);

        tail->next = head;
        head = target->next;
        target->next = nullptr;
        tail = target;
        debug_verify_data_integrity();
    }

    void remove_duplicates() //O(1) memory - O(n) time
    {
        for (Node* i = head; i; i = i->next)
        {
            Node* prev = i;
            for (Node* j = i->next; j;)
            {
                if (j->data == i->data)
                {
                    prev->next = j->next;
                    --length;
                    Node* temp = j;
                    j = j->next;
                    if (temp == tail)
                        tail = prev;
                    delete temp;
                    continue;
                }
                j = j->next;
                prev = prev->next;
            }
        }
        debug_verify_data_integrity();
    }

    void remove_last_occurrence(int key) //O(1) memory - O(n) time
    {

        Node* prev = nullptr;
        Node* cur = head;
        while (cur)
        {
            if (cur->next)
            {
                if (cur->next->data == key)
                    prev = cur;
            }
            cur = cur->next;
        }
        if (prev)
        {
            if (prev->next == tail)
            {
                prev->next = nullptr;
                delete tail;
                tail = prev;
            }
            else
            {
                prev->next = prev->next->next;
            }
            --length;
        }
        else
        {
            if (head->data == key)
            {
                delete_front();
            }
        }
        debug_verify_data_integrity();


    }

    void move_to_back(int key) //O(1) memory - O(n) time
    {
        Node* cur = head;
        Node* prev = nullptr;
        Node* oldTail = tail;

        while (cur!=oldTail)
        {
            if (cur->data == key)
            {
                tail->next = cur;
                if (!prev)
                {
                    head = cur->next;
                    cur->next = nullptr;
                    tail = cur;
                    cur = head;
                }
                else
                {
                    prev->next = cur->next;
                    cur->next = nullptr;
                    tail = cur;
                    cur = prev->next;
                }
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        debug_verify_data_integrity();

    }

    int max(Node* head = nullptr, bool first_call = true) //O(n) memory - O(n) time
    {
        if (first_call)
            return this->max(this->head, false);

        if (head == nullptr)
            return INT_MIN;
        return std::max(head->data, this->max(head->next, false));
    }


};

 
int main()
{
    LinkedList linkedList1 =  LinkedList();

    linkedList1.insert_end(5);
    linkedList1.insert_end(10);
    linkedList1.insert_end(10);

    linkedList1.print_for();

    cout<<linkedList1.max();
    linkedList1.print_for();
}








