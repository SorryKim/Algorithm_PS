#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    
    int dp[201][201];
    int N = matrix_sizes.size();
    
    for(int length = 1; length < N; length++){
        for(int start = 0; start + length < N; start++){
            int end = start + length;
            dp[start][end] = 987654321;
            for(int i = start; i < end; i++){
                int temp = matrix_sizes[start][0] * matrix_sizes[i][1] * matrix_sizes[end][1];
                dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + temp);
            }
        }
    }
    
    
    answer = dp[0][N - 1];
    
    return answer;
}