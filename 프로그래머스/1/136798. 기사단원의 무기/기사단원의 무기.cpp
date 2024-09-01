#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 약수의 갯수를 반환하는 함수
int Func(int n) {
    unordered_map<int, int> table;
    int result = 1;
    
    // 2로 나누기
    while (n % 2 == 0) {
        table[2]++;
        n /= 2;
    }

    // 3부터 시작해서 n의 제곱근까지 홀수로 나누기
    for (int i = 3; i * i <= n; i++) {
        while (n % i == 0) {
            table[i]++;
            n /= i;
        }
    }

    // 만약 n이 소수인 경우
    if (n > 2) {
        table[n]++;
    }

    
    for (auto now : table) 
        result *= (now.second + 1);
    

    return result;
}


int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++){
        int val = Func(i);
        if(val <= limit)
            answer += val;
        else
            answer += power;
    }
    
    return answer;
}