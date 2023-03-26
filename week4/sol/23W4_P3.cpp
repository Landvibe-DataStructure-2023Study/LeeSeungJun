#include <iostream>
using namespace std;

int n;
class Queue
{
public:
	int arr[10001];
	int frontIdx = 0;
	int rearIdx = -1;
	int size = 0;

	bool empty()
	{
		return this->size == 0;
	}
	int front()
	{
		if (empty())
			return -1;
		else
			return arr[frontIdx];
	}
	int rear()
	{
		if (empty())
			return -1;
		else
			return arr[rearIdx];
	}
	void updateIndex()
	{
		frontIdx %= n;
		rearIdx %= n;
	}
	void enqueue(int x)
	{
		if (this->size >= n)
			cout << "full" << '\n';
		else
		{
			rearIdx++;
			updateIndex();
			arr[rearIdx] = x;
			size++;
		}
	}
	void dequeue()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			frontIdx++;
			updateIndex();
			size--;
		}

	}
	int getSize()
	{
		return this->size;
	}
};

int main()
{
	Queue q = Queue();
	int test;
	cin >> n >> test;
	while (test--)
	{
		string s;
		cin >> s;
		if (s == "enqueue")
		{
			int x;
			cin >> x;
			if (q.getSize() >= n)
				cout << "Full" << '\n';
			else
			{
				q.enqueue(x);
			}
		}
		else if (s == "dequeue")
		{
			if (q.empty())
				cout << "Empty" << '\n';
			else
			{
				cout << q.front() << '\n';
				q.dequeue();
			}
		}
		else if (s == "size")
		{
			cout << q.getSize() << '\n';
		}
		else if (s == "isEmpty")
		{
			if (q.empty())
				cout << "True" << '\n';
			else
				cout << "False" << '\n';
		}
		else if (s == "front")
		{
			if (q.empty())
				cout << "Empty" << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (s == "rear")
		{
			if (q.empty())
				cout << "Empty" << '\n';
			else
				cout << q.rear() << '\n';
		}
		else if (s == "full")
		{
			if (q.getSize() >= n)
				cout << "True" << '\n';
			else
				cout << "False" << '\n';
		}
	}
}