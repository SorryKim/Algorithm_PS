#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    answer.push_back(0);
    answer.push_back(sequence.size() - 1);
    
    int start = 0;
    int end = 0;
    int sum = sequence[0];
    
    while(start <= end){
        
        if(end == sequence.size())
            break;
        if(sum == k){
            int len = answer[1] - answer[0];
            if(len > end - start){
                answer[0] = start;
                answer[1] = end;
            }
            
            sum -= sequence[start];
            sum += sequence[end + 1];
            start++;
            end++;
        }
        
        else if(sum > k){
            sum -= sequence[start];
            start++;
        }
        
        else if(sum < k){
            
            end++;
            if(end == sequence.size())
                break;
            sum += sequence[end];
        }
        
    }
    
    
    
    
    
    return answer;
}