#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string result;

void dfs(int depth, vector<bool> visited, vector<char> &v){

    if(depth >= v.size()){
        cout << result << "\n";
        return;
    }

    for(int i = 0; i < v.size(); i++){

        if(visited[i]) continue;

        if(i > 0 && v[i] == v[i - 1] && !visited[i - 1]) continue;

        visited[i] = true;
        result.push_back(v[i]);

        dfs(depth + 1, visited, v);

        visited[i] = false;
        result.pop_back();
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        vector<char> v;
        for(auto ch : s) v.push_back(ch);
        sort(v.begin(), v.end());
        vector<bool> visited(v.size(), false);
        result.clear();

        dfs(0, visited, v);
    }

}