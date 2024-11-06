#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M, N;
	cin >> M >> N;
	string* arr = new string[M + 1];
	arr[0] = "0번";

	map<string, int> map;

	for (int i = 1; i <= M; i++) {
		string pocketmon;
		cin >> pocketmon;
		arr[i] = pocketmon;
		map.insert({ pocketmon, i });
	}

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		if (command[0] >= '0' && command[0] <= '9') {
			int num = stoi(command);
			cout << arr[num] << "\n";
		}
		else {
			auto a = map.find(command);
			cout << a->second << "\n";
		}
	}
	delete[] arr;
}