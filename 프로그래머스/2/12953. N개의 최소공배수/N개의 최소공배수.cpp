#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int LCM(int a, int b){
    
    return (a*b) / GCD(a,b);
}

bool cmp(int a, int b){
    
    return a > b;
}

int solution(vector<int> arr) {
   
    
    sort(arr.begin(), arr.end());
    
    int answer = arr[0];
    for(int i = 1; i < arr.size(); i++){
        answer = LCM(answer, arr[i]);
    }
    
    return answer;
}