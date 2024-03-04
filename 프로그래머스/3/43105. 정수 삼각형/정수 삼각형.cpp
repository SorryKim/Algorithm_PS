#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = triangle.size() - 1; i > 0;  i--){
        vector<int> row = triangle[i];
        for(int j = 0 ; j < row.size() - 1; j++){
            triangle[i -1][j] += max(triangle[i][j], triangle[i][j+1]);
        }
    }
    
    answer = triangle[0][0];
    
    return answer;
}