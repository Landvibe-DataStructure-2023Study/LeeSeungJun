#include <iostream>
using namespace std;

class Stack
{
private:
	int st[10001];
	int size;
	int maxSize;
public:
	Stack(int t)
	{
		this->size = 0;
		this->maxSize = t;
	}
	int returnSize()
	{
		return this->size;
	}
	bool empty()
	{
		return this->size == 0;
	}
	int full()
	{
		if (size >= maxSize)
			return 1;
		else
			return 0;
	}
	int top()
	{
		if (empty())
			return -1;
		else
			return st[size - 1];
	}
	void push(int x)
	{
		if (full() == 1)
			cout << "FULL" << '\n';
		else
		{
			st[size] = x;
			size++;
		}
	}
	void pop()
	{
		if (empty())
			cout << -1 << '\n';
		else
		{
			cout << st[size - 1] << '\n';
			size--;
		}
	}
};