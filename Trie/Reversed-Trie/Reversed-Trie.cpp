#include <iostream>
#include <vector>
using namespace std;


class trie
{
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR] = {}; //initialize all to nullptr
	bool isLeaf = {};//initialize to false

public:

	void insert(string str)
	{
		reverse(str.begin(), str.end());
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i] - 'a';
			if (!cur->child[c])
				cur->child[c] = new trie();
			cur = cur->child[c];
		}
		cur->isLeaf = true;
	}


	bool suffix_exist(string str)
	{
		reverse(str.begin(), str.end());
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i] - 'a';
			if (!cur->child[c])
				return false;
			cur = cur->child[c];
		}
		return true;
	}


};


int main()
{
	trie t = trie();

	t.insert("hello");
	cout << t.suffix_exist("ll");
}
