#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture {
    int num, start, end;

    Lecture() : num(0), start(0), end(0) {}
    Lecture(int num, int start, int end) : num(num), start(start), end(end) {}

    static bool compareByStart(const Lecture& a, const Lecture& b) {
        return a.start < b.start;
    }

    struct CompareByEnd {
        bool operator()(const Lecture& a, const Lecture& b) {
            return a.end > b.end;
        }
    };
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    int answer = 0; 
    cin >> N;

    vector<Lecture> lectures(N);
    vector<int> room(N, 0); // 각 강의의 강의실 번호
    priority_queue<Lecture, vector<Lecture>, Lecture::CompareByEnd> pq; 

    for (int i = 0; i < N; i++) {
        int num, start, end;
        cin >> num >> start >> end;
        lectures[i] = Lecture(num, start, end);
    }

    // 시작 시간 기준으로 정렬
    sort(lectures.begin(), lectures.end(), Lecture::compareByStart);

    // 강의실 배정
    for (int i = 0; i < N; i++) {

        // 이전 강의실을 그대로 사용하는 경우
        if (!pq.empty() && pq.top().end <= lectures[i].start) {
            room[lectures[i].num - 1] = room[pq.top().num - 1];
            pq.pop();
        } 
        // 새로운 강의실이 필요한 경우
        else {
            answer++;
            room[lectures[i].num - 1] = answer;
        }
        
        pq.push(lectures[i]);
    }

    // 결과 출력
    cout << answer << "\n";
    for (int i = 0; i < N; i++) cout << room[i] << "\n";
    

    return 0;
}
