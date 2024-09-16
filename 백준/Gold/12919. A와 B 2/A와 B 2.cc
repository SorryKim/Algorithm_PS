#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>

using namespace std;

int answer = 0;

void Func(string t, const string &s)
{
    if (t == s)
    {
        answer = 1;
        return;
    }

    if (t.size() <= s.size() || answer == 1)
        return;

    // 마지막 문자가 'A'인 경우
    if (t.back() == 'A')
    {
        string temp = t;
        temp.pop_back();
        Func(temp, s);
    }

    // 첫 번째 문자가 'B'인 경우
    if (t.front() == 'B')
    {
        string temp = t;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        Func(temp, s);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    string T;
    cin >> S >> T;

    Func(T, S);
    cout << answer;

    return 0;
}
