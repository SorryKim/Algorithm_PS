#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> numbers;

    for (char a : number) {
        
        // 뒷자리 숫자가 현재보다 작을 경우 교체
        while (!numbers.empty() && numbers.back() < a && k > 0) {
            numbers.pop_back();
            k--;
        }
        numbers.push_back(a);
    }

    // 필요한 숫자를 다 지웠다면, 나머지는 그냥 추가한다.
    while (k > 0) {
        numbers.pop_back();
        k--;
    }

    for (char a : numbers) {
        answer += a;
    }

    return answer;
}
