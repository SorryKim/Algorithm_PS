#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    int Q;
    cin >> Q;

    long long xmin = 1, xmax = N;
    long long ymin = 1, ymax = M;

    while(Q--){
        long long x, y;
        int d;
        cin >> x >> y >> d;

        if(d == 1){ // 동
            xmin = max(xmin, x + 1);
            ymin = max(ymin, y);
            ymax = min(ymax, y);
        }
        else if(d == 2){ // 서
            xmax = min(xmax, x - 1);
            ymin = max(ymin, y);
            ymax = min(ymax, y);
        }
        else if(d == 3){ // 남
            xmin = max(xmin, x);
            xmax = min(xmax, x);
            ymax = min(ymax, y - 1);
        }
        else if(d == 4){ // 북
            xmin = max(xmin, x);
            xmax = min(xmax, x);
            ymin = max(ymin, y + 1);
        }
        else if(d == 5){ // 북동
            xmin = max(xmin, x + 1);
            ymin = max(ymin, y + 1);
        }
        else if(d == 6){ // 북서
            xmax = min(xmax, x - 1);
            ymin = max(ymin, y + 1);
        }
        else if(d == 7){ // 남동
            xmin = max(xmin, x + 1);
            ymax = min(ymax, y - 1);
        }
        else if(d == 8){ // 남서
            xmax = min(xmax, x - 1);
            ymax = min(ymax, y - 1);
        }
        else if(d == 9){ // 일치
            xmin = xmax = x;
            ymin = ymax = y;
        }
    }

    long long ans = (xmax - xmin + 1) * (ymax - ymin + 1);
    cout << ans << "\n";

    return 0;
}
