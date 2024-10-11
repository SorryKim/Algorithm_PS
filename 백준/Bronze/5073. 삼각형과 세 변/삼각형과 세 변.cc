#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    
    
    while(true){
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0)
            break;

        if(a == b && b == c){
            cout << "Equilateral\n";
            continue;
        }
        
        string answer = "";
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());

        if(v[2] >= v[0] + v[1])
            answer = "Invalid";
        else{

            if(v[1] == v[0] || v[1] == v[2])
                answer = "Isosceles";
            else
                answer = "Scalene";
        }
           
        
        cout << answer << '\n';
    }


    return 0;

}
