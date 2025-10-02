#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
int N;

vector<string> splitString(const string &s){
    vector<string> result;
    string temp;
    stringstream ss(s);

    while(getline(ss, temp, '\\')) result.push_back(temp);

    return result;
}

struct Trie{

    map<string, Trie*> mp;
    bool isEnd;

    Trie(){
        isEnd = false;
    }

    void insert(const string &s){

        vector<string> v = splitString(s);
        Trie* node = this;

        for(string now : v){
            if(node->mp.find(now) == node->mp.end()){
                node->mp[now] = new Trie();
            }

            node = node->mp[now];
        }

        node->isEnd = true;
    }

    void print(int depth, Trie* node){

        for(auto a : node->mp){
            for(int i = 0; i < depth; i++) cout << " ";
            cout << a.first << "\n";
            print(depth + 1, a.second);
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    Trie* root = new Trie();

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        root->insert(s);
    }
    
    root->print(0, root);
}