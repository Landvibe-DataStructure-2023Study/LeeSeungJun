#include <iostream>
using namespace std;

int vertex, s, d;
string cmd;
bool graph[2000][2000];
int test, n;
int main()
{
	cin >> test >> n;
	while (n--)
		cin >> vertex;
	while (test--)
	{
		cin >> cmd >> s;
		if (cmd == "insertEdge")
		{
			cin >> d;
			if (graph[s][d])
				cout << "Exist\n";
			else
			{
				graph[s][d] = true;
				graph[d][s] = true;
			}
		}
		else if (cmd == "eraseEdge")
		{
			cin >> d;
			if (!graph[s][d])
				cout << "None\n";
			else
			{
				graph[s][d] = false;
				graph[d][s] = false;
			}
		}
		else if (cmd == "isAdjacentTo")
		{
			cin >> d;
			if (graph[s][d])
				cout << "True\n";
			else
				cout << "False\n";
		}
		else if (cmd == "incidentEdges")
		{
			int count = 0;
			for (int i{ 0 }; i < 2000; i++)
			{
				if (graph[s][i]) count++;
			}
			cout << count << '\n';
		}
	}
}