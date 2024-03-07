#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    
    int n = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    double f = n * 0.15;
    int num = round(f);
    sort(v.begin(), v.end());
    double sum = 0;
    for (int i = num; i < n - num; i++) {
        sum += v[i];
    }
    
    double ans = sum / (n - num - num);

    if (v.size() == 0)
        cout << 0;
    else
        cout << round(ans);
    return 0;
}