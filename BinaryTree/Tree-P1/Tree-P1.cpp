#include <iostream>
using namespace std;


#pragma region Trees Type
//Binary Tree Has At Most 2 Childes
#pragma endregion

#pragma region Binary Tree Formulas
//h -> Height
//n -> Number Of Nodes

// n = (2^h+1) - 1   ====> Only For Perfect Tree
// h = log(n+1) - 1  ====> Only For Perfect Tree
#pragma endregion

struct Node
{
    char data{};
    Node* left{};
    Node* right{};
    Node(char data) : data(data) {};


};

void print(Node*& root)//TC O(n) && SC O(h) where h is the height 
{
    if (root)
    {
        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }
       
}

void clear(Node*& root) //TC O(1) && SC O(1)
{
    if (!root)
        return;
    delete root;
    root = nullptr;
}


void print_postorder(Node*& root)//TC O(n) && SC O(h) 
{
    if (!root)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
    //clear(root); //To clear after printing
}


void print_inorder(Node*& root)//TC O(n) && SC O(h) 
{
    if (!root)
        return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
    //clear(root);
}

void print_preorder(Node*& root)//TC O(n) && SC O(h) 
{
    if (!root)
        return;
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
    //clear(root);
}

int find_height(Node*& root) //TC O(n) && SC O(h) 
{
    if (!root)
        return 0;
    return 1 +max(find_height(root->left), find_height(root->right));

}

int find_no_leaf(Node*& root) //TC O(n) && SC O(h) 
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return find_no_leaf(root->left) + find_no_leaf(root->right);
}

char find_max(Node* root, char prev = '0') //TC O(n) && SC O(h) 
{
    if (!root)
        return prev;
    if (root->data > prev)
        return max(find_max(root->left, root->data), find_max(root->right, root->data));
    else
        return max(find_max(root->left, prev), find_max(root->right, prev));
}



int main()
{
    Node* root = new Node('+');
    Node* node2 = new Node('2');
    Node* node3 = new Node('3');
    Node* node4 = new Node('4');
    Node* node5 = new Node('5');

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node3->right = node5;

    int h = find_height(root);
    cout << h << endl;
    cout << find_no_leaf(root) << endl;
    cout << find_max(root);
}

