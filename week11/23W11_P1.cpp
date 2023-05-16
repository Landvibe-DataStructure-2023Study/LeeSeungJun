#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* parent;
	Node* left;
	Node* right;
	Node(int value)
	{
		this->value = value;
		parent = left = right = nullptr;
	}
};
class BST
{
public:
	Node* root = nullptr;
	Node* search(int x)
	{
		Node* curNode = root;
		while (curNode != nullptr)
		{
			if (curNode->value == x)
				return curNode;
			else if (curNode->value > x)
				curNode = curNode->left;
			else if (curNode->value < x)
				curNode = curNode->right;
		}
		return nullptr;
	}
	void insert(int x)
	{
		Node* newNode = new Node(x);
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		else
		{
			Node* curNode = root;
			Node* parNode = curNode->parent;
			while (curNode != nullptr)
			{
				if (curNode->value > x)
				{
					parNode = curNode;
					curNode = curNode->left;
				}
				else
				{
					parNode = curNode;
					curNode = curNode->right;
				}
			}
			newNode->parent = parNode;
			if (x > parNode->value)
				parNode->right = newNode;
			else
				parNode->left = newNode;
		}
	}
	void remove(int x)
	{
		Node* target = search(x);
		Node* parNode = target->parent;
		if (target->left == nullptr && target->right == nullptr)
		{
			if (target == root)
			{
				root = nullptr;
			}
			else
			{
				if (target == parNode->left)
					parNode->left = nullptr;
				if (target == parNode->right)
					parNode->right = nullptr;
			}
		}
		else if (target->left == nullptr || target->right == nullptr)
		{
			Node* childNode = (target->left == nullptr
				? target->right : target->left);
			if (target == root)
			{
				this->root = childNode;
			}
			else
			{
				if (target == parNode->left)
				{
					parNode->left = childNode;
					childNode->parent = parNode;
				}
				else
				{
					parNode->right = childNode;
					childNode->parent = parNode;
				}
			}
		}
		else if (target->left != nullptr && target->right == nullptr)
		{
			Node* succ = target->right;
			Node* succPar = succ->parent;
			while (succ != nullptr)
			{
				succPar = succ;
				succ = succ->left;
			}
			if (succ == succPar->left)
				succPar->left = succ->right;
			else
				succPar->right = succ->right;
			target->value = succ->value;
			target = succ;
		}
		delete target;
	}
	int inOrder(Node* v)
	{
		if (v == nullptr)
			return 0;
		int count;
		count = inOrder(v->left);
		count++;
		count += inOrder(v->right);
		return count;

	}
};

int main()
{
	BST bst = BST();
	int nodes, test;
	cin >> nodes >> test;
	while (nodes--)
	{
		int x;
		cin >> x;
		bst.insert(x);
	}
	while (test--)
	{
		int s, q;
		cin >> s >> q;
		Node* targetOne = bst.search(s);
		Node* targetTwo = bst.search(q);
		Node* subRootOne = targetOne->left;
		Node* subRootTwo = targetTwo->left;
			cout << bst.inOrder(subRootOne) + bst.inOrder(subRootTwo) << '\n';
	}
}