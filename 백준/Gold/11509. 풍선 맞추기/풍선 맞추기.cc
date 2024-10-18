#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Finish(vector<int> &v){

    for(auto a : v){
        if(a != 0)
            return false;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int answer = 0;
    cin >> N;
    vector<int> v(N);
    int max_height = 0;

    for(int i = 0; i < N; i++){
        cin >> v[i];
        max_height = max(max_height, v[i]);
    }
    
    

    while(!Finish(v)){
        answer++;
        int now = max_height;
        max_height = 0;
        
        for(int i = 0; i < v.size(); i++){
            
            if(now == v[i]){
                v[i] = 0;
                now--;
            }

            max_height = max(max_height, v[i]);
        }
    }

    cout << answer;
    
    return 0;
}
