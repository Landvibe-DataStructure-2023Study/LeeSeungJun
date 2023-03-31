#include <iostream>
using namespace std;

class Node
{
public:
	Node* next = nullptr;
	Node* prev = nullptr;
	int value = 0;
};

class Iterator
{
public:
	Node* node = nullptr;
	Iterator* operator++()
	{
		node = node->next;
		return this;
	}
	Iterator* operator--()
	{
		node = node->prev;
		return this;
	}
};

class Sequence
{
public:
	Node* head;
	Node* tail;
	int size;

	Sequence()
	{
		head = new Node;
		tail = new Node;

		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	Node* begin()
	{
		return head->next;
	}
	Node* end()
	{
		return tail;
	}
	void insert(Iterator& p, int e)
	{
		Node* newNode = new Node();
		newNode->value = e;

		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		this->size++;
	}
	void erase(Iterator& p)
	{
		if (size == 0)
			cout << "Empty\n";
		else
		{
			Node* deleteNode = p.node;
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;
			p.node = begin();
			size--;
			delete deleteNode;
		}
	}
	void reversePrint()
	{
		if (this->size == 0)
			cout << "Empty\n";
		else
		{
			Node* curNode = tail->prev;
			while (curNode != head)
			{
				cout << curNode->value << " ";
				curNode = curNode->prev;
			}
			cout << '\n';
		}
	}
	void find(int e)
	{
		if (size == 0)
			cout << "Empty\n";
		else
		{
			Node* curNode = head->next;
			int index = 0;
			while (curNode != tail)
			{
				if (curNode->value == e)
				{
					cout << index << '\n';
					return;
				}
				else
				{
					curNode = curNode->next;
					index++;
				}
			}
			cout << "-1\n";
		}
	}
	int getSize()
	{
		return this->size;
	}
};

int main()
{
	Sequence sq = Sequence();
	Iterator p;
	p.node = sq.begin();
	int test;
	cin >> test;
	while (test--)
	{
		string s;
		cin >> s;
		if (s == "begin")
		{
			p.node = sq.begin();
		}
		else if (s == "end")
		{
			p.node = sq.end();
		}
		else if (s == "insert")
		{
			int e;
			cin >> e;
			sq.insert(p, e);
		}
		else if (s == "erase")
		{
			if (sq.getSize() == 0)
				cout << "Empty\n";
			else
			{
				sq.erase(p);
			}
		}
		else if (s == "++")
		{
			++p;
		}
		else if (s == "--")
		{
			--p;
		}
		else if (s == "reversePrint")
		{
			sq.reversePrint();
		}
		else if (s == "find")
		{
			int e;
			cin >> e;
			sq.find(e);
		}
	}
}

