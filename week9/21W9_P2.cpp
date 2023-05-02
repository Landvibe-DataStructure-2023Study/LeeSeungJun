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
		v.push_back(e);
	}
	int pop()
	{
		vector<int>::iterator p = v.begin();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		{
			if (*p < *i)
				p = i;
		}
		int maxValue = *p;
		v.erase(p);
		return maxValue;
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
		for (int i{ 0 }; i < num; i++)
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

