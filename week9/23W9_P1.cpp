#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node* parent;
	vector<Node*> childList;
	int value;
	int depth;

	Node(Node* parent, int value, int depth)
	{
		this->parent = parent;
		this->value = value;
		this->depth = depth;
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> nodeList;

	Tree()
	{
		root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* findNode(int v)
	{
		for (int i{ 0 }; i < nodeList.size(); i++)
		{
			if (nodeList[i]->value == v)
				return nodeList[i];
		}
		return nullptr;
	}
	void insertNode(int x, int y)
	{
		Node* parentNode = findNode(x);
		if (parentNode == nullptr || findNode(y) != nullptr)
			cout << "-1\n";
		else
		{
			Node* newNode = new Node(parentNode, y, parentNode->depth + 1);
			parentNode->childList.push_back(newNode);
			nodeList.push_back(newNode);
		}
	}
	void deleteNode(int x)
	{
		Node* deleteNode = findNode(x);

		if (deleteNode == nullptr)
		{
			cout << "-1\n";
		}
		else
		{
			for (int i{ 0 }; i < deleteNode->childList.size(); i++)
			{
				deleteNode->parent->childList.push_back(deleteNode->childList[i]);
				deleteNode->childList[i]->parent = deleteNode->parent;
			}

			for (int i{ 0 }; i < deleteNode->parent->childList.size(); i++)
			{
				if (deleteNode == deleteNode->parent->childList[i])
				{
					deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
					break;
				}
			}

			for (int i{ 0 }; i < nodeList.size(); i++)
			{
				if (nodeList[i] == deleteNode)
				{
					nodeList.erase(nodeList.begin() + i);
					break;
				}
			}

			delete deleteNode;
		}
	}
	void parent(int x)
	{
		Node* childNode = findNode(x);
		if (childNode == nullptr)
		{
			cout << "-1\n";
		}
		else
		{
			cout << childNode->parent->value << '\n';
		}
	}
	void child(int x)
	{
		Node* parentNode = findNode(x);
		if (parentNode == nullptr || parentNode->childList.size() == 0)
			cout << "-1\n";
		else
		{
			for (int i{ 0 }; i < parentNode->childList.size(); i++)
				cout << parentNode->childList[i]->value << " ";
			cout << '\n';
		}
	}
	void minMaxChild(int x)
	{
		Node* targetNode = findNode(x);
		if (targetNode == nullptr || targetNode->childList.size() < 2)
		{
			cout << "-1\n";
		}
		else
		{
			int min = 99999999;
			int max = -9999999;
			for (int i{ 0 }; i < targetNode->childList.size(); i++)
			{
				if (targetNode->childList[i]->value < min)
					min = targetNode->childList[i]->value;
				if (targetNode->childList[i]->value > max)
					max = targetNode->childList[i]->value;
			}
			cout << min + max << '\n';
		}
	}
};

int main()
{
	Tree t = Tree();
	int test;
	cin >> test;
	while (test--)
	{
		string s;
		cin >> s;
		if (s == "insert")
		{
			int x, y;
			cin >> x >> y;
			t.insertNode(x, y);
		}
		else if (s == "parent")
		{
			int x;
			cin >> x;
			t.parent(x);
		}
		else if (s == "delete")
		{
			int x;
			cin >> x;
			t.deleteNode(x);
		}
		else if (s == "child")
		{
			int x;
			cin >> x;
			t.child(x);
		}
		else if (s == "min_maxChild")
		{
			int x;
			cin >> x;
			t.minMaxChild(x);
		}
	}
}