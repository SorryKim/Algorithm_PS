#include <string>
#include <vector>
#include <algorithm>


using namespace std;
int N = 0;

bool cmp(string s1, string s2){
    
    if(s1[N] != s2[N])
        return s1[N] < s2[N];   
    
    return s1 < s2;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    answer = strings;

    sort(answer.begin(), answer.end(), cmp);
    
    
    return answer;
}