#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;
unordered_map<int, set<int>> table;

// (n1 + n2)개의 원소를 사용하는 경우 set에 추가
void func(int n1, int n2){
    int next = n1 + n2;
    
    for(auto a : table[n1]){
        for(auto b : table[n2]){
            table[next].insert(a + b);
            if(a - b > 0)
                table[next].insert(a - b);
            table[next].insert(a * b);
            if(a / b > 0)
                table[next].insert(a / b);
        
            if(b - a > 0)
                table[next].insert(b - a);
            if(b / a > 0)
                table[next].insert(b / a);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    
    for(int i = 1; i <= 8; i++){
        table.insert({i, set<int>{}});
    }
    
    // 1개
    table[1].insert(N);
    
    // 2개
    table[2].insert(N*11);
    table[2].insert(N + N);
    table[2].insert(N * N);
    table[2].insert(N / N);
    
    // 3개
    table[3].insert(N*111);
    func(1,2);
    
    // 4개
    table[4].insert(N*1111);
    func(1,3);
    func(2,2);
    
    // 5개
    table[5].insert(N*11111);
    func(1,4);
    func(2,3);
    
    // 6개
    table[6].insert(N*111111);
    func(1,5);
    func(2,4);
    func(3,3);
    
    // 7개
    table[7].insert(N*1111111);
    func(1,6);
    func(2,5);
    func(3,4);
    
    // 8개
    table[8].insert(N*11111111);
    func(1,7);
    func(2,6);
    func(3,5);
    func(4,4);   
    
    for(int i = 1; i <= 8; i++){
        auto it = table[i].find(number);
        if(it != table[i].end()){
            answer = i;
            break;
        }
    }
   
    return answer == 0 ? -1 : answer;
}