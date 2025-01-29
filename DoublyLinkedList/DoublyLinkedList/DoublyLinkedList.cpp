#include <iostream>
#include <cassert>
#include <climits>
#include <vector>        // for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
    int data{ };
    Node* next{ };
    Node* prev{ };     // Previous node!

    Node(int data) : data(data) {}

    void set(Node* next, Node* prev) {
        this->next = next;
        this->prev = prev;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList {
private:
    Node* head{ };
    Node* tail{ };
    int length = 0;

    vector<Node*> debug_data;    // add/remove nodes you use

    void debug_add_node(Node* node) {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node* node) {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

public:
    LinkedList() {}
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList& another) = delete;

    void debug_print_address() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }

    void debug_print_node(Node* node, bool is_separate = false) {
        if (is_separate)
            cout << "Sep: ";
        if (node == nullptr) {
            cout << "nullptr\n";
            return;
        }

        if (node->prev == nullptr)
            cout << "X\t";
        else
            cout << node->prev->data << "\t";

        cout << " <= [" << node->data << "]\t => \t";

        if (node->next == nullptr)
            cout << "X\t";
        else
            cout << node->next->data << "\t";

        if (node == head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }

    void debug_print_list(string msg = "") {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int)debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "************\n" << flush;
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
        return oss.str();
    }

    void debug_verify_data_integrity() {
        if (length == 0) {
            assert(head == nullptr);
            assert(tail == nullptr);
        }
        else {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!head->prev);
            assert(!tail->next);
        }
        int len = 0;
        for (Node* cur = head; cur; cur = cur->next, len++) {
            if (len == length - 1)    // make sure we end at tail
                assert(cur == tail);
        }

        assert(length == len);
        assert(length == (int)debug_data.size());

        len = 0;
        for (Node* cur = tail; cur; cur = cur->prev, len++) {
            if (len == length - 1)    // make sure we end at head
                assert(cur == head);
        }
        //cout << "\n";
    }

    ////////////////////////////////////////////////////////////

    void print() { //Time Complexity O(n), Space O(1)
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void delete_node(Node* node) { //Time Complexity O(1), Space O(1)
        debug_remove_node(node);
        --length;
        delete node;
    }

    void add_node(Node* node) { //Time Complexity O(1), Space O(1)
        debug_add_node(node);
        ++length;
    }

    void link(Node* first, Node* second) { //Time Complexity O(1), Space O(1)
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    void insert_end(int value) { //Time Complexity O(1), Space O(1)
        Node* newNode = new Node(value);
        add_node(newNode);

        if (!head)
            head = tail = newNode;
        else {
            link(tail, newNode);
            tail = newNode;
        }
        debug_verify_data_integrity(); //Ignore it's Time Complexity it's just for debugging
    }

    void insert_front(int value) {  //Time Complexity O(1), Space O(1)
        Node* newNode = new Node(value);
        add_node(newNode);

        if (!head)
            head = tail = newNode;
        else {
            link(newNode, head);
            head = newNode;
        }
        debug_verify_data_integrity();
    }

    void print_reversed() { //Time Complexity O(n), Space O(1)
        for (Node* cur = tail; cur; cur = cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }

    void embed_after(Node* node_before, int value) { //Time Complexity O(1), Space O(1)
        Node* middle = new Node(value);
        add_node(middle);

        Node* node_after = node_before->next;
        link(node_before, middle);
        link(middle, node_after);
        debug_verify_data_integrity();
    }

    void insert_sorted(int value) { //Time Complexity O(n), Space O(1)
        if (!length || value <= head->data)
            insert_front(value);
        else if (tail->data <= value)
            insert_end(value);
        else {
            for (Node* cur = head; cur; cur = cur->next) {
                if (value <= cur->data) {
                    embed_after(cur->prev, value);
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }

    void delete_front() { //Time Complexity O(1), Space O(1)
        if (!head)
            return;

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete_node(temp);
        debug_verify_data_integrity();
    }

    void delete_end() //Time Complexity O(1), Space O(1)
    {
        if (!tail)
            return;

        Node* temp = tail;
        if (head == tail)
            head = tail = nullptr;
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete_node(temp);
        debug_verify_data_integrity();
    }

    Node* delete_and_link_utility(Node* cur) //Time Complexity O(1), Space O(1)
    {
        Node* ret = cur->prev;
        link(cur->prev, cur->next);
        delete_node(cur);
        return ret;
    }

    void delete_with_key(int value) //Time Complexity O(n), Space O(1)
    {
        if (!head)
            return;
        if (head->data == value)
            delete_front();

        else
        {
            for (Node* cur = head; cur; cur = cur->next)
            {
                if (cur->data == value)
                {
                    cur = delete_and_link_utility(cur);
                    if (!cur->next)
                        tail = cur;
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }

    void delete_all_nodes_with_key(int value) //Time Complexity O(n), Space O(1)
    {
        if (!head)
            return;
        for (Node* cur = head; cur; )
        {
            if (cur->data == value)
            {
                if (cur == head)
                {
                    cur = cur->next;
                    delete_front();
                    continue;
                }

                cur = delete_and_link_utility(cur);
                if (!cur->next)
                    tail = cur;
            }
            cur = cur->next;

        }
        debug_verify_data_integrity();
    }

    void delete_even_positions() //Time Complexity O(n), Space O(1)
    {
        if (!head)
            return;

        for (Node* cur = head; cur && cur->next; cur = cur->next)
        {
                delete_and_link_utility(cur->next);
                if (!cur->next)
                    tail = cur;
        }
        debug_verify_data_integrity();
    }

    void delete_odd_positions() //Time Complexity O(n), Space O(1)
    {
        if (!head)
            return;

        insert_front(-1);
        delete_even_positions();
        delete_front();

        debug_verify_data_integrity();
    }

    bool is_palindrome() //Time Complexity O(n), Space O(1)
    {
        if (!head)
            return true;

        Node* l = tail;
        Node* f = head;
        int counter = 0;

        while (counter < (length / 2))
        {
            counter++;
            if (l->data != f->data)
                return false;
            l = l->prev;
            f = f->next;
        }
        return true;
    }

    int middle() //Time Complexity O(n), Space O(1)
    {
        Node* l = tail;
        Node* f = head;
        while (head)
        {
            if (l == f || f->prev == l)
            {
                return f->data;
            }
            l = l->prev;
            f = f->next;
        }
        return -1;
    }

    int Middle() //Time Complexity O(n), Space O(1)
    {
        if (!head)
            return -1;
        Node* fast = head;
        Node* slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow->data;
    }

    void Swap(int k) //I preferred to not use any Utilities here
                     //Time Complexity O(n), Space O(1)
    {
        if (!head || !head->next)
            return;

        int kth_back = length - k + 1;

        Node* front = head;
        Node* back = tail;
        int z = 1;
        while (front)
        {
            if (z == k)
                break;
            front = front->next;
            back = back->prev;
            z++;
        }
        
        if (k == kth_back)
            return;

        if (k > kth_back)
        {
            Node* temp = front;
            front = back;
            back = temp;
        }

        Node* fp = front->prev;
        Node* fn = front->next;
        Node* bp = back->prev;
        Node* bn = back->next;

        if (k == 1 && front->next != back)
        {
            front->next = fp;
            back->next = fn;
            fn->prev = back;
            bp->next = front;
            front->prev = bp;
            head = back;
            tail = front;
        }
        else if (k == 1)
        {
            front->next = fp;
            back->prev = bn;
            back->next = front;
            front->prev = back;
            head = back;
            tail = front;
        }
        else if(front->next != back){
        back->next = fn;
        back->prev = fp;

        bp->next = front;
        bn->prev = front;

        front->next = bn;
        front->prev = bp;

        fp->next = back;
        fn->prev = back;
        }
        else
        {
            fp->next = back;
            back->prev = fp;
            back->next = front;
            front->prev = back;
            front->next = bn;
            bn->prev = front;
        }
        debug_verify_data_integrity();
    }

    void reverse() //Time Complexity O(n), Space O(1)
    {
        Node* next;
        Node* prev = nullptr;
        Node* cur = head;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            cur->prev = next;
            prev = cur;
            cur = next;
        }
        tail = head;
        head = prev;
        debug_verify_data_integrity();
    }
    void merge_2sorted_lists(LinkedList &other) //Time Complexity O(n), Space O(1)
    {
        if (!other.head)
            return;

        length = other.length + this->length;
        Node* Dummy = new Node(-1);
        Node* D = Dummy;
        Node* cur = head;
        Node* othercur = other.head;

        while (cur && othercur)
        {
   
            if (cur->data <= othercur->data)
            {
                Dummy->next = cur;
                cur->prev = Dummy;
                cur = cur->next;
            }
            else
            {
                Dummy->next = othercur;
                othercur->prev = Dummy;
                othercur = othercur->next;
            }
            Dummy = Dummy->next;
        }
        while (cur)
        {
            Dummy->next = cur;
            cur->prev = Dummy;
            cur = cur->next;
            Dummy = Dummy->next;
        }
        while (othercur)
        {
            Dummy->next = othercur;
            othercur->prev = Dummy;
            othercur = othercur->next;
            Dummy = Dummy->next;
        }

        head = D->next; 
        tail = Dummy;
    }
};


int main() 
{
}
