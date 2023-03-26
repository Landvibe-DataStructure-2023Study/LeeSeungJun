#include <iostream>
using namespace std;

class Node
{
private:
	Node* next;
	Node* prev;
	int value;
public:
	Node()
	{
		this->next = nullptr;
		this->prev = nullptr;
		this->value = 0;
	}
	friend class Queue;
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
		size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	void removeFront()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			Node* removeNode = this->head->next;
			this->head->next = removeNode->next;
			removeNode->next->prev = this->head;
			delete removeNode;
			this->size--;
		}
	}
	void addBack(int x)
	{
		Node* addNode = new Node;
		addNode->value = x;
		addNode->prev = this->tail->prev;
		this->tail->prev->next = addNode;
		addNode->next = this->tail;
		this->tail->prev = addNode;
		this->size++;
	}
	friend class Queue;
};
class Queue
{
private:
	int size;
	DoubleLinkedList dll;
public:
	Queue()
	{
		this->dll = DoubleLinkedList();
		this->size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	int getSize()
	{
		return this->size;
	}
	int front()
	{
		return dll.head->next->value;
	}
	int rear()
	{
		return dll.tail->prev->value;
	}
	void enqueue(int x)
	{
		dll.addBack(x);
		this->size++;
	}
	void dequeue()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			dll.removeFront();
			this->size--;
		}
	}
};

int main()
{
	int test;
	cin >> test;
	Queue playerOne = Queue();
	Queue playerTwo = Queue();


	while (test--)
	{
		int scoreOne{ 0 }, scoreTwo{ 0 };
		int winOne{ 0 }, winTwo{ 0 };
		int sub{ 0 };
		int rounds;
		cin >> rounds;
		for (int i{ 0 }; i < rounds; i++)
		{
			int x;
			cin >> x;
			playerOne.enqueue(x);
		}
		for (int i{ 0 }; i < rounds; i++)
		{
			int x;
			cin >> x;
			playerTwo.enqueue(x);
		}

		for (int i{ 0 }; i < rounds; i++)
		{
			cout << "Round" << i + 1 << " ";
			int healthOne =
				(winOne == 1 ? playerOne.front() + sub : playerOne.front());
			playerOne.dequeue();
			int healthTwo =
				(winTwo == 1 ? playerTwo.front() + sub : playerTwo.front());
			playerTwo.dequeue();

			winOne = 0; winTwo = 0; sub = 0;
			if (healthOne > healthTwo)
			{
				winOne = 1;
				scoreOne++;
				sub = healthOne - healthTwo;
			}
			else if (healthOne < healthTwo)
			{
				winTwo = 1;
				scoreTwo++;
				sub = healthTwo - healthOne;
			}
			if (healthOne > healthTwo)
				cout << healthOne << '>' << healthTwo << ' ';
			else if (healthOne < healthTwo)
				cout << healthOne << '<' << healthTwo << ' ';
			else if (healthOne == healthTwo)
				cout << healthOne << '=' << healthTwo << ' ';
			cout << scoreOne << ':' << scoreTwo << '\n';
		}

		if (scoreOne > scoreTwo)
			cout << "Winner P1" << '\n';
		else if (scoreOne < scoreTwo)
			cout << "Winner P2" << '\n';
		else if (scoreOne == scoreTwo)
			cout << "Draw" << '\n';
	}
}