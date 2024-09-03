#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int moveH[4] = {1, -1 , 0, 0};
    int moveW[4] = {0, 0, 1, -1};
    
    string target = board[h][w];
    
    for(int i = 0; i < 4; i++){
        int nextH = h + moveH[i];
        int nextW = w + moveW[i];
        
        if(nextH >= 0 && nextH < board.size() && nextW >= 0 && nextW < board[0].size()){
            if(target == board[nextH][nextW])
                answer++;
        }
    }
    
    return answer;
}