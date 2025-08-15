#include <iostream>
#include <string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int count_unique_substrings(const string& str ) // Time Complexity O(L^3)
{
	unordered_set<string> s;

	for (int i = 0; i < (int)str.size(); i++)
	{
		for (int j = i; j < (int)str.size(); j++)
		{
			s.insert(str.substr(i, j - i + 1));
		}
	}
	return s.size();
}

int count_matched_substring(const string& str1, const string& str2) // Time Complexity O(L^3)
{
	unordered_set<string> s1;

	for (int i = 0; i < (int)str1.size(); i++)
	{
		for (int j = i; j < (int)str1.size(); j++)
		{
			s1.insert(str1.substr(i, j - i + 1));
		}
	}

	unordered_set<string> s2;

	for (int i = 0; i < (int)str2.size(); i++)
	{
		for (int j = i; j < (int)str2.size(); j++)
		{
			s2.insert(str2.substr(i, j - i + 1));
		}
	}

	int cnt = 0;
	for (auto it : s1)
		cnt += s2.count(it);

	return cnt;
}

int count_anagram_subsrings(const string& str) //Time Complexity O(L^3 log(L))
{
	unordered_set<string> s;

	for (int i = 0; i < (int)str.size(); i++)
	{
		for (int j = i; j < (int)str.size(); j++)
		{
			string sub = str.substr(i, j - i + 1);
			sort(sub.begin(), sub.end()); // O(L Log(L)) /// Note that you can do it with frequency array in O(L) only
			s.insert(sub);

		}
	}
	return s.size();
}

int main()
{
	cout << count_unique_substrings("aaab") << endl;
	cout << count_matched_substring("aaab", "ab") << endl;


}


