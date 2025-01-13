#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    int answer = 0;
    set<string> my_set;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        my_set.insert(s);
    }

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        if(my_set.find(s) != my_set.end()) answer++;
    }

    cout << answer << '\n';
    return 0;
}