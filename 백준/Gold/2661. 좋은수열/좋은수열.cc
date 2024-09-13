#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int N;
string answer = "";

bool Check(string s)
{

    int size = 1;

    while (size * 2 <= s.size())
    {

        string temp1 = s.substr(s.size() - size);
        string temp2 = s.substr(s.size() - (2 * size), size);

        if (temp1 == temp2)
            return false;
        size++;
    }

    return true;
}

void DFS(string s)
{

    if (s.size() == N)
    {
        cout << s;
        exit(0);
    }

    if (answer != "")
        return;

    if (Check(s + "1"))
        DFS(s + "1");

    if (Check(s + "2"))
        DFS(s + "2");

    if (Check(s + "3"))
        DFS(s + "3");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DFS("");
    cout << answer;

    return 0;
}
