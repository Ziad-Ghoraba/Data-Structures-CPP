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
	void insert(string str, int index)
	{
		if (index == (int)str.size())
		{
			isLeaf = true;
		}
		else
		{
			int cur = str[index] - 'a';
			if (child[cur] == nullptr)
				child[cur] = new trie();
			child[cur]->insert(str, index + 1);

		}
	}

	void insert(string str)
	{
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

	bool word_exist(string str)
	{
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i] - 'a';
			if (!cur->child[i]) return false;
			cur = cur->child[c];
		}
		return cur->isLeaf;
	}

	bool perfix_exist(string str, int index = 0)
	{
		if (index == (int)str.size())
			return true;
		if (!child[str[index] - 'a'])
			return false;
		return child[str[index] - 'a']->perfix_exist(str, index + 1);
	}

	bool word_exist(string str, int index = 0)
	{
		if (index == (int)str.size())
			return isLeaf;
		if (!child[str[index] - 'a'])
			return false;
		return child[str[index] - 'a']->word_exist(str, index + 1);
	}

	bool word_exist_with_1_change(string str)
	{
		//O(L * 26 * L)
		for (int i = 0; i < str.size(); i++)
		{
			char cpy = str[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c == cpy) continue;
				str[i] = c;
				if (word_exist(str, 0))
					return true;
			}
			str[i] = cpy;
		}
		return false;
	}

	string root(string word, int index = 0)
	{
		if (index >= word.size() || !child[word[index] - 'a'])
			return word;
		if (child[word[index] - 'a']->isLeaf)
			return word.substr(0, index + 1);
		return child[word[index] - 'a']->root(word, index + 1);
	}

	void get_all_strings(vector<string>& res)
	{
		string s;
		for (int i = 0; i < 26; i++)
		{
			if (child[i])
			{
				s = (i + 'a');
				if (child[i]->isLeaf)
				{
					res.push_back(s);
				}
				helper(res, child[i], s);
			}
			s = "";
		}
	}

	void helper(vector<string>& res, trie* cur, string s)
	{
		for (int i = 0; i < 26; i++)
		{
			if (cur->child[i])
			{
				s += (i + 'a');
				if (cur->child[i]->isLeaf)
				{
					res.push_back(s);
				}
				helper(res, cur->child[i], s);

				s = s.substr(0, s.size() - 1);
			}
		}

	}

	void auto_complete(const string& str, vector<string>& res)
	{
		if (!perfix_exist(str))
			return;

		trie* cur;
		cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			char c = str[i] - 'a';
			cur = cur->child[c];
		}
		if (cur->isLeaf)
			res.push_back(str);

		helper(res, cur, str);
		return;

	}
};



string replaceWords(vector<string>& dictionary, string sentence) {
	trie* t = new trie();
	for (auto it : dictionary)
		t->insert(it);
	sentence += ' ';
	vector<string> vec;
	string word;
	for (char c : sentence)
	{
		if (c == ' ')
		{
			vec.push_back(word);
			word = "";
			continue;
		}
		word += c;
	}
	string res;
	for (auto it : vec)
	{
		res += t->root(it);
		res += " ";
	}

	return res.substr(0, res.size() - 1);
}


void list_substrs(const string& str, vector<string>& queries)
{
	trie trie;
	//O(s^2)
	for (int i = str.size() - 1; i >= 0; i--)
		trie.insert(str, i);

	//O(L * Q)
	for (int i = 0; i < queries.size(); i++)
		if (trie.perfix_exist(queries[i]))
			cout << queries[i];
}



class MagicDictionary {
public:
	MagicDictionary* child[26] = {};
	bool isLeaf = false;
	MagicDictionary() {
	}

	void buildDict(vector<string> dictionary) {
		for (auto w : dictionary)
			insert(w);
	}

	void insert(string str)
	{
		MagicDictionary* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i] - 'a';
			if (!cur->child[c])
				cur->child[c] = new MagicDictionary();
			cur = cur->child[c];
		}
		cur->isLeaf = true;
	}

	bool search(string searchWord) {

	}
};



int main()
{
	trie tree;

	tree.insert("abcd");
	tree.insert("ab");
	tree.insert("abx");
	tree.insert("abyz");
	tree.insert("xyzw");
	tree.insert("bcd");


	/*vector<string> s;
	tree.auto_complete("ab",s);
	for (auto it : s)
		cout << it<< " ";*/


	MagicDictionary md = MagicDictionary();
	vector<string> s = { "abc", "abx" };
	md.buildDict(s);
	cout << "x";
}
