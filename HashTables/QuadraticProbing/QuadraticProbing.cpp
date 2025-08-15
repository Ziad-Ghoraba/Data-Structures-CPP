#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

int hash_string(string str, int n = 65407)
{
	long long nn = n;
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum = (sum * 26 + str[i] - 'a') % nn;
	return sum % nn;
}

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

class PhoneHashTable
{
private:
	int table_size;
	vector<PhoneEntry*> table;
	PhoneEntry* deleted{};

public:
	PhoneHashTable(int table_size) : table_size(table_size)
	{
		table.resize(table_size);
		deleted = new PhoneEntry("", "");
	}

	void put(PhoneEntry phone)
	{

		int idx = phone.hash() % table_size;
		int step = 0, original_idx = idx;

		do
		{
			if (table[idx] == deleted || !table[idx])
			{
				table[idx] = new PhoneEntry(phone.name, phone.phone_number);
				return;
			}
			else if (table[idx]->name == phone.name)
			{
				table[idx]->phone_number == phone.phone_number;
				return; // update
			}
			++step;
			idx = (original_idx + step * step) % table_size;
		} while (idx != original_idx);

		rehashing();
		put(phone);
	}

	bool remove(PhoneEntry phone)
	{
		int idx = phone.hash() % table_size;
		int step = 0, original_idx = idx;

		do
		{
			if (!table[idx])
				break;
			if (table[idx] != deleted && table[idx]->name == phone.name)
			{
				delete table[idx];
				table[idx] = deleted;
				return true;
			}
			++step;
			idx = (original_idx + step * step) % table_size;
		} while (idx != original_idx);
		return false;
	}

	bool get(PhoneEntry& phone)
	{
		int idx = phone.hash() % table_size;
		int step = 0, original_idx = idx;

		do
		{
			if (!table[idx])
				break;
			if (table[idx] != deleted && table[idx]->name == phone.name)
			{
				phone.phone_number = table[idx]->phone_number;
				return true;
			}
			++step;
			idx = (original_idx + step * step) % table_size;
		} while (idx != original_idx);
		return false;
	}

	void rehashing()
	{
		cout << "Rehashing\n";
		PhoneHashTable new_table(2 * table_size);

		for (int hash = 0; hash < table_size; ++hash)
		{
			if (table[hash] == deleted || !table[hash])
				continue;

			new_table.put(*table[hash]);
		}
		table_size *= 2;
		table = new_table.table;
	}

	void print_all()
	{
		for (int hash = 0; hash < table_size; ++hash)
		{
			cout << hash << " ";
			if (table[hash] == deleted)
				cout << " X ";
			else if (!table[hash])
				cout << " E ";
			else
				table[hash]->print();
			cout << "\n";
		}
		cout << "******************\n";
	}
};

int main()
{

}