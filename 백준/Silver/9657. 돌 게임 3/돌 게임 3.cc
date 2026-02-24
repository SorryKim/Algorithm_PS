#include <iostream>
using namespace std;

int main()
{
    int rock;
    cin>>rock;
    if(rock%7==0||rock%7==2) cout<<"CY";
    else cout<<"SK";
    
    return 0;
}