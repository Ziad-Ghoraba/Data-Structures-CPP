#include <iostream>
#include <map>
#include <vector>
using namespace std;


class trie
{
private:
	map<char, trie*> child;
	bool isLeaf = {};//initialize to false

public:
	void insert(string str)
	{
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i];
			if (cur->child.find(c) == cur->child.end())
				cur->child[c] = new trie();
			cur = cur->child[c];
		}
		cur->isLeaf = true;
	}

	bool word_exist(string str)
	{
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i];
			if (cur->child.find(c) == cur->child.end())
				return false;
			cur = cur->child[c];
		}
		return cur->isLeaf;
	}

};






int main()
{
	vector<string> vec = { "ax", "xb", "yz", "ay" };
	string s = "axbyz";
	trie* t = new trie();
	t->insert("Hello");
	t->insert("Ziad");
	t->insert("Ghoraba");

	cout << t->word_exist("Ziad") << endl;
	cout << t->word_exist("Hello") << endl;
	cout << t->word_exist("Ghoraba") << endl;
	cout << t->word_exist("ghoraba") << endl;
}
