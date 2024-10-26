#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    long long N; 
    cin >> N;
    
    vector<long long> sizes(6);
    for (int i = 0; i < 6; ++i) 
        cin >> sizes[i];
    
    
    long long T, P;
    cin >> T >> P;
    
    // 티셔츠 묶음 수량 계산
    long long total_shirt_bundles = 0;
    for (int i = 0; i < 6; ++i)
        total_shirt_bundles += (sizes[i] + T - 1) / T;
    
    
    // 펜 묶음 수량 계산
    long long pen_bundles = N / P; // P 자루씩 최대 몇 묶음인지 계산
    long long pen_remaining = N % P; // 나머지 펜의 수

   
    cout << total_shirt_bundles << endl;
    cout << pen_bundles << " " << pen_remaining << endl;
    
    return 0;
}