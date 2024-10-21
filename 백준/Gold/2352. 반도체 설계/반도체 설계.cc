#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int answer = 0;

    cin >> N;
    vector<int> v(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> v[i];
    
    // 증가 감소 조합 확인해보면 될 듯...

    // 1) v[0] <= v[1] 부분집합구하기
    vector<int> temp;
    for(int i = 1; i < v.size(); i++){

        if(temp.empty() || temp[temp.size() - 1] < v[i])
            temp.push_back(v[i]);
        else{
            int idx = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            temp[idx] = v[i];
        }
    }

    answer = temp.size();

    // 1) v[0] >= v[1] 부분집합구하기
    temp.clear();
    
    for(int i = v.size() - 1; i > 0; i--){

        if(temp.empty() || temp[temp.size() - 1] > v[i])
            temp.push_back(v[i]);
        else{
            int idx = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            temp[idx] = v[i];
        }
    }

    answer = max(answer, (int)temp.size());

    cout << answer << '\n';

    return 0;
}
