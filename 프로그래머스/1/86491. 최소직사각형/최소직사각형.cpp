#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    for (auto card : sizes) {
        max_width = max(max_width, max(card[0], card[1]));
        max_height = max(max_height, min(card[0], card[1]));
    }


    return max_width * max_height;
}