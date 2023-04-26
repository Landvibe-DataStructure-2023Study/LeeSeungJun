#include <iostream>
#include <vector>
using namespace std;

int c;
int found = 0;
class Node
{
public:
	Node* parent;
	vector<Node*>childList;
	int value;
	int depth;
	int file;
	int capa;
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
	vector<Node*>nodeList;
	Tree()
	{
		root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* find(int x)
	{
		for (auto n : nodeList)
		{
			if (n->value == x)
				return n;
		}
		return nullptr;
	}
	void insert(int par, int chi)
	{
		Node* parentNode = find(par);
		if (parentNode == nullptr || find(chi) != nullptr)
			return;
		Node* newNode = new Node(parentNode, chi, parentNode->depth + 1);
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	int count(Node* node)
	{
		int sum{ 0 };
		for (auto n : node->childList)
		{
			sum += count(n);
		}
		sum += node->file;
		return sum;
	}
	void postOrder(Node* node)
	{
		for (auto n : node->childList)
		{
			postOrder(n);
		}
		if (node->capa >= c) {
			cout << node->value << ' ';
			found = 1;
		}
		
	}
};

int main()
{
	Tree t = Tree();
	int nodes;
	cin >> nodes >> c;
	for (int i{ 1 }; i < nodes; i++)
	{
		int par, chi;
		cin >> par >> chi;
		t.insert(par, chi);
	}
	for (int i{ 0 }; i < nodes; i++)
	{
		int v, file;
		cin >> v >> file;
		Node* target = t.find(v);
		target->file = file;
	}
	for (auto n : t.nodeList)
	{
		n->capa = t.count(n);
	}
	
	t.postOrder(t.root);
	if (found == 0)
		cout << "-1\n";
}