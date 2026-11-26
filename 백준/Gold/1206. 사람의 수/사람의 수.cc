#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N, 0);
    for(int i = 0; i < N; i++){
        double d;
        cin >> d;
        v[i] = round(d * 1000);
    }

    int answer = 1;
    bool finish = false;
    while(!finish){

        finish = true;
        for(auto now : v){
            int low = now * answer;
            int high = (now + 1) * answer;

            int sum = (low + 999) / 1000;

            if(sum * 1000 >= high) {
                finish = false;
                break;
            }
        }

        if(finish) break;
        else answer++;
    }

    cout << answer << "\n";

    return 0;
}