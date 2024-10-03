#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> v;
    set<int> sum_set;
    cin >> N;
    

    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            sum_set.insert(v[i] + v[j]);
        }
    }

    for(int i = N - 1; i >= 0; i--){
        for(int now : sum_set){
            int target = v[i] - now;
            if(target <= 0)
                continue;
            
            int left = 0;
            int right = N - 1;

            while(left <= right){

                int mid = (left + right) / 2;

                if(v[mid] == target){
                    cout << v[i];
                    exit(0);
                }

                if(v[mid] > target){
                    right = mid - 1;
                }else
                    left = mid + 1;
            }
        }
    }
   
    
    return 0;
}
