#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b > a) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    int limit = 1;

    // 모든 신호등 주기의 최소공배수
    for (auto& s : signals) {
        int G = s[0];
        int Y = s[1];
        int R = s[2];
        
        int cycle = G + Y + R;
        limit = lcm(limit, cycle);
    }

    // 1초부터 최소공배수까지 탐색
    for (int t = 1; t <= limit; t++) {
        bool allYellow = true;

        for (auto& s : signals) {
            int G = s[0];
            int Y = s[1];
            int R = s[2];

            int cycle = G + Y + R;
            int now = (t - 1) % cycle;

            // 노란불이 아닌 경우
            if (now < G || now >= G + Y) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) return t;
    }

    return -1;
}
