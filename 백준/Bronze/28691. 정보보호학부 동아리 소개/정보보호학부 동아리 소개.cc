#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if(s == "M") cout << "MatKor\n";
    if(s == "W") cout << "WiCys\n";
    if(s == "C") cout << "CyKor\n";
    if(s == "A") cout << "AlKor\n";
    if(s == "$") cout << "$clear\n";

    return 0;
}