#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> memo;

long long solve(long long i) {

    if (i == 0) 
        return 1; 

    if (memo.find(i) != memo.end()) 
        return memo[i];

    memo[i] = solve(i / P) + solve(i / Q);
    
    return memo[i];
}

int main() {
    
    cin >> N >> P >> Q;
    cout << solve(N) << '\n';

    return 0;
}
