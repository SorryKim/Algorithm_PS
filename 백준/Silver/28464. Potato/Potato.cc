#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> potatoes, answer;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int potato;
        cin >> potato;
        potatoes.push_back(potato);
    }
}

pair<int, int> solve()
{
    pair<int, int> result = make_pair(0, 0);

    sort(potatoes.begin(), potatoes.end());
    int left = 0;
    int right = potatoes.size() - 1;

    while (left <= right)
    {

        if (left == right)
        {
            result.second += potatoes[left];
            break;
        }

        result.first += potatoes[left];
        result.second += potatoes[right];

        left++;
        right--;
    }

    return result;
}

int main()
{
    input();

    pair<int, int> result = solve();
    cout << result.first << ' ' << result.second << '\n';

    return 0;
}
