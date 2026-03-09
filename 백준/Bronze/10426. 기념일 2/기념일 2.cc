#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string date;
    int N;
    cin >> date >> N;

    int y = stoi(date.substr(0,4));
    int m = stoi(date.substr(5,2));
    int d = stoi(date.substr(8,2));

    vector<int> days = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    for(int i = 1; i < N; i++) {

        if(isLeap(y)) days[2] = 29;
        else days[2] = 28;

        d++;

        if(d > days[m]) {
            d = 1;
            m++;
        }

        if(m > 12) {
            m = 1;
            y++;
        }
    }

    printf("%04d-%02d-%02d\n", y, m, d);
}