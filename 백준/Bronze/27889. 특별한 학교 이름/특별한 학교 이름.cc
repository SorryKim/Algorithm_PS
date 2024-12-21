#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if(s == "NLCS") cout << "North London Collegiate School";
    if(s == "BHA") cout << "Branksome Hall Asia";
    if(s == "KIS") cout << "Korea International School";
    if(s == "SJA") cout << "St. Johnsbury Academy";

    return 0;
}