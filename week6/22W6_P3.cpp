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
		if (parentNode == nullptr)
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

		if (deleteNode == root || deleteNode == nullptr)
		{
			//cout << "-1\n";
			return;
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
	void printChild(int x)
	{
		Node* targetNode = findNode(x);
		if (targetNode == nullptr)
		{
			cout << "0\n";
			return;
		}
		else if (targetNode->parent == nullptr)
		{
			cout << x << '\n';
			return;
		}
			
		else
		{
			Node* parentNode = targetNode->parent;
			for (int i{ 0 }; i < parentNode->childList.size(); i++)
			{
				cout << parentNode->childList[i]->value << ' ';
			}
			cout << '\n';
			return;
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
		else if (s == "print")
		{
			int x;
			cin >> x;
			t.printChild(x);
		}
		else if (s == "delete")
		{
			int x;
			cin >> x;
			t.deleteNode(x);
		}
	}
}