#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;

    while (getline(cin, a) && getline(cin, b))
    {
        int countA[26] = {0};
        int countB[26] = {0};

        // 문자열 a의 각 문자 빈도수 계산
        for (char ch : a)
            countA[ch - 'a']++;

        // 문자열 b의 각 문자 빈도수 계산
        for (char ch : b)
            countB[ch - 'a']++;

        string result = "";
        // 알파벳 순서대로 공통 문자 추출
        for (int i = 0; i < 26; ++i)
        {
            int cnt = min(countA[i], countB[i]);
            result += string(cnt, 'a' + i);
        }

        cout << result << "\n";
    }

    return 0;
}
