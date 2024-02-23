#include <string>
#include <vector>

using namespace std;

int arr[100001];

int solution(int n) {
    int mod = 1234567;
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i <= 100000; i++){
        
        arr[i] = ((arr[i-2] % mod) + (arr[i-1] % mod))%mod;
    }
    
    return arr[n];
}