#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);
    unordered_map<int, int> table;

    // Input
    for (int i = 0; i < N; i++)
        cin >> v[i];


    int left = 0;
    int right = 0;
    int answer = 0;

    while (right < N)
    {

        table[v[right]]++;

        // 과일이 2종류 이상인 경우, 왼쪽에서 뺌
        while (table.size() > 2)
        {
            table[v[left]]--;
            if (table[v[left]] == 0)
                table.erase(v[left]);

            left++;
        }

        answer = max(answer, right - left + 1);
        right++;
    }

    cout << answer;

    return 0;
}
