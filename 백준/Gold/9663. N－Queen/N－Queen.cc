#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int answer = 0;
int N;

void DFS(int depth, vector<int> v)
{

    if (depth == N)
    {
        answer++;
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        bool flag = true;

        for (int j = 1; j <= depth; j++)
        {
            if (v[j] == i)
            {
                flag = false;
                break;
            }

            if (abs(j - (depth + 1)) == abs(v[j] - i))
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            v[depth + 1] = i;
            DFS(depth + 1, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> v(N + 1, -1);

    for (int i = 1; i <= N; i++)
    {
        v[1] = i;
        DFS(1, v);
    }

    cout << answer << "\n";
    return 0;
}
