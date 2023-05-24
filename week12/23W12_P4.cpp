#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

struct Entry
{
	int id;
	int group;
	int valid;
	bool pre;
	string name;
	Entry()
	{
		id = 0;
		group = 0;
		name = "";
		pre = false;
		valid = NOITEM;
	}
	Entry(int _id, int _group, string _name)
	{
		id = _id;
		group = _group;
		name = _name;
		pre = false;
		valid = ISITEM;
	}
};
class HashTable
{
private:
	int capacity;
	Entry* idTable;
	Entry* nameTable;
public:
	HashTable(int c)
	{
		capacity = c;
		nameTable = new Entry[capacity];
		idTable = new Entry[capacity];
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
	void add(int x, int c, string s)
	{
		int nameIdx = hashFunc(toKey(s));
		int idIdx = hashFunc(x);

		while (nameTable[nameIdx].valid == ISITEM)
			nameIdx = hashFunc(nameIdx + 1);
		nameTable[nameIdx] = Entry(x, c, s);

		while (idTable[idIdx].valid == ISITEM)
			idIdx = hashFunc(idIdx + 1);
		idTable[idIdx] = Entry(x, c, s);
	}
	void erase(int x)
	{
		int idIdx = hashFunc(x);
		string s;
		while (idTable[idIdx].valid != NOITEM)
		{
			if (idTable[idIdx].valid == ISITEM && idTable[idIdx].id == x)
			{
				s = idTable[idIdx].name;
				idTable[idIdx].valid = AVAILABLE;
			}
			idIdx = hashFunc(idIdx + 1);
		}
		int nameIdx = hashFunc(toKey(s));
		while (nameTable[nameIdx].valid != NOITEM)
		{
			if (nameTable[nameIdx].valid == ISITEM && nameTable[nameIdx].name == s)
			{
				nameTable[nameIdx].valid = AVAILABLE;
				cout << nameTable[nameIdx].name << ' '
					<< nameTable[nameIdx].group << '\n';
				return;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
	}
	string getName(int x)
	{
		int idIdx = hashFunc(x);
		string s;
		while (idTable[idIdx].valid != NOITEM)
		{
			if (idTable[idIdx].valid == ISITEM && idTable[idIdx].id == x)
			{
				s = idTable[idIdx].name;
				return s;
			}
			idIdx = hashFunc(idIdx + 1);
		}
	}
	void change(int x, int c)
	{
		int idIdx = hashFunc(x);
		string s;
		while (idTable[idIdx].valid != NOITEM)
		{
			if (idTable[idIdx].valid == ISITEM && idTable[idIdx].id == x)
			{
				s = idTable[idIdx].name;
				idTable[idIdx].group = c;
			}
			idIdx = hashFunc(idIdx + 1);
		}
		int nameIdx = hashFunc(toKey(s));
		while (nameTable[nameIdx].valid != NOITEM)
		{
			if (nameTable[nameIdx].valid == ISITEM && nameTable[nameIdx].id == x)
			{
				nameTable[nameIdx].group = c;
				return;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
	}
	void present(string s)
	{
		int nameIdx = hashFunc(toKey(s));
		int x;
		bool found = false;
		while (nameTable[nameIdx].valid != NOITEM)
		{
			if (nameTable[nameIdx].valid == ISITEM && nameTable[nameIdx].name == s)
			{
				x = nameTable[nameIdx].id;
				nameTable[nameIdx].pre = true;
				cout << nameTable[nameIdx].id << " " << nameTable[nameIdx].group << '\n';
				found = true;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
		if (!found)
		{
			cout << "Invalid\n";
			return;
		}
		int idIdx = hashFunc(x);
		while (idTable[idIdx].valid != NOITEM)
		{
			if (idTable[idIdx].valid == ISITEM && idTable[idIdx].id == x)
			{
				idTable[idIdx].pre = true;
				return;
			}
			idIdx = hashFunc(idIdx + 1);
		}
	}
	void absent(string s)
	{
		int nameIdx = hashFunc(toKey(s));
		int x;
		bool found = false;
		while (nameTable[nameIdx].valid != NOITEM)
		{
			if (nameTable[nameIdx].valid == ISITEM && nameTable[nameIdx].name == s)
			{
				x = nameTable[nameIdx].id;
				nameTable[nameIdx].pre = false;
				found = true;
				cout << nameTable[nameIdx].id << " " << nameTable[nameIdx].group << '\n';
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
		if (!found)
		{
			cout << "Invalid\n";
			return;
		}
		int idIdx = hashFunc(x);
		while (idTable[idIdx].valid != NOITEM)
		{
			if (idTable[idIdx].valid == ISITEM && idTable[idIdx].id == x)
			{
				idTable[idIdx].pre = false;
				return;
			}
			idIdx = hashFunc(idIdx + 1);
		}
		cout << "Invalid\n";
	}
	int preCount()
	{
		int count{0};
		for (int i{0}; i<capacity; i++)
		{
			if (idTable[i].pre == true && idTable[i].valid == ISITEM)
				count++;
		}
		return count;
	}
};

int main() 
{
	int t;
	cin >> t;
	HashTable ht = HashTable(200000);
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			int a, c;
			string b;
			cin >> a >> c >> b;
			ht.add(a, c, b);
		}
		else if (cmd == "delete") {
			int a;
			cin >> a;
			ht.erase(a);
		}
		else if (cmd == "change") {
			int a, c;
			cin >> a >> c;
			ht.change(a, c);
		}
		else if (cmd == "present") {
			string a;
			cin >> a;
			ht.present(a);
		}
		else if (cmd == "absent") {
			string a;
			cin >> a;
			ht.absent(a);
		}
		else if (cmd == "name") {
			int a;
			cin >> a;
			cout << ht.getName(a) << '\n';
		}
	}
	cout << ht.preCount() << endl;
}