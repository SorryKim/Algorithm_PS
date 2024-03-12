#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int arr[100] = { 0, };
    stack<int> st;
    vector<int> v;
    
    for(int i = 0; i < progresses.size(); i++){
        
        int now = progresses[i];
        int speed = speeds[i];
        
        int temp = 1;
        while(now + speed*temp < 100){
            temp++;
        }
        
        v.push_back(temp);
        
    }
        
    // 7 3 9 -> 2 1
    // 5 10 1 1 20 1 -> 1 3 2
    int cnt = 1;
    int temp = v[0];
    
    for(int i = 1; i < v.size(); i++){
        
        if(temp >= v[i]){
            cnt++;
        }else{
            answer.push_back(cnt);
            temp = v[i];
            cnt = 1;
        }
        
        if(i == v.size() - 1)
            answer.push_back(cnt);
    }
    
    
    return answer;
}