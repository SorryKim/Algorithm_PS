#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if(s == "SONGDO") cout << "HIGHSCHOOL\n";
    if(s == "CODE") cout << "MASTER\n";
    if(s == "2023") cout << "0611\n";
    if(s == "ALGORITHM") cout << "CONTEST\n";

    return 0;
}