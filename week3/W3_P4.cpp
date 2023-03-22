#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	char value;
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
	void addFront(char x)
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
	char top()
	{
		if (empty())
			return -1;
		else
			return ll.head->next->value;
	}
	void push(char x)
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

bool isOper(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		return true;
	}
	else
		return false;
}
bool isChar(char c)
{
	if (c >= '1' && c <= '9')
		return true;
	else
		return false;
}
int main()
{
	int t;
	Stack st;
	cin >> t;
	while (t--)
	{
		string s;
		int count{ 0 };
		cin >> s;
		for (int i{ 0 }; i < s.size(); i++)
		{
			char c = s[i];
			if (isChar(c))
				cout << c;
			else if (isOper(c))
			{
				if (c == '+' || c == '-')
				{
					while (true) {
						if (s.empty())
							break;
						else if (st.top() == '+' || st.top() == '-' || 
							st.top() == '*' || st.top() == '/')
						{
							cout << st.top();
							st.pop();
							if (st.empty())
								count++;
						}

						else
							break;
					}
					st.push(c);
				}
				else if (c == '*' || c == '/')
				{
					while (true) {
						if (s.empty())
							break;
						if (st.top() == '*' || st.top() == '/')
						{
							cout << st.top();
							st.pop();
							if (st.empty())
								count++;
						}
						else
							break;
					}
					st.push(c);
				}
			}
			
		}
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}
		count++;
		cout << " " << count << '\n';
	}
	
}