#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getDiv(int num){
    
    vector<int> v;
    
    for(int i = 1; i <= num; i++){
        if(num % i == 0)
            v.push_back(i);
    }
    
    return v;
}

// num으로 모든 원소를 나눌 수 있는지 확인하는 함수
bool Check1(int num, vector<int> &v){
    
    for(auto a : v){
        if(a % num != 0)
            return false;
    }
    
    return true;
}

// num으로 모든 원소를 나눌 수 없는지 확인하는 함수
bool Check2(int num, vector<int> &v){
    
    for(auto a : v){
        if(a % num == 0)
            return false;
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    // 두 배열을 정렬
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    // arrayA의 약수 중 arrayB를 나누지 않는 최대 값 찾기
    vector<int> divA = getDiv(arrayA[0]);
    int maxA = 0;
    for(int divisor : divA) {
        if(Check1(divisor, arrayA) && Check2(divisor, arrayB)) {
            maxA = max(maxA, divisor);
        }
    }
    
    // arrayB의 약수 중 arrayA를 나누지 않는 최대 값 찾기
    vector<int> divB = getDiv(arrayB[0]);
    int maxB = 0;
    for(int divisor : divB) {
        if(Check1(divisor, arrayB) && Check2(divisor, arrayA)) {
            maxB = max(maxB, divisor);
        }
    }
    
    // 최종 결과
    answer = max(maxA, maxB);
    return answer;
}
