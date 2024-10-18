#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];

int Find(int n) {
    if (parent[n] == n)
        return n;
    else
        return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P;
    int answer = 0;
    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;
    

    for (int i = 0; i < P; i++) {
        int num;
        cin >> num;

        int gate = Find(num);

        if (gate == 0)
            break;

        answer++;
        Union(gate, gate - 1);
    }

    cout << answer << '\n';
    return 0;
}
