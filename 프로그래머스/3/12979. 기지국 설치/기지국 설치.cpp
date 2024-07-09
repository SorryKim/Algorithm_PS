#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int temp = 1;
    int range = 2*w + 1;
    
    for(auto station : stations){
        
        int start = station - w;
        int end = station + w;
        
        if(temp < start){
            int length = start - temp;
            
            if(length % range == 0)
                answer += length / range;
            else
                answer += (length / range) + 1;
            
            
        }
        
        temp = end + 1;
    }
    
    int last = stations[stations.size() - 1] + w;
    
    if(last < n){
        int length = n - last;
        if(length % range == 0)
            answer += length / range;
        else
            answer += (length / range) + 1;
        
    }
    
    return answer;
}