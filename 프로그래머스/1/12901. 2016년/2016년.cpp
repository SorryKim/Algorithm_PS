#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> days = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> ans = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int num = -1;
    for(int i = 0; i < a; i++)
        num += days[i];
    num += b;
    num %= 7;
    
    answer = ans[num];
    return answer;
}