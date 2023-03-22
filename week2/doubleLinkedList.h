#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int elem;
	Node* next;
	Node* prev;
public:
	Node()
	{
		this->elem = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node()
	{
		this->elem = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	friend class DoubleLinkedList;
};

class DoubleLinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	DoubleLinkedList()
	{
		this->head = new Node;
		this->tail = new Node;
		this->head->next = this->tail;
		this->tail->prev = this->head;
		this->size = 0;
	}
	~DoubleLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}

	bool empty() const
	{
		if (size == 0)
			return true;
		return false;
	}

	void print()
	{
		if (empty())
		{
			cout << "empty" << '\n';
			return;
		}
		Node* currPtr = this->head->next;
		while (currPtr != tail)
		{
			cout << currPtr->elem << " ";
			currPtr = currPtr->next;
		}
		cout << '\n';
	}

	void insert(int idx, int x)
	{
		if (idx > this->size)
		{
			cout << "error" << '\n';
			return;
		}

		Node* curNode = this->head;
		for (int i{ 0 }; i < idx; i++)
		{
			curNode = curNode->next;
		}
		Node* addNode = new Node;
		addNode->elem = x;
		addNode->next = curNode->next;
		curNode->next->prev = addNode;
		curNode->next = addNode;
		addNode->prev = curNode;
		size++;
	}

	void remove(int idx)
	{
		if (idx >= this->size || empty())
		{
			cout << "error" << '\n';
			return;
		}

		Node* removeNode = this->head->next;
		for (int i{ 0 }; i < idx; i++)
		{
			removeNode = removeNode->next;
		}
		int removeValue = removeNode->elem;
		removeNode->prev->next = removeNode->next;
		removeNode->next->prev = removeNode->prev;
		size--;
		cout << removeValue << '\n';
		delete removeNode;
	}

	void removeAll(int x)
	{
		int count{ 0 };
		Node* curNode = this->head->next;
		while (curNode != tail)
		{
			if (curNode->elem == x)
			{
				curNode->prev->next = curNode->next;
				curNode->next->prev = curNode->prev;
				count++;
				size--;
			}
			curNode = curNode->next;
		}

		if (count == 0)
			cout << "not found" << '\n';
		else
			cout << count << '\n';
	}

	void neighborMax(int idx)
	{
		if (idx >= this->size)
		{
			cout << "error" << '\n';
			return;
		}
		else if (idx == 0)
		{
			cout << head->next->next->elem << '\n';
			return;
		}
		else if (idx == size - 1)
		{
			cout << tail->prev->prev->elem << '\n';
			return;
		}
		else
		{
			Node* curNode = this->head->next;
			for (int i{ 0 }; i < idx; i++)
			{
				curNode = curNode->next;
			}
			int front, back;
			front = curNode->prev->elem;
			back = curNode->next->elem;

			if (front > back)
				cout << front << '\n';
			else
				cout << back << '\n';
		}
	}

	void neighborMin(int idx)
	{
		if (idx >= this->size)
		{
			cout << "error" << '\n';
			return;
		}
		else if (idx == 0)
		{
			cout << head->next->next->elem << '\n';
			return;
		}
		else if (idx == size - 1)
		{
			cout << tail->prev->prev->elem << '\n';
			return;
		}
		else
		{
			Node* curNode = this->head->next;
			for (int i{ 0 }; i < idx; i++)
			{
				curNode = curNode->next;
			}
			int front, back;
			front = curNode->prev->elem;
			back = curNode->next->elem;

			if (front < back)
				cout << front << '\n';
			else if (front > back)
				cout << back << '\n';
		}
	}
};

