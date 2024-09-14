#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<string> v;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end());
        bool flag = true;
        for (int i = 0; i < v.size() - 1; i++){
            
            string s1 = v[i];
            string s2 = v[i + 1].substr(0, s1.size());

            if(s1 == s2){
                flag = false;
                break;
            }
        }

        string answer =  flag ? "YES" : "NO";
        cout << answer << "\n";
    }

    return 0;
}
