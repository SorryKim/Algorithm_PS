#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double d = (double)num1 / (double)num2;
    d *= 1000;
    answer = (int)d;
    return answer;
}