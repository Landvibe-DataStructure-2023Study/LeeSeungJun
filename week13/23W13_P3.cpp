#include <iostream>
using namespace std;

int s, d, v{ 0 };
string cmd;
bool graph[10000][10000]{ 0 };
bool vertexList[10000]{ 0 };
int test, n;
int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		cin >> cmd;
		if (cmd == "insertVertex")
		{
			cin >> s;
			if (vertexList[s])
				cout << "Exist\n";
			else
			{
				vertexList[s] = true;
				v++;
			}
		}
		else if (cmd == "insertEdge")
		{
			cin >> s >> d;
			if (graph[s][d])
				cout << "Exist\n";
			else
			{
				graph[s][d] = true;
				graph[d][s] = true;
			}
		}
		else if (cmd == "eraseVertex")
		{
			cin >> s;
			vertexList[s] = false;
			v--;
			for (int i{ 0 }; i < 10000; i++)
			{
				graph[s][i] = false;
				graph[i][s] = false;
			}
		}
		else if (cmd == "isAdjacentEven")
		{
			cin >> s;
			int count{ 0 };
			for (int i{ 0 }; i < 10000; i++)
			{
				if (graph[s][i])
					count++;
			}
			if (count % 2 == 1)
				cout << "False ";
			else
				cout << "True ";
			cout << count << '\n';
		}
		else if (cmd == "maxEdgeVertex")
		{
			if (v == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				int count, max{ 0 }, idx;
				for (int i{ 0 }; i < 10000; i++)
				{
					count = 0;
					if (vertexList[i])
					{
						for (int j{ 0 }; j < 10000; j++)
						{
							if (graph[i][j])
								count++;
						}
						if (count > max)
						{
							max = count;
							idx = i;
						}
					}
				}
				if (max == 0)
					cout << -1 << '\n';
				else
					cout << idx << '\n';
			}
		}
	}
}