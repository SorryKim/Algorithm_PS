#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int n;
    vector<int> heap;

    cin >> n;

    heap.push_back(0);
    heap.push_back(1);


    for (int i = 2; i <= n; i++) {

        heap.push_back(i);

        int temp = heap[i];
        heap[i] = heap[i - 1];
        heap[i - 1] = temp;

        for (int j = i - 1; j > 1; j /= 2) {
            int temp = heap[j];
            heap[j] = heap[j/2];
            heap[j/2] = temp;
        }

    }


    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";

    return 0;
}
