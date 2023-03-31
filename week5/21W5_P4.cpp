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
	Node* node;
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
		size++;
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
	void print()
	{
		if (size == 0)
			cout << "Empty\n";
		else
		{
			Node* curNode = head->next;
			while (curNode != tail)
			{
				cout << curNode->value << " ";
				curNode = curNode->next;
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
	int test;
	cin >> test;
	while (test--)
	{
		Sequence sq = Sequence();
		Iterator p = Iterator();
		int n;
		cin >> n;
		p.node = sq.begin();
		while (n--)
		{
			int num;
			cin >> num;
			sq.insert(p, num);
		}
		p.node = sq.begin();
		while (p.node != sq.tail)
		{
			int pVal = p.node->prev->value;
			int val = p.node->value;
			int nVal = p.node->next->value;
			int printVal = pVal + (3 * val) + nVal;
			cout << printVal << " ";
			++p;
		}
		cout << '\n';
	}
}