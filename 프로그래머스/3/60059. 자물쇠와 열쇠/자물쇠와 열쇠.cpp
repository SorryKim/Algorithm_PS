#include <vector>
#include <iostream>

using namespace std;

// 배열의 회전
void Rotate(vector<vector<int>>& arr) {
    int N = arr.size();
    for(int i = 0; i < N/2; i++){
        for(int j = i; j < N - 1 - i; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][i];
            arr[N - 1 - j][i] = arr[N - 1 - i][N - 1 - j];
            arr[N - 1 - i][N - 1 - j] = arr[j][N - 1 - i];
            arr[j][N - 1 - i] = temp;
        }
    }
}

bool Check(vector<vector<int>> &key, vector<vector<int>> &lock, int x, int y) {
    
    int M = key.size();
    int N = lock.size();
    
    // 자물쇠에 열쇠를 맞춰본다.
    vector<vector<int>> temp = lock;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int lockX = i + x;
            int lockY = j + y;
            
            if (lockX >= 0 && lockX < N && lockY >= 0 && lockY < N) {
                
                // 돌기와 돌기가 만나면 안됨
                if (temp[lockX][lockY] == 1 && key[i][j] == 1)
                    return false;
                
                // 홈이 열쇠의 돌기로 채워짐
                if (temp[lockX][lockY] == 0 && key[i][j] == 1)
                    temp[lockX][lockY] = 1;
            }
        }
    }
    
    // 자물쇠가 다 채워졌는지 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j] == 0) {
                return false;
            }
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();

    
    for (int r = 0; r < 4; r++) {  
        
        for (int i = 1 - M; i < N; i++) {
            for (int j = 1 - M; j < N; j++) {
                if (Check(key, lock, i, j))
                    return true;
            }
        }
        
        Rotate(key);
    }
    
    return false;
}


