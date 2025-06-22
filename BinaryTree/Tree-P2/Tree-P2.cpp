#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include<math.h>
#include<string>
using namespace std;

struct TreeNode
{
	int val{};
	TreeNode* left{};
	TreeNode* right{};

	TreeNode(int val) : val(val) {};
};


struct BinaryTree
{
	TreeNode* root{};
	BinaryTree(int root_value) : root(new TreeNode(root_value)) {};

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode* current = this->root;
		// iterate on the path, create all necessary TreeNodes
		for (int i = 0; i < (int)values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new TreeNode(values[i]);
				else
					assert(current->left->val == values[i]);
				current = current->left;
			}
			else {
				if (!current->right)
					current->right = new TreeNode(values[i]);
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
	}

	void print_in_order(TreeNode* current = nullptr)
	{
		if (current == nullptr)
			current = root;

		if (current->left)
			print_in_order(current->left);

		cout << current->val << " ";

		if (current->right)
			print_in_order(current->right);
	}

	int find_max(TreeNode* current = nullptr, int Max = 0)
	{
		if (current == nullptr)
			current = root;
		Max = max(current->val, Max);

		if (current->left)
			Max = max(find_max(current->left, Max), Max);

		if (current->right)
			Max = max(find_max(current->right, Max), Max);

		return Max;
	}

	int find_max_2()
	{
		return _find_max_2(root);
	}

	int sum_of_all_nodes()
	{
		return _sum_of_all_nodes(root);
	}

	int maxDepth(TreeNode* root)
	{
		if (!root)
			return 0;

		return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
	}

	bool hasPathSum(TreeNode* root, int targetSum = 1, int currentSum = 0) {
		if (!root)
			return false;

		currentSum += root->val;
		if (!root->left && !root->right && currentSum == targetSum)
			return true;

		bool l = hasPathSum(root->left, targetSum, currentSum);
		bool r = hasPathSum(root->right, targetSum, currentSum);

		if (l || r)
			return true;
		else
			return false;
	}

	int sumOfLeftLeaves(TreeNode* root, int Sum = 0, bool l = true, bool x = true) {
		if (!root || x && root->left == nullptr && root->right == nullptr)
			return 0;


		Sum = sumOfLeftLeaves(root->left, Sum, true, false);
		if (!root->left && !root->right && l)
			Sum += root->val;

		if (root->right)
			Sum += sumOfLeftLeaves(root->right, Sum, false, false);

		return Sum;
	}

	bool is_perfect_formula(TreeNode* root)
	{
		int nodes = no_of_nodes(root);

		int levels = log2(nodes + 1);
		if (levels == log2(nodes + 1)) return true; else return false;
	}

	bool is_perfect()
	{
		if (!root)
			return false;
		return _is_perfect(root);
	}

	bool is_full_BT()
	{
		return _is_full_BT(root);
	}

	int no_of_nodes(TreeNode* root) //O(n) time & memeory
	{
		if (!root)
			return 0;

		return 1 + no_of_nodes(root->left) + no_of_nodes(root->right);
	}

	int no_of_levels_prefectTree(TreeNode* root)
	{
		if (!root)
			return 0;
		return 1 + no_of_levels_prefectTree(root->left);
	}

	void level_order_traversal1()
	{
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			cout << cur->val << " ";
			q.pop();

			if(cur->left)
				q.push(cur->left);

			if (cur->right)
				q.push(cur->right);
		}
	}

	void level_order_traversal2()
	{
		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty())
		{
			int sz = q.size();
			cout << "Level" << level << ": ";
			while (sz--)
			{
				TreeNode* temp = q.front();
				q.pop();
				cout << temp->val << " ";
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
			level++;
			cout << "\n";
		}
	}

	vector<vector<int>> zigzagLevelOrder() {
		vector<vector<int>> vec;
		if (!root)
			return vec;
		bool even = false;
		queue<TreeNode*> d;
		d.push(root);
		while (!d.empty())
		{
			int sz = d.size();
			int ss = sz;
			vector<int> v;

			while (sz--)
			{
				TreeNode* temp = d.front();
				d.pop();
				if (even)
					v.insert(v.begin(), temp->val);
				else
					v.push_back(temp->val);

				if (temp->left)
					d.push(temp->left);

				if (temp->right)
					d.push(temp->right);
			}

			vec.push_back(v);
			v.clear();
			even = !even;
		}
		return vec;
	}

	string parenthesize()
	{
		return _parenthesize(root);
	}

	bool isSymmetric(TreeNode* root) {
		return _isSymmetric(root);
	}

	vector<string> duplicates_sub_trees()
	{
		vector<string> Duplicates;
		if (!root)
			return Duplicates;
		vector<string> Uniq;
		_duplicates_sub_trees(root, Duplicates);
		for (int i = 0; i < Duplicates.size(); i++)
		{
			if ((find(Duplicates.begin() + i + 1, Duplicates.end(), Duplicates[i]) != Duplicates.end()) 
				&& (find(Uniq.begin(), Uniq.end(), Duplicates[i]) == Uniq.end()))
			{
				int op = count(Duplicates[i].begin(), Duplicates[i].end(), '(');
				int cl = count(Duplicates[i].begin(), Duplicates[i].end(), ')');
				for (int j = 0; j < op - cl; j++)
					Duplicates[i] += ")";
				Uniq.push_back(Duplicates[i]);
			}
		}
		return Uniq;
	}


private:
	int _find_max_2(TreeNode* root)
	{
		if (!root)
			return 0;

		int ml = _find_max_2(root->left);
		int mr = _find_max_2(root->right);

		return max(ml, max(mr, root->val));
	}

	int _sum_of_all_nodes(TreeNode* root)
	{
		if (!root)
			return 0;
		return root->val + _sum_of_all_nodes(root->left) + _sum_of_all_nodes(root->right);
	}

	bool _is_full_BT(TreeNode* root)
	{
		if (!root)
			return false;

		if (!(root->left && root->right || !root->left && !root->right))
			return false;

		bool l = true, r = true;
		if (root->left)
			l =_is_full_BT(root->left);
		if (root->right)
			r = _is_full_BT(root->right);

		return l && r;
	}

	bool _is_perfect(TreeNode* root)
	{
		if (!root)
			return true;
		
		if (no_of_nodes(root->left) != no_of_nodes(root->right))
			return false;

		return _is_perfect(root->left) && _is_perfect(root->right);
	}

	string _parenthesize(TreeNode* root)
	{
		if (!root)
			return "()";
		
		string res = "(" + to_string(root->val);
		res += _parenthesize(root->left);
		res += _parenthesize(root->right);

		res += ")";
		return res;
	}

	bool _isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return _check(root->left, root->right);
	}

	bool _check(TreeNode* left, TreeNode* right)
	{
		if (!left && !right)
			return true;
		if (!left && right || left && !right || left->val != right->val)
			return false;

		return _check(left->left, right->right) && _check(left->right, right->left);
	}

	string _duplicates_sub_trees(TreeNode* root, vector<string>& Duplicates)
	{
		if (!root)
			return "()";
		string s = "(" + to_string(root->val);
		s+= _duplicates_sub_trees(root->left, Duplicates);
		s+= _duplicates_sub_trees(root->right, Duplicates);

		if (root->left || root->right)
			Duplicates.push_back(s);

		return s;
	}
};





int main()
{
	BinaryTree* binaryTree = new BinaryTree(1);

	binaryTree->add({ 2, 3 }, { 'L', 'L' });
	binaryTree->add({ 4, 5, 6, 8, 9 }, { 'R', 'R', 'R', 'R', 'R' });
	binaryTree->add({ 4, 2, 3 }, { 'R', 'L', 'L' });
	binaryTree->add({ 4, 5, 6, 7 }, { 'R', 'R', 'L', 'L' });
	binaryTree->add({ 4, 5, 6, 8, 9 }, { 'R', 'R', 'L', 'R', 'R' });
	binaryTree->add({ 4, 5, 6, 7 }, { 'R', 'R', 'R', 'L' });

	binaryTree->print_in_order();

	cout << endl;
	cout << binaryTree->parenthesize() << endl;

	vector<string> vs = binaryTree->duplicates_sub_trees();
	for (auto it : vs)
		cout << it << "  ";
}

