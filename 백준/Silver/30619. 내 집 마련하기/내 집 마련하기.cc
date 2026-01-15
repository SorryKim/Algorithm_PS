#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    A.resize(N + 1, 0);
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;

    for(int m = 0; m < M; m++){
        vector<int> houses, people;

        int L, R;
        cin >> L >> R;
        
        for(int i = 1; i <= N; i++){
            if(A[i] >= L && A[i] <= R){
                houses.push_back(i);
                people.push_back(A[i]);
            }
        }

        sort(houses.begin(), houses.end());
        sort(people.begin(), people.end());
        
        vector<int> temp = A;
        for(int i = 0; i < houses.size(); i++) temp[houses[i]] = people[i];
        
        for(int i = 1; i <= N; i++) cout << temp[i] << " ";
        cout << "\n";
    }

    return 0;
}