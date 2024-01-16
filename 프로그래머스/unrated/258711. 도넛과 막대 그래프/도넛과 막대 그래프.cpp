#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 0: 들어오는 간선
// 1: 나가는 간선
int arr[1000001][2];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    for (int i = 0; i < edges.size(); i++) {
        
        int start = edges[i][0];
        int end = edges[i][1];

        arr[start][1]++;
        arr[end][0]++;
    }

    // 도넛, 막대, 8자 순서로 벡터에 집어넣어야함
    int a = 0, b = 0, c = 0;

    for (int i = 1; i <= 1000000; i++) {

        int in = arr[i][0];
        int out = arr[i][1];

        // 시작점인 경우
        if (in == 0 && out >= 2) {
            answer.push_back(i);

            // 전체 그래프 수 도넛 그래프에 저장
            a = out;
        }

        // 막대 그래프인 경우
        // in이 1개이고 out이 0개인 노드가 그래프에 1개 존재
        if (in >= 1 && out == 0)
            b++;
       
        // 8자 그래프인 경우
        // in이 2개이고  out이 2개인 경우
        else if (in >= 2 && out == 2) 
            c++;
        
       
    }

    a = a - b - c;

    answer.push_back(a);
    answer.push_back(b);
    answer.push_back(c);
    return answer;
}