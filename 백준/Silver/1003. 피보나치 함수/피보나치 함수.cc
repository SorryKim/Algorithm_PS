#include <iostream>
using namespace std;

int main() {
    pair<int, int> result[41] = { { 1,0 },{0,1} };
    for (int i = 2; i < 41; i++) {
        int first = result[i - 2].first + result[i - 1].first;
        int second = result[i - 2].second + result[i - 1].second;
        result[i] = { first,second };
    }

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int num;
        scanf("%d", &num);
        printf("%d %d\n", result[num].first, result[num].second);
    }
}