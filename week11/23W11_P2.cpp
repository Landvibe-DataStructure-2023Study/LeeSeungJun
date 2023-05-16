#include <iostream>
using namespace std;

int c, k;

class Node {
private:
    int data;
    Node* par;
    Node* left;
    Node* right;

public:
    Node(int d) {
        data = d;
        par = left = right = nullptr;
    }
    friend class BST;
};

class BST {
public:
    Node* root = nullptr;


    Node* search(int data) {
        Node* curNode = root;
        while (curNode != nullptr) {
            if (data == curNode->data) {
                return curNode;
            }
            else if (data < curNode->data) {
                curNode = curNode->left;
            }
            else if (data > curNode->data) {
                curNode = curNode->right;
            }
        }
        return nullptr;
    }


    void depth(Node* node) {
        Node* curNode = node;
        int depth = 0;

        while (curNode != root) {
            curNode = curNode->par;
            depth++;
        }
        cout << depth << "\n";
    }


    void insert(int data) {

        Node* newNode = new Node(data);


        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curNode = root;
        Node* parNode = root->par;

        while (curNode != nullptr) {
            if (data < curNode->data) {
                parNode = curNode;
                curNode = curNode->left;
            }
            else {
                parNode = curNode;
                curNode = curNode->right;
            }
        }


        newNode->par = parNode;
        if (data < parNode->data) {
            parNode->left = newNode;
        }
        else {
            parNode->right = newNode;
        }
    }



    void remove(int data) {

        Node* node = search(data);
        Node* parNode = node->par;


        if (node->left == nullptr && node->right == nullptr) {
            if (node == root) {
                this->root = nullptr;
            }
            else {
                if (node == parNode->left) {
                    parNode->left = nullptr;
                }
                else {
                    parNode->right = nullptr;
                }
            }

        }
        else if (node->left == nullptr || node->right == nullptr) {
            Node* child = (node->left != nullptr) ? node->left : node->right;

            if (node == root) {
                this->root = child;
            }
            else {
                if (node == parNode->left) {
                    parNode->left = child;
                    child->par = parNode;
                }
                else {
                    parNode->right = child;
                    child->par = parNode;
                }
            }

        }
        else if (node->left != nullptr && node->right != nullptr) {
            Node* succ = node->right;
            Node* succPar = node;

            while (succ->left != nullptr) {
                succPar = succ;
                succ = succ->left;
            }

            if (succ == succPar->left) {
                succPar->left = succ->right;
            }
            else {
                succPar->right = succ->right;
            }

            node->data = succ->data;
            node = succ;
        }
        delete node;
    }


    void min(Node* node) {
        if (node == nullptr) return;

        min(node->left);
        c++;
        if (c == k) {
            cout << node->data << "\n";
            return;
        }
        min(node->right);
    }


    int height(Node* node) {
        if (node == nullptr)
            return -1;

        if (height(node->left) < height(node->right))
            return height(node->right) + 1;
        else
            return height(node->left) + 1;
    }

};

int main() {
    ios::sync_with_stdio;
    cin.tie(NULL);
    int numOfCmd;
    cin >> numOfCmd;

    BST* bst = new BST();

    while (numOfCmd--) {
        string cmd;
        int x;

        cin >> cmd >> x;

        if (cmd == "insert") {
            bst->insert(x);
            bst->depth(bst->search(x));
        }
        else if (cmd == "delete") {
            bst->depth(bst->search(x));
            bst->remove(x);
        }
        else if (cmd == "min") {
            k = x;
            c = 0;
            bst->min(bst->root);
        }
        else if (cmd == "height") {
            cout << bst->height(bst->search(x)) << "\n";
        }
    }
}