// 완전 이진 트리 / baekjoon_9934.cpp
// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <cmath>
using namespace std;

int arr[1025];
int tree[1025];
int k;
int cnt = 0;

// 입력받은 배열을 inorder하면서 트리에 저장
void inorder(int index, int depth)
{
    if (depth == k)
    {   
        cnt++;
        tree[index] = arr[cnt];   
    }
    else
    {                                  
        // left child
        inorder(index * 2, depth + 1);

        // parent
        cnt++;
        tree[index] = arr[cnt];

        // right child
        inorder(index * 2 + 1, depth + 1);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> k;
	for (int i = 1; i <= (int)pow(2, k) - 1; i++) {
		cin >> arr[i];
	}

    inorder(1, 1);

    for (int i = 1; i <= k; i++) {
        for (int j = (int)pow(2,i - 1); j <= (int)pow(2, i) - 1; j++) {
            cout << tree[j] << " ";
        }
        cout << "\n";
    }
}
