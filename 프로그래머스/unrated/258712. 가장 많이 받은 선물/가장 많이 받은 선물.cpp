#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// 문자열을 나누는 함수
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

// 선물 주고받은 여부 체크
int arr[51][51];
// 선물지수 기록
int score[51];
// 다음달에 받을 선물갯수 기록
int nextMonth[51];

// 이름을 입력하면 해당 이름의 인덱스를 출력하는 메소드
int searchIdx(vector<string> v, string name) {

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == name)
            return i;
    }

    return -1;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    for (string s : gifts) {
        // 0 : 선물을 준 사람
        // 1 : 선물을 받은 사람
        vector<string> input = split(s, ' ');
        int giver = searchIdx(friends, input[0]);
        int receiver = searchIdx(friends, input[1]);

        // 선물 증정여부 체크
        arr[giver][receiver]++;

        // 선물지수 반영
        score[giver]++;
        score[receiver]--;
    }

    for (int i = 0; i < friends.size(); i++) {

        for (int j = 0; j < friends.size(); j++) {

            // 자기 자신인 경우 pass
            if (i == j)
                continue;

            // a와 b가 선물을 교환했던 적이 있는 경우
            if (arr[i][j] != 0 || arr[j][i] != 0) {
                
                // a가 더많이 준 경우
                if (arr[i][j] > arr[j][i])
                    nextMonth[i]++;
                // 둘이 같은 경우
                else if(arr[i][j] == arr[j][i]){
                    if (score[i] > score[j]) 
                        nextMonth[i]++;              
                }
            }
            // 선물 교환했던 적이 없던 경우
            else {
                if (score[i] > score[j]) 
                    nextMonth[i]++;
               
            }
        }
    }

    for (int i = 0; i < friends.size(); i++) {
        answer = max(answer, nextMonth[i]);
    }

    

    return answer;
}
