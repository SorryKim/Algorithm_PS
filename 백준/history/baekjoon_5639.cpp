// baekjoon_5639
// https://www.acmicpc.net/problem/5639

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	
};

Node* insertNode(Node* node, int n) {
	if (node == nullptr) {
		node = new Node();
		node->data = n;
		node->left = nullptr;
		node->right = nullptr;
	}
	else if (node->data < n) {
		node->right = insertNode(node->right, n);
	}
	else if (node->data > n) {
		node->left = insertNode(node->left, n);
	}
	
	return node;
}

void postorder(Node* node) {
	if (node->left != nullptr) {
		postorder(node->left);
	}
	if (node->right != nullptr) {
		postorder(node->right);
	}
	cout << node->data << endl;
	
}


int main() {
	int num;
	Node* root = nullptr;
	while (cin >> num) {
		if (num == EOF)
			break;
		else {
			root = insertNode(root, num);
		}
	}
	postorder(root);
}
