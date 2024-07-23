#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool check[1000001] = {false, };

int solution(int n) {
    int answer = 0;
    
    check[1] = true;
    for (int i = 2; i <= sqrt(1000000); i++){
        if (check[i])
            continue;
        for (int j = i * i; j <= 1000000; j += i)
            check[j] = true;
    }

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            answer++;
          
        }
    }
    
    return answer;
}