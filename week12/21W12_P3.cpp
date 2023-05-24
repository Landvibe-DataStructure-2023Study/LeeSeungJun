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
	int divisor;
public:
	HashTable(int _capacity, int _divisor)
	{
		capacity = _capacity;
		divisor = _divisor;
		hashTable = new Entry[capacity];
	}

	int hashFunc(int key)
	{
		return key % capacity;
	}

	int hashFuncTwo(int key)
	{
		return divisor - (key % divisor);
	}

	void put(int key, string value)
	{
		int idx = hashFunc(key);
		int probing = 1;

		while (hashTable[idx].valid == ISITEM && probing <= capacity)
		{
			idx = hashFunc(idx + hashFuncTwo(key));
			probing++;
		}
		cout << probing << '\n';
		if (probing > capacity) return;

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
				hashTable[idx].valid = AVAILABLE;
				return;
			}
			idx = hashFunc(idx + hashFuncTwo(key));
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
			idx = hashFunc(idx + hashFuncTwo(key));
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
	int test, size, divisor;
	cin >> test >> size >> divisor;
	HashTable ht = HashTable(size, divisor);
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
	}

}