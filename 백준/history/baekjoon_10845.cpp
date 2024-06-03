// baekjoon_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
	Node() {
		data = 0;
		link = nullptr;
	}
	Node(int n) {
		data = n;
		link = nullptr;
	}
};

class Queue {
public:
	Node* front;
	Node* back;
	int size;
	Queue() {
		front = new Node();
		back = new Node();
		this->size = 0;
	}

	void push(int n) {
		Node* newNode = new Node(n);
		if (this->size == 0) {
			front = newNode;
			back = newNode;
		}
		else {
			back->link = newNode;
			back = newNode;
		}
		this->size++;
	}

	int pop() {
		if (this->size == 0)
			return -1;
		else {
			this->size--;
			int num = front->data;
			front = front->link;
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

	Queue* q = new Queue();
	string command = "";
	int num = 0;

	for (int i = 0; i <= n; i++) {

		getline(cin, command);

		if (command == "size") {
			cout << q->getSize() << endl;
			continue;
		}
		else if (command == "front") {
			cout << q->getFront() << endl;
			continue;
		}
		else if (command == "back") {
			cout << q->getBack() << endl;
		}
		else if (command == "empty") {
			cout << q->empty() << endl;
			continue;
		}
		else if (command == "pop") {
			cout << q->pop() << endl;
			continue;
		}
		else if (command.size() > 5) {
			string snum = command.substr(5, command.size() - 1);
			q->push(stoi(snum));
			continue;
		}
	}

}
