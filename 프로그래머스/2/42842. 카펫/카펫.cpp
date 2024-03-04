#include <string>
#include <vector>

using namespace std;

pair<int, int> DFS(int brown, int yellow) {
    pair<int, int> result;
    
    int n = 0;
    int m = 0;
    
    for(int i = 1; i <= 5000; i++){
        n = i;
        for(int j = 1; j <= n; j++){
            m = j;
            if(brown == (2 * (n + m) - 4) && yellow == (n - 2) * (m - 2))
                return {n,m};
        }
    }

    return {n,m};
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 갈색: 2n + 2m -4 = 2(n + m) - 4
    // 노란색: (n - 2)(m - 2)

    pair<int, int> temp = DFS(brown, yellow);

    answer.push_back(temp.first);
    answer.push_back(temp.second);
    return answer;
}
