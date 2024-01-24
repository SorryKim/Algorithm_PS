#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool check[3001];

int solution(vector<int> nums) {
    int answer = 0;
    
    check[0] = true;
    check[1] = true;
    
	for (int i = 2; i < sqrt(3000); i++){
		if (check[i] == false){
			for (int j = i + i; j <= 3000; j += i){
				check[j] = true;
			}
		}
	}
    
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                int temp = nums[i] + nums[j] + nums[k];
                if(!check[temp]){
                    answer++;
            
                }
            }
        }
    }



    return answer;
}