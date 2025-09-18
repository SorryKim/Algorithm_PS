#include <bits/stdc++.h>

using namespace std;

int N, K, L;
set<pair<int, int>> apples;
vector<pair<int, char>> moves;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> K;

    // 사과의 위치 입력받기
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        apples.insert({x, y});
    }

    // 이동 방향 입력 받기
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int t;
        char dir;
        cin >> t >> dir;
        moves.push_back({t, dir});
    }
}

int solve()
{
    int answer = 0;

    deque<pair<int, int>> snake;
    snake.push_front({1, 1});
    set<pair<int, int>> body;
    body.insert({1, 1});

    int dir = 0;
    int moveIdx = 0;

    while (true)
    {
        answer++;

        // 머리 이동
        pair<int, int> head = {
            snake.front().first + dx[dir],
            snake.front().second + dy[dir]};

        // 머리 벽 충돌 체크
        if (head.first > N || head.first <= 0 || head.second > N || head.second <= 0)
            return answer;

        // 몸과 충돌 체크
        if (body.find(head) != body.end())
            return answer;

        // 머리 이동
        snake.push_front(head);
        body.insert(head);

        // 사과확인
        if (apples.find(head) != apples.end())
        {
            apples.erase(head); // 사과 먹기, 꼬리 삭제 x
        }
        // 사과 없는 경우
        else
        {
            body.erase(snake.back());
            snake.pop_back();
        }

        // 방향 전환 확인
        if (moveIdx < L && answer == moves[moveIdx].first)
        {

            char ch = moves[moveIdx].second;
            if (ch == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            moveIdx++;
        }
    }

    return answer;
}

int main()
{
    input();
    cout << solve() << '\n';
}