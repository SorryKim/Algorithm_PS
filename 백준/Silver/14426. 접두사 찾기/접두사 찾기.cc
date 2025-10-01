#include <iostream>

using namespace std;

struct Trie{

    Trie* next[26];
    bool isEnd;

    Trie(){
        for(int i = 0; i < 26; i++) next[i] = nullptr;
        isEnd = false;
    }

    void insert(const string &s){
        
        Trie* node = this;
        for(char c : s){
            int idx = c - 'a';
            if(node->next[idx] == nullptr){
                node->next[idx] = new Trie();
            }
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    bool startsWith(const string &prefix){
        Trie* node = this;

        for(char c : prefix){
            int idx = c - 'a';
            if(node->next[idx] == nullptr) return false;
            node = node->next[idx];
        }

        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Trie* root = new Trie();

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        root->insert(s);
    }

    int ans = 0;
    for(int i = 0; i < M; i++){
        string target;
        cin >> target;
        if(root->startsWith(target)) ans++;
    }

    cout << ans << "\n";
}