#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(a != b){
        answer++;
        a =  ceil(double(a) / 2.0);
        b =  ceil(double(b) / 2.0);
    }
    

    return answer;
}