#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<long long> factorials;
    vector<int> numbers;
    
    factorials.push_back(1);
    for (int i = 1; i <= n; i++) {
        factorials.push_back(factorials[i - 1] * i);
    }

    for (int i = 1; i <= n; i++) 
        numbers.push_back(i);
    

    k--;

    for (int i = n; i > 0; i--) {
        long long idx = k / factorials[i - 1]; // 현재 단계에서 선택해야 할 숫자의 인덱스
        answer.push_back(numbers[idx]); // 해당 숫자를 결과에 추가
        numbers.erase(numbers.begin() + idx); // 선택한 숫자를 리스트에서 제거
        k %= factorials[i - 1]; // k 값 갱신
    }

    return answer;
}
