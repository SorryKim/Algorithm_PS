#include <bits/stdc++.h>
using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool check(string s)
{

    bool flag = false;
    // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    for (char ch : s)
    {
        // 모음 발견
        if (vowels.find(ch) != vowels.end())
        {
            flag = true;
            break;
        }
    }

    // 1번 조건 만족 x
    if (!flag)
        return false;

    // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    int cnt = 0;
    bool isVowel = true;
    for (char ch : s)
    {

        // 모음인 경우
        if (vowels.find(ch) != vowels.end())
        {
            if (isVowel)
                cnt++;
            else
            {
                isVowel = true;
                cnt = 1;
            }
        }
        // 자음인 경우
        else
        {
            if (isVowel)
            {
                isVowel = false;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }

        if (cnt == 3)

            return false;
    }

    // 3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

    for (int i = 0; i < s.size() - 1; i++)
    {
        char now = s[i];
        char next = s[i + 1];

        if (now == 'e' || now == 'o')
            continue;

        if (now == next)

            return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    while (s != "end")
    {

        string answer = check(s) ? "is acceptable.\n" : "is not acceptable.\n";
        cout << "<" << s << "> " << answer;

        cin >> s;
    }

    return 0;
}
