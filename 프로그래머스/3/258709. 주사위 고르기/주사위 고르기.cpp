#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Selection
{
    // 해당 선택에서 A가 승리, 패배, 무승부의 경우의 수
    int win, lose, draw;

    // A와 B가 선택한 주사위 번호를 담을 벡터
    vector<int> A, B;

    // 생성자
    Selection(vector<int> a, vector<int> b) {
        win = 0;
        lose = 0;
        draw = 0;

        A = a;
        B = b;
    }

    Selection() {}

};

int N;
vector<Selection> selections;


// DFS로 A,B의 주사위 번호를 나누어줌
void DFS(int diceNo, vector<int> A, vector<int> B,int countA, int countB) {
    
    if (countA == N / 2 && countB == N / 2) {
        selections.push_back(Selection(A, B));
        return;
    }

    if (countA < N / 2) {
        A[countA] = diceNo;
        DFS(diceNo + 1, A , B, countA + 1, countB);
    }

    if (countB < N / 2) {
        B[countB] = diceNo;
        DFS(diceNo + 1, A, B, countA, countB + 1);
    }
    
}


vector<int> scoreA;
vector<int> scoreB;

void diceSelect(int depth, vector<int> v, Selection &selection, vector<vector<int>> dice) {
    
    if (depth == N/2) {
        int tempA = 0;
        int tempB = 0;
        for (int i = 0; i < N / 2; i++) {
            int diceA = selection.A[i];
            int diceB = selection.B[i];
            tempA += dice[diceA][v[i]];
            tempB += dice[diceB][v[i]];
        }
        scoreA.push_back(tempA);
        scoreB.push_back(tempB);

        return;
    }

    for (int i = 0; i < 6; i++) {
        v[depth] = i;
        diceSelect(depth + 1, v, selection, dice);
    }

}


vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    vector<int> a(N/2);
    vector<int> b(N/2);

    // 주사위 배분
    DFS(0, a, b, 0, 0);

    // 주사위 덧셈 경우의 수 계산하기
    for (Selection &selection : selections) {
        vector<int> vec(N/2);
        scoreA.clear();
        scoreB.clear();
        diceSelect(0, vec, selection, dice);

        sort(scoreB.begin(), scoreB.end());

        for (int nowA : scoreA) {

            // 이진탐색을 통해 값을 검색
            // nowA값과 동일한 수가 나오는 첫 인덱스
            int startIdx = lower_bound(scoreB.begin(), scoreB.end(), nowA) - scoreB.begin();
            int endIdx = upper_bound(scoreB.begin(), scoreB.end(), nowA) - scoreB.begin();
            selection.win += startIdx;
            selection.draw += endIdx - startIdx;
            selection.lose += scoreB.size() - endIdx;
        }
        
        
    }
   
   

    Selection ans = selections[0];
    for (Selection selection : selections) {
        if (selection.win > ans.win)
            ans = selection;
        else if (selection.win == ans.win) {
            if (selection.draw > ans.win)
                ans = selection;
        }

  
    }

    for (auto &a : ans.A) {
        a += 1;
    }
    
    
    return ans.A;
}