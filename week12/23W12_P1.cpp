#include <iostream>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

struct Entry
{
	int key;
	string value;
	int valid;

	Entry()
	{
		key = 0;
		value = "";
		valid = NOITEM;
	}
	Entry(int _key, string _value)
	{
		key = _key;
		value = _value;
		valid = ISITEM;
	}
};

class HashTable
{
private:
	Entry* hashTable;
	int capacity;
public:
	HashTable(int _capacity)
	{
		capacity = _capacity;
		hashTable = new Entry[capacity];
	}

	int hashFunc(int key)
	{
		return key % capacity;
	}

	void put(int key, string value)
	{
		int idx = hashFunc(key);
		int probing = 1;

		while (hashTable[idx].valid == ISITEM && probing <= capacity)
		{
			idx = hashFunc(idx + 1);
			probing++;
		}
		if (probing > capacity) return;
		cout << probing + idx << '\n';

		hashTable[idx] = Entry(key, value);
	}

	void erase(int key)
	{
		int idx = hashFunc(key);
		int probing = 1;

		while (hashTable[idx].valid != NOITEM && probing <= capacity)
		{
			if (hashTable[idx].valid == ISITEM && hashTable[idx].key == key)
			{
				cout << hashTable[idx].value << '\n';
				hashTable[idx].valid = AVAILABLE;
				return;
			}
			idx = hashFunc(idx + 1);
			probing++;
		}
		cout << "None\n";
	}

	string find(int key)
	{
		int idx = hashFunc(key);
		int probing = 1;

		while (hashTable[idx].valid != NOITEM && probing <= capacity)
		{
			if (hashTable[idx].valid == ISITEM && hashTable[idx].key == key)
			{
				return hashTable[idx].value;
			}
			idx = hashFunc(idx + 1);
			probing++;
		}
		return "None";
	}
	void vacant() {
		int idx = 0;
		int count = 0;
		while (idx < capacity) {
			if (hashTable[idx].valid != ISITEM) count++;
			idx++;
		}
		cout << count << "\n";
	}
};

int main()
{
	int test, size;
	cin >> test >> size;
	HashTable ht = HashTable(size);
	while (test--)
	{
		string s, val;
		int x;
		cin >> s;
		if (s == "put")
		{
			cin >> x >> val;
			ht.put(x, val);
		}
		else if (s == "find")
		{
			cin >> x;
			cout << ht.find(x) << '\n';
		}
		else if (s == "erase")
		{
			cin >> x;
			ht.erase(x);
		}
		else if (s == "vacant")
		{
			ht.vacant();
		}
	}

}