#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int users, test, block;
    cin >> users >> test >> block;

    vector<bool> blockList(users + 1, 0);
    vector<vector<bool>> graph(users + 1, vector<bool>(users + 1, false));

    while (block--)
    {
        int a;
        cin >> a;
        blockList[a] = true;
    }

    for (int i = 1; i <= users; i++)
    {
        for (int j = 1; j <= users; j++)
        {
            bool n;
            cin >> n;
            graph[i][j] = n;
        }
    }

    while (test--)
    {
        set<int> reccomendList;
        int target, range;
        cin >> target >> range;

        for (int i = 1; i <= users; i++)
        {
            if (graph[target][i])
                reccomendList.insert(i);
        }

        while (--range)
        {
            set<int> temp;
            for (int k : reccomendList)
            {
                for (int i = 1; i <= users; i++)
                {
                    if (graph[k][i])
                        temp.insert(i);
                }
            }
            reccomendList.insert(temp.begin(), temp.end());
        }

        set<int> temp;
        for (int l : reccomendList)
        {
            if (!blockList[l])
                temp.insert(l);
        }
        reccomendList.insert(temp.begin(), temp.end());

        int count{ 0 };
        for (int n : reccomendList)
        {
            if (!blockList[n] && n != target)
            {
                cout << n << " ";
                count++;
            }
        }
        if (count == 0) cout << 0;
        cout << '\n';
    }
}
