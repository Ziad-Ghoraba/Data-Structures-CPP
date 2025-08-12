#include <iostream>
#include <queue>

using namespace std;

class AVLTree
{
private:
	int value{};
	int height{};
	int count{ 1 };		// number of nodes in this subtree
	AVLTree* left{};		
	AVLTree* right{};

	

	int  ch_height(AVLTree* node) //child node
	{
		if (!node)
			return -1;
		return node->height; //0 for leaf
	}

	void update_height()
	{
		height = 1 + max(ch_height(left), ch_height(right));
	}

	int balance_factor()
	{
		return ch_height(left) - ch_height(right);
	}

	AVLTree* right_rotation(AVLTree* Q)
	{
		AVLTree* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return	P;
	}

	AVLTree* left_rotation(AVLTree* P)
	{
		AVLTree* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		Q->update_height();
		P->update_height();
		return	Q;
	}

	AVLTree* balance(AVLTree* node)
	{
		if (node->balance_factor() == 2)
		{
			if (node->left->balance_factor() == -1)
				node->left = left_rotation(node->left);
			node = node->right_rotation(node);
		}
		else if (node->balance_factor() == -2)
		{
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);
			node = node->left_rotation(node);
		}
		return node;
	}

	AVLTree* _insert_node(int target, AVLTree* node)
	{
		if (target < node->value)
		{
			if (!node->left)
				node->left = new AVLTree(target);
			else
				node->left = _insert_node(target, node->left);
		}
		else
		{
			if (!node->right)
				node->right = new AVLTree(target);
			else
				node->right = _insert_node(target, node->right);
		}
		node->update_height();
		return balance(node);
	}

	pair<bool, int> _lower_bound(int target,AVLTree* cur, int result = INT_MAX)
	{
		if (!cur)
			return { result != INT_MAX, result };

		if (cur->value == target)
			return { true, target };

		if (cur->value > target )
		{
			result = cur->value;
			return _lower_bound(target, cur->left, result);
		}
		else
		{
			return _lower_bound(target, cur->right, result);
		}
	}

	pair<bool, int> _upper_bound(int target, AVLTree* cur, int result = INT_MIN)
	{
		if (!cur)
			return { result != INT_MIN, result };

		if (cur->value > target)
		{
			result = cur->value;
			return _upper_bound(target, cur->left, result);
		}
		else
		{
			return _upper_bound(target, cur->right, result);
		}
	}

	void _print_inorder(AVLTree* cur)
	{
		if (!cur)
			return;
		_print_inorder(cur->left);
		cout << cur->value << " -> ";
		_print_inorder(cur->right);
	}

	

public:
	AVLTree(int data) : value(data) {}

	AVLTree* insert_node(int target)
	{
		return _insert_node(target, this);
	}


	pair<bool, int> lower_bound(int target)
	{
		return _lower_bound(target, this);
	}

	pair<bool, int> upper_bound(int target)
	{
		return _upper_bound(target, this);
	}

	void print_inorder()
	{
		_print_inorder(this);
	}

	void print_level_order()
	{
		queue<AVLTree*> q;
		q.push(this);

		while (!q.empty())
		{
			int level_size = q.size();

			for (int i = 0; i < level_size; ++i)
			{
				AVLTree* node = q.front();
				q.pop();

				cout << node->value << " ";

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			cout << endl;
		}
	}

	int upper_bound_count(int target, AVLTree* node) {	// O(logn)
		if (!node)
			return 0;

		if (target < node->value) {
			int sum = 1;
			if (node->right)
				sum += node->right->count;
			return sum + upper_bound_count(target, node->left);

		}
		return upper_bound_count(target, node->right);
	}



};


int main()
{
	AVLTree* tree = new AVLTree(2);
	tree = tree->insert_node(5);
	tree = tree->insert_node(10);
	tree = tree->insert_node(13);
	tree = tree->insert_node(15);
	tree = tree->insert_node(20);
	tree = tree->insert_node(40);
	tree = tree->insert_node(50);
	tree = tree->insert_node(70);

	cout << tree->upper_bound(2).second;		
	
}

