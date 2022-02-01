// baekjoon_10866
// https://www.acmicpc.net/problem/10866

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
	int data;
	Node* rlink;
	Node* llink;
	Node() {
		data = 0;
		llink = nullptr;
		rlink = nullptr;
	}
	Node(int n) {
		data = n;
		rlink = nullptr;
		llink = nullptr;
	}
};

class Deque {
public:
	Node* front;
	Node* back;
	int size;
	Deque() {
		front = new Node();
		back = new Node();
		this->size = 0;
	}

	void push_front(int n) {
		Node* newNode = new Node(n);
		if (this->size == 0) {
			front = newNode;
			back = newNode;
		}
		else {
			newNode->rlink = front;
			front->llink = newNode;
			front = newNode;
		}
		this->size++;
	}

	void push_back(int n) {
		Node* newNode = new Node(n);
		if (this->size == 0) {
			front = newNode;
			back = newNode;
		}
		else {
			newNode->llink = back;
			back->rlink = newNode;
			back = newNode;
		}
		this->size++;
	}

	int pop_front() {
		if (this->size == 0)
			return -1;
		else if (front->rlink == nullptr) {
			this->size--;
			int num = front->data;
			front = nullptr;
			back = nullptr;
			return num;
		}
		else {
			this->size--;
			Node* tmp = front;
			int num = tmp->data;
			front = tmp->rlink;
			delete tmp;
			return num;
		}
	}

	int pop_back() {
		if (this->size == 0)
			return -1;
		else if (back->llink == nullptr) {
			this->size--;
			int num = back->data;
			front = nullptr;
			back = nullptr;
			return num;
		}
		else {
			this->size--;
			Node* tmp = back;
			int num = tmp->data;
			back = tmp->llink;
			delete tmp;
			return num;
		}
	}

	int getSize() {
		return this->size;
	}

	int empty() {
		if (this->size == 0)
			return 1;
		else
			return 0;
	}

	int getFront() {
		if (this->size == 0)
			return -1;
		else
			return front->data;
	}

	int getBack() {
		if (this->size == 0)
			return -1;
		else
			return back->data;
	}
	
};


int main() {
	int n;
	cin >> n;

	Deque* d = new Deque();
	string command = "";
	int num = 0;

	for (int i = 0; i <= n; i++) {
		getline(cin, command);

		if (command == "size")
			cout << d->getSize() << endl;
		if (command == "empty")
			cout << d->empty() << endl;
		if (command == "front")
			cout << d->getFront() << endl;
		if (command == "back")
			cout << d->getBack() << endl;
		if (command == "pop_front") 
			cout << d->pop_front() << endl;
		if (command == "pop_back")
			cout << d->pop_back() << endl;

		else if (command.substr(0, 10) == "push_front") {
			string snum = command.substr(11, command.size() - 1);
			int inum = stoi(snum);
			d->push_front(inum);
		}
		else if (command.substr(0, 9) == "push_back") {
			string snum = command.substr(10, command.size() - 1);
			int inum = stoi(snum);
			d->push_back(inum);
		}
		
	}

}
