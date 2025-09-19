#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 후보번호 -> {추천수, 게시된 시각}
    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        // 이미 게시된 후보라면 추천수 증가
        if (mp.find(num) != mp.end())
        {
            mp[num].first++;
        }
        else
        {

            // 아직 사진틀이 남아있다면 추가
            if ((int)mp.size() < N)
            {
                mp[num] = {1, i};
            }
            else
            {

                // 삭제할 후보 찾기 (추천수 최소, 시간 오래된 순)
                int removeId = -1;
                int minCnt = INT_MAX;
                int minTime = INT_MAX;

                for (auto &target : mp)
                {
                    int id = target.first;
                    int cnt = target.second.first;
                    int time = target.second.second;

                    if (cnt < minCnt || (cnt == minCnt && time < minTime))
                    {
                        minCnt = cnt;
                        minTime = time;
                        removeId = id;
                    }
                }
                mp.erase(removeId);
                mp[num] = {1, i};
            }
        }
    }

    // 최종 후보들 정렬 출력
    vector<int> result;
    for (auto &p : mp)
        result.push_back(p.first);
    sort(result.begin(), result.end());

    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
