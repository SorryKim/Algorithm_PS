#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    
    int n = a.size();
    if(n == 1 || n == 2)
        return n;
    
    int answer = 2; // 처음과 마지막은 무조건 가능
    vector<int> left(n); // 왼쪽에서부터 인덱스까지의 최소값 저장
    vector<int> right(n); // 오른쪽에서부터 인덱스까지의 최소값 저장

    left[0] = a[0];
    for(int i = 1; i < n; i++)
        left[i] = min(left[i-1], a[i]);

    right[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        right[i] = min(right[i+1], a[i]);

    
    for(int i = 1; i < n-1; i++){
        int now = a[i];
        // 현재값이 최대값이 아니면 생존 가능
        if(max(now, max(left[i - 1], right[i + 1])) != now)
            answer++;   
    }
    return answer;
}