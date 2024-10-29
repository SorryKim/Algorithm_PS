#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    long long N;
    cin >> N;

    long long start = 1;
    long long end = N;
    long long answer = 0;

    while(start <= end){
        long long mid = (start + end) / 2;
       
        if(mid > 0 && mid > N / mid)
            end = mid - 1;
        else{
            answer = mid;
            start = mid + 1;
        }
        
    }

    if(answer * answer < N)
        answer++;
        
    cout << answer << '\n';

    return 0;   
}