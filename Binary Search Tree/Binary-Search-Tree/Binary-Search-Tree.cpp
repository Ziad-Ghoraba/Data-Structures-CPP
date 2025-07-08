#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <deque>

#include <tuple>

using namespace std;

struct TreeNode {
	int val{ };
	TreeNode* left{ };
	TreeNode* right{ };
	TreeNode(int val) : val(val) {}
};


struct DoublyLinkedListNode
{
	int val{ };
	DoublyLinkedListNode* next{};
	DoublyLinkedListNode* prev{};
	DoublyLinkedListNode(int val) : val(val) {}
};


struct BinaryTree {
	TreeNode* root{ };
	BinaryTree(int root_value) :
		root(new TreeNode(root_value)) {
	}

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

	void print_inorder() {
		_print_inorder(root);
		cout << "\n";
	}
	
	bool normal_search(int val) // Time Complexity: O(n)
	{
		return _normal_search(root, val);
	}

	bool BST(int val)// Time Complexity: O(h)
	{
		return _BST(root, val);
	}

	void insert(int val)// Time Complexity: O(h)
	{
		_insert(root, val);
	}

	int minimum()
	{
		return _minimum(root);
	}

	int successor(int val)
	{
		vector<int> vec;
		_inorder_list(root, vec);

		for (auto it : vec)
			if (it > val)
				return it;
		return -1;
	}

	TreeNode* lowestCommonAncestor(TreeNode* p, TreeNode* q) {
		return _lowestCommonAncestor(root, p, q);
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root =
			sort_BST(nums, 0, nums.size() - 1);
		return root;

	}

	DoublyLinkedListNode* treeToDoubleList()
	{
		if (!root)
			return nullptr;
		vector<int> list;
		_inorder_list(root, list);
		DoublyLinkedListNode* first = new DoublyLinkedListNode(list[0]);
		DoublyLinkedListNode* cur = first;
		DoublyLinkedListNode* next = nullptr;
		DoublyLinkedListNode* prev = nullptr;

		for (int i = 1; i < list.size(); i++)
		{
			next = new DoublyLinkedListNode(list[i]);
			cur->next = next;
			cur->prev = prev;
			prev = cur;
			cur = next;
		}

		cur->prev = prev;
		cur->next = first;
		first->prev = cur;
		
		cur = first;
		for (int i = 0; i < list.size(); i++)
		{
			cout << cur->prev->val << " <- " << cur->val << " -> " << cur->next->val << endl;
			cur = cur->next;
		}

		return first;
	}

	bool isValidBST() {
		vector<int> vec;
		_inorder_list(root, vec);
		for (int i = 1; i < vec.size(); i++)
			if (vec[i - 1] >= vec[i])
				return false;
		return true;

	}

	int minimum_in_BST()
	{
		return _minimum_in_BST(root);
	}

	pair<bool, int> successor_v2(int target) //O(h)
	{
		vector<TreeNode*> vec;
		vec.push_back(nullptr);

		TreeNode* node = get_chain(root, vec, target);
		if (!node)
			return { false, -1 };  // Target not found

		if (node->right)
			return { true, _minimum_in_BST(node->right)}; // Successor is the minimum in the right subtree
		
		vec.pop_back();
		TreeNode* parent = vec.back();
		vec.pop_back();
		while (parent && parent->right == node)
		{
			node = parent;
			parent = vec.back();
			vec.pop_back();
		}
		if (!parent)
			return { false, -1 };
		return { true, parent->val };
	}

	int kthSmallest( int k) {
		if (!root)
			return -1;
		vector<int> vec;
		_inorder_list(root, vec);
		return vec[k - 1];

	}

	TreeNode* Delete(int target)
	{
		return _Delete(root, target);
	}


private:

	void _print_inorder(TreeNode* current) {
		if (!current)
			return;
		_print_inorder(current->left);
		cout << current->val << " ";
		_print_inorder(current->right);
	}

	bool _normal_search(TreeNode* root, int& val, bool s = false)
	{
		if (root->val == val)
			return !s;
		if(!s && root->left)
			s = _normal_search(root->left, val);
		if(!s && root->right)
			s = _normal_search(root->right, val);
		return s;
	}

	bool _BST(TreeNode* root, int& val)
	{
		if (!root)
			return false;
		if (root->val == val)
			return true;
		if (root->val > val)	
			return _BST(root->left, val);
		return _BST(root->right, val);
		
	}

	void _insert(TreeNode* &root,int val)
	{
		if (!root) {
			root = new TreeNode(val);
			return; 
		}
		if (val < root->val)
			_insert(root->left, val);
		else if (val > root->val)
			_insert(root->right, val);
	}

	int _minimum(TreeNode* root)
	{
		if (!root)
			return -1;

		if (!root->left)
			return root->val;

		return _minimum(root->left);
	}

	void _inorder_list(TreeNode* root,vector<int> &vec)
	{
		if (!root)
			return ;
		_inorder_list(root->left, vec);
		vec.push_back(root->val);
		_inorder_list(root->right, vec);
	}

	TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val >= p->val && root->val <= q->val || root->val <= p->val && root->val >= q->val)
			return root;
		if (root->val > max(p->val, q->val))
			return _lowestCommonAncestor(root->left, p, q);
		return _lowestCommonAncestor(root->right, p, q);
	}

	TreeNode* sort_BST(vector<int>& nums, int s, int e)
	{
		if (s > e)
			return nullptr;
		int mid = (s + e) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		if (nums.size() == 1)
			return root;

		root->left = sort_BST(nums, s, mid - 1);

		root->right = sort_BST(nums, mid + 1, e);

		return root;

	}

	TreeNode* get_chain(TreeNode* root, vector<TreeNode*> &vec, int target)
	{
		if (!root)
			return nullptr;
		vec.push_back(root);
		if (root->val == target)
			return root;

		if (root->val > target)
			return get_chain(root->left, vec, target);

		return get_chain(root->right, vec, target);
	}

	int _minimum_in_BST(TreeNode* root)
	{
		if (!root)
			return -1;
		if (root->left)
			return _minimum_in_BST(root->left);
		return root->val;
	}

	TreeNode* _minimum_node(TreeNode* root)
	{
		if (!root)
			return nullptr;
		if (root->left)
			return _minimum_node(root->left);
		return root;
	}

	TreeNode* createBST(vector<int>& nums, int left, int right) {
		if (left > right) return NULL;
		int mid = left + (right - left) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = createBST(nums, left, mid - 1);
		node->right = createBST(nums, mid + 1, right);
		return node;
	}

	TreeNode* _Delete(TreeNode* root, int target)
	{
		if (!root)
			return nullptr;
		if (root->val > target)
			root->left = _Delete(root->left, target);
		else if (root->val < target)
			root->right = _Delete(root->right, target);
		else
		{
			TreeNode* temp = root;
			if (!root->right && !root->left)
				root =  nullptr;
			else if (!root->left)
				root =  root->right;
			else if (!root->right)
				root =  root->left;

			else {
				TreeNode* min = _minimum_node(root->right);
				root->val = min->val;
				root->right = _Delete(root->right, root->val);
				temp = nullptr;
			}
			if (temp)
				delete temp;
		}
		return root;
	}
};

int main() {

	// 				 50
	//		30							70
	//	10		40				60				80
	//     12                55                        90

	BinaryTree tree(50);
	tree.add({ 30, 10, 12 }, { 'L', 'L', 'R' });
	tree.add({ 30, 40 }, { 'L', 'R' });
	tree.add({ 70, 60, 55 }, { 'R', 'L', 'L' });
	tree.add({ 70, 80, 90 }, { 'R', 'R', 'R' });

	tree.print_inorder();
	tree.Delete(50);
	tree.print_inorder();

	return 0;
}

