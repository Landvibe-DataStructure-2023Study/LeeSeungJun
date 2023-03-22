#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int elem;
	Node* next;
public:
	Node()
	{
		this->elem = NULL;
		this->next = nullptr;
	}
	friend class LinkedList;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList()
	{
		this->head = new Node;
		this->tail = new Node;
		this->head->next = this->tail;
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
		while (currPtr != this->tail)
		{
			cout << currPtr->elem << " ";
			currPtr = currPtr->next;
		}
		cout << '\n';
	}

	void addFront(int x)
	{
		Node* addNode = new Node;
		addNode->elem = x;

		addNode->next = head->next;
		head->next = addNode;
		size++;
	}

	void removeFront()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			Node* delNode = new Node;
			delNode = head->next;
			int delElem = delNode->elem;
			head->next = delNode->next;
			delete delNode;
			size--;
			cout << delElem << '\n';
		}
	}

	void update(int idx, int x)
	{
		if (idx >= this->size)
			cout << "error" << '\n';
		else
		{
			Node* curNode = this->head->next;
			for (int i{ 0 }; i < idx; i++)
			{
				curNode = curNode->next;
			}
			curNode->elem = x;
		}
	}

	void min()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			Node* curNode = this->head->next;
			int minValue = curNode->elem;
			int minIndex = 0;
			for (int i{ 0 }; i < this->size; i++)
			{
				if (curNode->elem < minValue)
				{
					minValue = curNode->elem;
					minIndex = i;
				}
				curNode = curNode->next;
			}
			cout << minIndex << " " << minValue << '\n';
		}
	}

	void addBack(int x)
	{
		Node* addNode = new Node;
		Node* curNode = this->head->next;
		addNode->elem = x;

		while(curNode->next != this->tail)
		{
			curNode = curNode->next;
		}
		curNode->next = addNode;
		addNode->next = this->tail;
		size++;
	}

	void removeBack()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			Node* curNode = this->head->next;
			while (curNode->next->next != this->tail)
			{
				curNode = curNode->next;
			}
			Node* delNode = curNode->next;
			int delElem = delNode->elem;
			delete delNode;
			curNode->next = this->tail;
			this->size--;
			cout << delElem << '\n';
		}

	}

	void max()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			Node* curNode = this->head->next;
			int maxValue = curNode->elem;
			int maxIndex = 0;
			for (int i{ 0 }; i < this->size; i++)
			{
				if (curNode->elem > maxValue)
				{
					maxValue = curNode->elem;
					maxIndex = i;
				}
				curNode = curNode->next;
			}
			cout << maxIndex << " " << maxValue << '\n';
		}
	}

	
};