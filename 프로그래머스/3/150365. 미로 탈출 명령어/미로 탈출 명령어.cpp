#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int R, C;
string answer;

void DFS(int x, int y, string path){
    
    if(answer != "") return;
    
    // 도착하면 끝
    if(x == R && y == C && path.size() == K){
        answer = path;
        return;
    }
    
    if(path.size() == K) return;
    
    // 남은 거리, 도착지 못가는 경우
    int dist = abs(R - x) + abs(C - y);
    if(K < path.size() + dist) return;
    if ((K - path.size() - dist) % 2 != 0) return; // 홀짝기반 못가는 경우
    
    // 사전순 d l r u
    
    // d
    if(x + 1 <= N) DFS(x + 1 , y, path + "d");
    
    // l
    if(y - 1 > 0) DFS(x, y - 1, path + "l");
    
    // r
    if(y + 1 <= M) DFS(x, y + 1, path + "r");
    
    // u
    if(x - 1 > 0) DFS(x - 1, y, path + "u");
    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    N = n;
    M = m;
    R = r;
    C = c;
    K = k;
    answer = "";
    DFS(x, y, "");
    if(answer == "") return "impossible";
    return answer;
}