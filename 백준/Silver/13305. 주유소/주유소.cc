#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long answer = 0;
    vector<long long> dist;
    vector<long long> city;

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        long long num;
        cin >> num;
        dist.push_back(num);
    }

    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        city.push_back(num);
    }

    long long oil = LLONG_MAX;

    for(int i = 0; i < N - 1; i++){

        oil = min(oil, city[i]);

        answer += oil * dist[i];
    }


    cout << answer;

    return 0;
}
