#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void Hanoi(int n, int start, int temp, int end) {
    
    if (n == 1) {
        answer.push_back({start, end});
        return;
    }

    Hanoi(n - 1, start, end, temp);
    answer.push_back({start, end});
    Hanoi(n - 1, temp, start, end);
}

vector<vector<int>> solution(int n) {
    Hanoi(n,1,2,3);
    return answer;
}