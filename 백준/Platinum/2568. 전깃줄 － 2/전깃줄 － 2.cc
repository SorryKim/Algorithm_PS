#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    // LIS
    vector<int> lis;
    vector<int> index(N, -1);
    vector<int> before(N, -1);

    for (int i = 0; i < N; i++)
    {
        int num = v[i].second;
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int idx = it - lis.begin();

        if (it == lis.end())
            lis.push_back(num);
        else
            *it = num;  // lis에 값 업데이트

        index[i] = idx;  // index 배열에 현재 idx 저장

        // 이전 인덱스 추적을 위한 before 배열 업데이트
        if (idx > 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (index[j] == idx - 1 && v[j].second < v[i].second)
                {
                    before[i] = j;
                    break;
                }
            }
        }
    }

    // LIS에 포함된 인덱스를 역추적
    vector<int> temp;
    int idx = -1;
    for (int i = N - 1; i >= 0; i--)
    {
        if (index[i] == lis.size() - 1)
        {
            idx = i;
            break;
        }
    }

    while (idx != -1)
    {
        temp.push_back(idx);
        idx = before[idx];
    }

    // 제거된 전깃줄 구하기
    vector<int> answer;
    vector<bool> check(N, false);
    for (int i : temp)
        check[i] = true;

    for (int i = 0; i < N; i++)
    {
        if (!check[i])
            answer.push_back(v[i].first);
    }

    // 정답 출력
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto a : answer)
        cout << a << '\n';

    return 0;
}
