// CCW / baekjoon_11758.cpp
// https://www.acmicpc.net/problem/11758

#include<iostream>
#include<algorithm>
using namespace std;

struct Point {

    int x = 0, y = 0;

    Point(){}

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

};

// 벡터의 외적을 이용한 ccw
int ccw(Point a, Point b, Point c) {
    int num = a.x * b.y + b.x * c.y + c.x * a.y;
    num -= a.y * b.x + b.y * c.x + c.y * a.x;
   
    if (num > 0)
        return 1;
    else if (num < 0)
        return -1;
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Point a, b, c;
  
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    int result = ccw(a, b, c);

    cout << result << "\n";
   
}
