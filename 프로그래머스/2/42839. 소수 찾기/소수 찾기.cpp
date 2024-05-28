#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<bool> isPrime(10000000, true);


// 재귀를 이용하여 모든 조합 생성
void generateCombinations(const string& numbers, string current, vector<bool>& used, set<int>& combinations) {
    
    if (!current.empty()) {
         combinations.insert(stoi(current));
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            generateCombinations(numbers, current + numbers[i], used, combinations);
            used[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    int maxV = 10000000;
   
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i = 2; i < sqrt(maxV); i++){
        if(isPrime[i]){
            for(int j = i * i; j <= maxV; j += i){
                isPrime[j] = false;
            }
        }
    }
    vector<bool> used(numbers.length(), false);
    set<int> combinations;
    
    generateCombinations(numbers, "", used, combinations);
    
    for(int a : combinations){
        if(isPrime[a])
            answer++;
    }
    
    
    return answer;
}