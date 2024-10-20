#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int picture[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            picture[i][j] = 0;
        }
    }
    int R,C,Q;
    cin >> R >> C >> Q;
    
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            int num;
            cin >> num;
            picture[i][j] = picture[i][j - 1] + num;
        }
    }

    

    while(Q--){
        int r1,r2,c1,c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int sum = 0;
        int div = (r2 - r1 + 1) * (c2 - c1 + 1);
    
        for(int i = r1; i <= r2; i++)
            sum += (picture[i][c2] - picture[i][c1 - 1]);
        
        cout << sum / div << '\n';
    }

    return 0;
}
