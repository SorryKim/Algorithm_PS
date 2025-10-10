#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

string change(long long number) {
    if (number == 0) return "0";

    string result = "";
    while (number > 0) {
        result += to_string(number % 2);
        number /= 2;
    }
    
    reverse(result.begin(), result.end());

    long long h = 1;
    while ((1LL << h) - 1 < result.size()) h++;

    long long total = (1LL << h) - 1;
    string temp(total - result.size(), '0');
    return temp + result;
}

bool check(const string &s, int start, int end) {
    if (start >= end) return true;

    int mid = (start + end) / 2;
    char root = s[mid];

    int leftMid = (start + mid - 1) / 2;
    int rightMid = (mid + 1 + end) / 2;

    // 부모가 0인데 자식 루트가 1이면 불가능
    if (root == '0') {
        if ((start <= mid - 1 && s[leftMid] == '1') ||
            (mid + 1 <= end && s[rightMid] == '1'))
            return false;
    }

    return check(s, start, mid - 1) && check(s, mid + 1, end);
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long number : numbers) {
        string target = change(number);
        answer.push_back(check(target, 0, target.size() - 1) ? 1 : 0);
    }
    return answer;
}