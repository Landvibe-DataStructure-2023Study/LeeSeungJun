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
	void erase(Iterator& p)
	{
		if (size == 0)
			cout << "Empty\n";
		else if (p.node == tail)
			return;
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
	void find(int e)
	{
		Node* curNode = head->next;
		int index = 0;
		int found{ 0 };
		while (curNode != tail)
		{
			if (curNode->value == e)
			{
				cout << index << ' ';
				found = 1;
			}
			curNode = curNode->next;
			index++;
		}
		if (found == 0)
			cout << "-1";
		cout << '\n';
	}
	void upper(int e)
	{
		Node* curNode = head->next;
		int isUpper{ 0 };
		int idx{ 0 };
		while (curNode != tail)
		{
			if (curNode->value > e)
			{
				cout << idx << ' ';
				isUpper = 1;
			}
			curNode = curNode->next;
			idx++;
		}
		if (isUpper == 0)
			cout << -1;
		cout << '\n';
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
		while (p.node != sq.tail)
		{
			int pVal = p.node->prev->value;
			int val = p.node->value;
			int nVal = p.node->next->value;
			int sub{0};
			if (p.node == sq.head->next)
			{
				if (val > nVal)
					sub = val - nVal;
				else
					sub = nVal - val;
			}
			else if (p.node == sq.tail->prev)
			{
				if (val > pVal)
					sub = val - pVal;
				else
					sub = pVal - val;
			}
			else
			{
				if (val > pVal && pVal > nVal)
					sub = val - nVal;
				else if (val > nVal && nVal > pVal)
					sub = val - pVal;
				else if (nVal > val && val > pVal)
					sub = nVal - pVal;
				else if (nVal > pVal && pVal > val)
					sub = nVal - val;
				else if (pVal > val && val > nVal)
					sub = pVal - nVal;
				else if (pVal > nVal && pVal > val)
					sub = pVal - val;
			}
			cout << sub << " ";
			sq.next(p);
		}
		cout << '\n';
	}
}