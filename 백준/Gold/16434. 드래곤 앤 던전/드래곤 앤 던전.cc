#include <bits/stdc++.h>
using namespace std;

struct Room
{
    int t;
    long long a, h;

    Room(int t, long long a, long long h)
    {
        this->t = t;
        this->a = a;
        this->h = h;
    }
};

long long N, ATK;
vector<Room> rooms;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> ATK;

    for (int i = 0; i < N; i++)
    {
        int t;
        long long a, h;
        cin >> t >> a >> h;
        rooms.push_back(Room(t, a, h));
    }
}

// 해당 MaxHP로 게임 클리어가 가능한지
bool play(long long MaxHP)
{

    // 초기 용사 세팅
    long long CurHP = MaxHP;
    long long atk = ATK;

    for (Room room : rooms)
    {
        // 현재 방이 몬스터인 경우
        if (room.t == 1)
        {
            long long monsterATK = room.a;
            long long monsterHP = room.h;

            // 필요한 공격 횟수 (올림)
            long long heroTurns = (monsterHP + atk - 1) / atk;

            // 몬스터의 공격 횟수
            long long monsterTurns = heroTurns - 1;

            // 용사 체력 감소
            CurHP -= monsterATK * monsterTurns;

            // 용사가 죽었는지 확인
            if (CurHP <= 0)
                return false;
        }
        // 현재 방이 물약인 경우
        else
        {
            atk += room.a;
            CurHP += room.h;
            CurHP = min(CurHP, MaxHP); // 최대체력이상으로 회복은 불가
        }
    }

    return true;
}

long long solve()
{

    long long result;

    long long left = 1;
    long long right = LONG_LONG_MAX - 1;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (play(mid))
        {
            right = mid - 1;
            result = mid;
        }
        else
            left = mid + 1;
    }

    return result;
}

int main()
{
    input();
    cout << solve() << '\n';
    return 0;
}
