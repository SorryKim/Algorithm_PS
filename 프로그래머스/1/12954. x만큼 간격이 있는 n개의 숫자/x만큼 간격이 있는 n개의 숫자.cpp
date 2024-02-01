#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int num = 0;
    while(n--){
        num += x;
        answer.push_back(num);
    }
    return answer;
}