#include <iostream>
#include <vector>
using namespace std;

class Pqueue
{
public:
	vector<int>v;

	bool empty() { return v.size() == 0; }
	void push(int e)
	{
		if (empty())
			v.push_back(e);
		else
		{
			vector<int>::iterator iter;
			for (iter = v.begin(); iter != v.end(); iter++)
			{
				if (e < *iter)
				{
					v.insert(iter, e);
					return;
				}
			}
			v.insert(v.end(), e);
		}
	}
	int pop()
	{
		if (!empty())
		{
			int data = v.front();
			v.erase(v.begin());
			return data;
		}
		else
			return 0;
	}
};

int main()
{
	int test, num, n;
	cin >> test;
	while (test--)
	{
		cin >> num;
		vector <int> v;
		Pqueue p;
		for (int i{0}; i<num; i++)
		{
			cin >> n;
			v.push_back(n);
		}
		for (int i{ 0 }; i < num; i++)
		{
			p.push(v.front());
			v.erase(v.begin());
		}
		for (int i{ 0 }; i < num; i++)
		{
			v.push_back(p.pop());
		}
		for (int i{ 0 }; i < num; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
}

