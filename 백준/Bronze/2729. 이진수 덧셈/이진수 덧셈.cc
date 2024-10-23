#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string Calc(string a, string b) {
    // 먼저 자리수 맞춰줌
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;

    string result = "";
    int carry = 0;
    
    for (int i = a.size() - 1; i >= 0; i--) {
        int num_a = a[i] - '0';
        int num_b = b[i] - '0';

        int sum = num_a + num_b + carry;
        char ch = sum % 2 ? '1' : '0';

        result = ch + result;
        carry = sum / 2;
    }
    
    if (carry)
        result = '1' + result;

    
    bool flag = false;
    string answer = "";

    for(int i = 0; i < result.size(); i++){
        if(result[i] == '1')
            flag = true;
        
        if(flag)
            answer += result[i];
    }

    if(answer == "")
        answer = "0";
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        string a, b;
        cin >> a >> b;
        cout << Calc(a, b) << '\n';
    }

    return 0;
}
