#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 부분집합의 합 리턴
vector<long long> Sum(const vector<int>& v) {
    vector<long long> result;
    int n = v.size();
    int size = 1 << n; // 부분집합의 총 개수는 2^n개

    for(int i = 0; i < size; i++){ 
        long long sum = 0;

        for(int j = 0; j < n; j++){
            if(i & (1 << j))
                sum += v[j];
        }

        result.push_back(sum);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long S;
    cin >> N >> S;

    vector<int> v1, v2;
    vector<long long> sum1, sum2;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;

        if(i < N / 2)
            v1.push_back(num);
        else
            v2.push_back(num);
    }

    sum1 = Sum(v1);
    sum2 = Sum(v2);

    sort(sum2.begin(), sum2.end());
    long long answer = 0;

    for(auto now : sum1){
        long long target = S - now;

        // target값을 만족하는 수가 여러번 나올 수 있음
        auto lower = lower_bound(sum2.begin(), sum2.end(), target);
        auto upper = upper_bound(sum2.begin(), sum2.end(), target);
        answer += (upper - lower);
    }

    if(S == 0)
        answer--;
        
    cout << answer;

    return 0;
}
