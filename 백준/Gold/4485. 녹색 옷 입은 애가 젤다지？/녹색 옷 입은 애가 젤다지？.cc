#include <iostream>
#include <queue>

using namespace std;

int graph[125][125];
int dist[125][125];

const int INF = 987654321;
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

bool Check(int x, int y, int N)
{

    if (x >= 0 && x < N && y >= 0 && y < N)
        return true;

    return false;
}

struct Edge
{
    int x, y;
    int cost;

    Edge(int x, int y, int cost) : x(x), y(y), cost(cost) {}

    bool operator>(const Edge &e) const
    {
        return cost > e.cost;
    }
};

int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 1;
    int num = 1;
    int answer = 0;

    while (true)
    {
        cin >> N;

        if (N == 0)
            return 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
                dist[i][j] = INF;
            }
        }

        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

        pq.push(Edge(0, 0, graph[0][0]));
        dist[0][0] = graph[0][0];

        while (!pq.empty())
        {
            int nowX = pq.top().x;
            int nowY = pq.top().y;
            int cost = pq.top().cost;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {

                int nextX = nowX + moveX[i];
                int nextY = nowY + moveY[i];
                int nextCost = graph[nextX][nextY] + cost;

                if (Check(nextX, nextY, N))
                {
                    if (dist[nextX][nextY] > nextCost)
                    {
                        dist[nextX][nextY] = nextCost;
                        pq.push(Edge(nextX, nextY, nextCost));
                    }
                }
            }
        }

        cout << "Problem " << num << ": " << dist[N - 1][N - 1] << "\n";
        num++;
    }

    return 0;
}
