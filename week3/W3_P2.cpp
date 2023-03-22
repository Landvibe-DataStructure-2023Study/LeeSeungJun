#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int value;
	Node* next;
public:
	Node()
	{
		value = 0;
		next = nullptr;
	}

	friend class LinkedList;
	friend class Stack;
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
		this->head = new Node();
		this->tail = new Node();
		this->head->next = tail;
		size = 0;
	}
	void addFront(int x)
	{
		Node* addNode = new Node;
		addNode->value = x;
		addNode->next = this->head->next;
		this->head->next = addNode;
		size++;
	}
	void removeFront()
	{
		Node* removeNode = this->head->next;
		this->head->next = removeNode->next;
		size--;
	}
	bool empty()
	{
		return this->size == 0;
	}
	friend class Stack;
};
class Stack
{
private:
	LinkedList ll;
	int size;
public:
	Stack()
	{
		ll = LinkedList();
		this->size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	int returnSize()
	{
		return this->size;
	}
	int top()
	{
		if (empty())
			return -1;
		else
			return ll.head->next->value;
	}
	void push(int x)
	{
		ll.addFront(x);
		size++;
	}
	void pop()
	{
		if (empty())
			return;
		else
		{
			ll.removeFront();
			size--;
		}
	}
};

int main()
{
	int t;
	Stack st;
	while (t--)
	{
		string s;
		cin >> s;
		for (int i{ 0 }; i < s.size(); i++)
		{
			char c = s[i];
		}
	}
}