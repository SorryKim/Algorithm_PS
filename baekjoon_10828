// baekjoon_10828
// https://www.acmicpc.net/problem/10828
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
};

class Stack {
public:
	Node* top;
	int size;

	Stack() {
		top = new Node();
		this->size = 0;
	}

	void push(int n) {
		Node* newNode = new Node();
		newNode->data = n;
		newNode->link = top;
		top = newNode;
		size++;
	}

	int sizeValue() {
		return this->size;
	}

	int pop() {
		if (size == 0)
			return -1;
		else {
			Node* tmp = top;
			int num = top->data;
			top = top->link;
			delete tmp;
			size--;
			return num;
		}
	}

	int empty() {
		if (size == 0)
			return 1;
		else
			return 0;
	}

	int topValue(){
		if (size == 0)
			return -1;
		else
			return top->data;
	}
};

int main() {

	int n;
	cin >> n;

	Stack* s = new Stack();
	string command = "";
	int num = 0;


	for (int i = 0; i <= n; i++) {

		getline(cin, command);

		if (command == "size") {
			cout << s->sizeValue() << endl;
			continue;
		}
		else if (command == "top") {
			cout << s->topValue() << endl;
			continue;
		}
		else if (command == "empty") {
			cout << s->empty() << endl;
			continue;
		}
		else if (command == "pop") {
			cout << s->pop() << endl;
			continue;
		}
		else if(command.size() > 5){
			string snum = command.substr(5, command.size() - 1);
			s->push(stoi(snum));
			continue;
		}
	}
}
