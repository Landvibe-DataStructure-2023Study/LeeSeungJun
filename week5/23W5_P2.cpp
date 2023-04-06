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
	Iterator()
	{
		node = nullptr;
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

	void next(Iterator& p)
	{
		if (p.node == tail)
			return;
		else
			p.node = p.node->next;
	}
	void prev(Iterator& p)
	{
		if (p.node == head->next)
			return;
		else
			p.node = p.node->prev;
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
};


int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int len;
		cin >> len;
		Sequence sq = Sequence();
		Iterator p = Iterator();
		p.node = sq.head->next;
		while (len--)
		{
			int e;
			cin >> e;
			sq.insert(p, e);
		}
		p.node = sq.begin();
		int moves;
		cin >> moves;
		while (moves--)
		{
			int jump;
			cin >> jump;
			if (jump > 0)
			{
				for (int i{ 0 }; i < jump; i++)
				{
					sq.next(p);
					if (p.node == sq.tail)
						break;
				}
			}
			else
			{
				jump *= -1;
				for (int i{ 0 }; i < jump; i++)
				{
					sq.prev(p);
					if (p.node == sq.head->next)
						break;
				}
			}
			jump = p.node->value;
			if (jump > 0)
			{
				for (int i{ 0 }; i < jump; i++)
				{
					sq.next(p);
					if (p.node == sq.tail)
						break;
				}
			}
			else
			{
				jump *= -1;
				for (int i{ 0 }; i < jump; i++)
				{
					sq.prev(p);
					if (p.node == sq.head->next)
						break;
				}
			}
		}
		cout << p.node->value << "\n";
	}
}