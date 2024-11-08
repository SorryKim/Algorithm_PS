#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int left = 0;
    int right = 1;
    int answer = 0;

    int sum = 1;
    while(right <= N && left <= right){

        if(sum == N){
            answer++;
            right++;
            sum += right;
        }
        else if(sum > N){
            sum -= left;
            left++;
        }
        else if(sum < N){
            right++;
            sum += right;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
