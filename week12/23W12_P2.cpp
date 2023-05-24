#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

struct Entry
{
	int valid;
	bool log;
	string id;
	string pw;
	
	Entry()
	{
		id = "";
		pw = "";
		valid = NOITEM;
		log = false;
	}
	Entry(string _id, string _value)
	{
		id = _id;
		pw = _value;
		valid = ISITEM;
		log = false;
	}
};

class HashTable
{
private:
	int capacity;
	Entry* hashTable;
public:
	HashTable(int _capacity)
	{
		capacity = _capacity;
		hashTable = new Entry[capacity];
	}
	int toKey(string s)
	{
		int code = 0;
		int multi = 1;
		for (size_t i{ 0 }; i < 6; i++)
		{
			int digit = s[i] - 'a';
			code += digit * multi;
			multi *= 26;
		}
		return code;
	}
	int hashFunc(int key)
	{
		return key % capacity;
	}
	void signup(string id, string pw)
	{
		int key = toKey(id);
		int idx = hashFunc(key);
		while (hashTable[idx].valid == ISITEM)
		{
			if (hashTable[idx].id == id)
			{
				cout << "Invalid " << hashTable[idx].pw << '\n';
				return;
			}
			idx = hashFunc(idx + 1);
		}
		hashTable[idx] = Entry(id, pw);
		cout << "Submit\n";
	}
	void login(string id, string pw)
	{
		int key = toKey(id);
		int idx = hashFunc(key);
		while (hashTable[idx].valid == ISITEM)
		{
			if (hashTable[idx].id == id && hashTable[idx].pw == pw && hashTable[idx].log == true)
			{
				cout << "Quit\n";
				return;
			}
			else if (hashTable[idx].id == id && hashTable[idx].pw == pw && hashTable[idx].log == false)
			{
				hashTable[idx].log = true;
				cout << "Submit\n";
				return;
			}
			idx = hashFunc(idx + 1);
		}
		cout << "Invalid\n";
	}
	void logout(string id)
	{
		int key = toKey(id);
		int idx = hashFunc(key);
		while (hashTable[idx].valid == ISITEM)
		{
			if (hashTable[idx].id == id)
			{
				hashTable[idx].log = false;
				cout << "Submit\n";
				return;
			}
			idx = hashFunc(idx + 1);
		}
	}
	void change(string id, string pw)
	{
		int key = toKey(id);
		int idx = hashFunc(key);
		while (hashTable[idx].valid == ISITEM)
		{
			if (hashTable[idx].id == id)
			{
				hashTable[idx].pw = pw;
				cout << "Submit\n";
				return;
			}
			idx = hashFunc(idx + 1);
		}
	}
};

int main()
{
	int test;
	cin >> test;
	HashTable ht = HashTable(500000);
	while (test--)
	{
		string s, id, pw;
		cin >> s;
		if (s == "signup")
		{
			cin >> id >> pw;
			ht.signup(id, pw);
		}
		else if (s == "login")
		{
			cin >> id >> pw;
			ht.login(id, pw);
		}
		else if (s == "logout")
		{
			cin >> id;
			ht.logout(id);
		}
		else if (s == "change")
		{
			cin >> id >> pw;
			ht.change(id, pw);
		}
	}
}