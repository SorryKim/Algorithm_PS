#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N);
    int left = 0, right = 0;
    for (int i = 0; i < N; i++){
        cin >> v[i];
        right += v[i];
        left = max(left, v[i]);
    }
    
    int ans = 0;
    vector<int> groups;
    
    // 이진 탐색을 통해 "그룹 합의 최댓값"의 후보 ans를 찾는다.
    while(left <= right) {
        int mid = (left + right) / 2;  // 현재 가정하는 그룹 합의 최대값
        int cnt = 0, sum = 0;
        vector<int> temp;
        bool flag = true;
        
        for (int i = 0; i < N; i++){

            // 만약 한 구슬의 값이 mid보다 크다면 mid값으로는 그룹을 구성할 수 없다.
            if(v[i] > mid) {
                flag = false;
                break;
            }
            cnt++;
            sum += v[i];

            // 현재 그룹의 합이 mid를 초과하면, 이번 구슬은 새로운 그룹의 시작
            if(sum > mid){
                temp.push_back(cnt - 1);
                cnt = 1;                
                sum = v[i];
            }
        }
        if(!flag) {  // mid값이 한 구슬보다 작으면 불가능
            left = mid + 1;
            continue;
        }
        temp.push_back(cnt);  // 마지막 그룹 추가
        
        // 그리디로 구한 그룹 수가 M보다 많으면, mid값이 너무 작으므로 늘려야 함.
        // 반대로 temp.size() <= M 인 경우는 후보로 사용할 수 있음.
        if(temp.size() > M) {
            left = mid + 1;
        } else {
            ans = mid;
            groups = temp;
            right = mid - 1;
        }
    }
    
    // 그룹의 개수가 M보다 작다면, 남은 그룹(더 분할할 수 있는 그룹)을 추가로 쪼개서 M개로 맞춘다.
    vector<int> finalGroups;

    for (int i = 0; i < groups.size(); i++){
       
        int num = M - (int)finalGroups.size() - (groups.size() - i);
        int splits = min(groups[i] - 1, num);
        for (int j = 0; j < splits; j++){
            finalGroups.push_back(1);
            groups[i]--;
        }
        
        finalGroups.push_back(groups[i]);
    }

    groups = finalGroups;
    
    // Output
    cout << ans << "\n";
    for (int num : groups)
        cout << num << " ";
    cout << "\n";
    
    return 0;
}