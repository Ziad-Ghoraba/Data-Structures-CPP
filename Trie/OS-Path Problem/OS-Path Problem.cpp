#include <iostream>
#include <map>
#include <vector>
using namespace std;


class trie
{
private:
	map<string, trie*> child;
	bool isLeaf = {};//initialize to false

public:
	void insert(vector<string>& path)
	{
		trie* cur = this;
		for (int i = 0; i < path.size(); i++)
		{
			string c = path[i];
			if (cur->child.find(c) == cur->child.end())
				cur->child[c] = new trie();
			cur = cur->child[c];
		}
		cur->isLeaf = true;
	}

	bool word_exist(vector<string>& path)
	{
		trie* cur = this;
		for (int i = 0; i < path.size(); i++)
		{
			string c = path[i];
			if (cur->child.find(c) == cur->child.end())
				return false;
			cur = cur->child[c];
		}
		return true;
	}

	
};






int main()
{
	trie tree;
	vector<string> path;

	path = { "home", "software", "eclipse" };
	tree.insert(path);
	path = { "home", "software", "eclipse", "bin" };
	tree.insert(path);
	path = { "home", "installed", "gnu" };
	tree.insert(path);
	path = { "user", "mostafa", "tmp" };
	tree.insert(path);

	path = { "user", "mostafa", "tmp" };
	cout << tree.word_exist(path) << "\n"; // 1
	path = { "user", "mostafa" };
	cout << tree.word_exist(path) << "\n"; // 1
	path = { "user", "most" };
	cout << tree.word_exist(path) << "\n"; // 0
	path = { "user", "mostafa", "private" };
	cout << tree.word_exist(path) << "\n"; // 0

	return 0;
	
}
