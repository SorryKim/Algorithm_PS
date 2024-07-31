#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> mySet;
    int n = elements.size();
    
    for(int length = 1; length <= n; length++) {
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j - i < length; j++){
                sum += elements[j % n];
            }
            mySet.insert(sum);
        }
    }
    
    answer = mySet.size();
    return answer;
}
