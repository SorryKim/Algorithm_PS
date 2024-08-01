#include <string>
#include <set>
using namespace std;


int solution(string dirs) {
    int answer = 0;
    int x = 0, y = 0;
    set<pair<pair<int,int>, pair<int,int>>> mySet;
    
    for(auto now : dirs){
        
        int nextX = x;
        int nextY = y;
        if(now == 'L'){
            if(x - 1 < -5)
                continue;
            nextX--;
        }
        if(now == 'R'){
            if(x + 1 > 5)
                continue;
            nextX++;
        }
        if(now == 'U'){
            if(y + 1 > 5)
                continue;
            nextY++;
        }
        if(now == 'D'){
            if(y - 1 < -5)
                continue;
            nextY--;
        }
        
        mySet.insert({{x,y},{nextX,nextY}});
        mySet.insert({{nextX,nextY}, {x,y}});
        x = nextX;
        y = nextY;
    }
    
    answer = mySet.size() / 2;
    
    
    return answer;
}