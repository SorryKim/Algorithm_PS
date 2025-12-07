#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, double> score = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F", 0.0}
    };

    string subject, grade;
    double credit;

    double total_score = 0.0;  // 학점 × 점수 합
    double total_credit = 0.0; // 학점 총합

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;

        if (grade == "P") continue; // P는 완전히 제외

        total_score += credit * score[grade];
        total_credit += credit;
    }

    double GPA = total_score / total_credit;

    cout << fixed << setprecision(6) << GPA << "\n";

    return 0;
}
