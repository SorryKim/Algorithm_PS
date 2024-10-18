#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 월, 일을 일수로 변환
int Convert(int month, int day) {
    int result = 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    for (int i = 0; i < month - 1; i++)
        result += days[i];

    result += day;

    return result;
}

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2) {
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> flowers(N);

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        flowers[i].first = Convert(a, b);
        flowers[i].second = Convert(c, d);
    }

    sort(flowers.begin(), flowers.end(), cmp);

    int answer = 0;
    int idx = 0;
    int current = Convert(3, 1);
    int end = Convert(11, 30);

    int temp = 0;

    
    while(current <= end){

        bool flag = false;

        while(idx < N && flowers[idx].first <= current){
            if(flowers[idx].second > temp){
                temp = flowers[idx].second;
                flag = true;
            }
            idx++;
        }

        if(flag){
            answer++;
            current = temp;
        }else{
            answer = 0;
            break;
        }
    }

    cout << answer << '\n';
    return 0;
}
