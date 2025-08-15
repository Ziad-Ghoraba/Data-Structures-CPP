#include <iostream>
#include <cctype>
#include <string>
#include <cassert>
#include<vector>
using namespace std;


int hash_string(string str, int n) 
{
    long long nn = n; //nn for overflow 
    long long sum = 0;
    for (int i = 0; i <(int) str.size(); i++)
    {
        sum = (sum * 26 + str[i] - 'a') % nn;
    }
    return  sum % nn;
}

int hash_string_lower_upper_digit(string str, int n = 65407)
{
    int base = 2 * 26 + 10;
    long long nn = n; //nn for overflow 
    long long sum = 0;
    int value = 0;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (islower(str[i]))
            value = str[i] - 'a';
        else if (isupper(str[i]))
            value = str[i] - 'A' + 26;
        else if (isdigit(str[i]))
            value = str[i] - '0' + 26 + 26;
        else
            assert(false);

        sum = (sum * base + value) % nn;
    }
    return  sum % nn;
}


int folding_for_hashing(string str, int n = 65407)
{
    int base = 2 * 26 + 10;
    long long nn = n; //nn for overflow 
    long long total_sum = 0;
    int value = 0;
    for (int i = 0; i < (int)str.size();)
    {
        int t = i;
        long long sum = 0;
        while (t < i + 4 && t < (int)str.size())
        {
            if (islower(str[i]))
                value = str[i] - 'a';
            else if (isupper(str[i]))
                value = str[i] - 'A' + 26;
            else if (isdigit(str[i]))
                value = str[i] - '0' + 26 + 26;
            else
                assert(false);

            sum = (sum * base + value) % nn;
            t++;
        }
        total_sum += sum;
        i += 4;
        
    }
    return total_sum % nn;
}

//---------------------------------------------------------------------------------------
struct SomeObject
{
    const static int INTERNAL_LIMIT = 2147483647;
    string str1, str2;
    int num;

    int hash()
    {
        long long res = folding_for_hashing(str1 + str2 + to_string(num), 2147483647);
        return res % INTERNAL_LIMIT;
    }
};
//---------------------------------------------------------------------------------------

struct PhoneEntry
{
	const static int INTERNAL_LIMIT = 65407;
	string name;		 // key
	string phone_number; // data

	int hash()
	{
		return hash_string(name, INTERNAL_LIMIT);
	}

	PhoneEntry(string name, string phone_number) : name(name), phone_number(phone_number)
	{
	}

	void print()
	{
		cout << "(" << name << ", " << phone_number << ")  ";
	}
};
//------------------------------------------------------------------------------------------

class PhoneHashTable
{
private:
	int table_size;
	double limit_load_factor;
	vector<vector<PhoneEntry>> table;
	// we can use others: e.g. list<PhoneEntry>

	double loadFactor() {
		int totalElements = 0;
		for (const auto& bucket : table) {
			totalElements += bucket.size();
		}

		int numberOfBuckets = table.size();
		return (double)totalElements / numberOfBuckets;
	}

	void rehashing()
	{
		table_size = table_size * 2;
		vector<vector<PhoneEntry>> newTable(table_size);
		for(auto it:table)
			for (auto it2 : it)
			{
				int idx = it2.hash() % table_size;
				newTable[idx].push_back(it2);
			}
		table = move(newTable);
		
	}

public:
	PhoneHashTable(int table_size = 10, double limit_load_factor = 0.75) : table_size(table_size), limit_load_factor(limit_load_factor)
	{
		table.resize(table_size);
	}

	bool get(PhoneEntry& phone)
	{
		int idx = phone.hash() % table_size;

		for (int i = 0; i < (int)table[idx].size(); ++i)
		{
			if (table[idx][i].name == phone.name)
			{
				phone = table[idx][i];
				return true;
			}
		}
		return false;
	}

	


	void put(PhoneEntry phone)
	{
		double lf = loadFactor();
		if (lf > limit_load_factor)
			rehashing();
		int idx = phone.hash() % table_size;

		for (int i = 0; i < (int)table[idx].size(); ++i)
		{
			if (table[idx][i].name == phone.name)
			{
				table[idx][i] = phone; // exist => update
				return;
			}
		}
		table[idx].push_back(phone);
	}

	bool remove(PhoneEntry phone)
	{
		int idx = phone.hash() % table_size;
		for (int i = 0; i < (int)table[idx].size(); ++i)
		{
			if (table[idx][i].name == phone.name)
			{
				// Swap with last and remove last in O(1)
				swap(table[idx][i], table[idx].back());
				table[idx].pop_back();
				return true;
			}
		}
		return false;
	}

	void print_all()
	{
		for (int hash = 0; hash < table_size; ++hash)
		{
			if (table[hash].size() == 0)
				continue;

			cout << "Hash " << hash << ": ";
			for (int i = 0; i < (int)table[hash].size(); ++i)
				table[hash][i].print();
			cout << "\n";
		}
	}
};

int main()
{
    cout << folding_for_hashing("aabcdefgAxT334gfg");

}

/// Another collision resolution technique used in hash tables is probing. Take some time to read and learn more about it.