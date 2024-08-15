#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int N;
int arr[21][21];
int answer = 987654321;

void DFS(int n, vector<int> start, vector<int> link)
{

    if (start.size() == N / 2 && link.size() == N / 2)
    {
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < N / 2; i++)
        {
            int now = start[i];
            for (int j = i + 1; j < N / 2; j++)
            {
                int next = start[j];
                sum1 += arr[now][next];
                sum1 += arr[next][now];
            }
        }

        for (int i = 0; i < N / 2; i++)
        {
            int now = link[i];
            for (int j = i + 1; j < N / 2; j++)
            {
                int next = link[j];
                sum2 += arr[now][next];
                sum2 += arr[next][now];
            }
        }

        answer = min(answer, abs(sum1 - sum2));

        return;
    }

    if (start.size() < N / 2)
    {
        start.push_back(n);
        DFS(n + 1, start, link);
        start.pop_back();
    }

    if (link.size() < N / 2)
    {
        link.push_back(n);
        DFS(n + 1, start, link);
        link.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    vector<int> start, link;

    DFS(1, start, link);
    cout << answer << '\n';

    return 0;
}
