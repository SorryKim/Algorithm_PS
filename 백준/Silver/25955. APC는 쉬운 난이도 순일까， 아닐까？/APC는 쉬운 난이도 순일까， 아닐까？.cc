#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int tierRank(char c){
    if(c == 'B') return 0;
    if(c == 'S') return 1;
    if(c == 'G') return 2;
    if(c == 'P') return 3;
    return 4;
}

long long score(const string& s){
    char t = s[0];
    int num = stoi(s.substr(1));
    return (long long)tierRank(t) * 1001 + (1000 - num);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> origin(N);
    for(int i = 0; i < N; i++) cin >> origin[i];

    vector<pair<long long,string>> a, b;

    for(auto &x : origin){
        a.push_back({score(x), x});
        b.push_back({score(x), x});
    }

    sort(b.begin(), b.end());

    vector<string> wrong;
    for(int i = 0; i < N; i++){
        if(a[i].second != b[i].second){
            wrong.push_back(a[i].second);
        }
    }

    if(wrong.empty()){
        cout << "OK\n";
    } else {
     
        vector<pair<long long,string>> out;
        for(auto &x : wrong) out.push_back({score(x), x});
        sort(out.begin(), out.end());

        cout << "KO\n";
        cout << out[0].second << " " << out[1].second << "\n";
    }
}
