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
			Node* newNode = new Node(parentNode, y, parentNode->depth+1);
			parentNode->childList.push_back(newNode);
			nodeList.push_back(newNode);
		}
	}
	void deleteNode(int x)
	{
		Node* deleteNode = findNode(x);

		if (deleteNode == root || deleteNode == nullptr)
		{
			cout << "-1\n";
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
		if (targetNode->childList.size() == 0 || targetNode == nullptr)
			cout << "-1\n";
		else
		{
			for (int i{ 0 }; i < targetNode->childList.size(); i++)
			{
				cout << targetNode->childList[i]->value << ' ';
			}
			cout << '\n';
		}
	}
};

int main()
{
	Tree t = Tree();
	int nodes, test;
	cin >> nodes >> test;
	while (nodes--)
	{
		int par, chi;
		cin >> par >> chi;
		Node* parentNode = t.findNode(par);
		Node* childNode = new Node(parentNode, chi, parentNode->depth+1);
		parentNode->childList.push_back(childNode);
		t.nodeList.push_back(childNode);
	}
	while (test--)
	{
		int target, depth{ 0 };
		cin >> target;
		Node* targetNode = t.findNode(target);
		if (targetNode == nullptr)
		{
			cout << "-1\n";
		}
		else
		{
			cout << targetNode->depth << '\n';
		}
	}
}