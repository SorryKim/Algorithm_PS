#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    stack<char> st;
    int answer = 0;
    char before;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if (st.empty())
        {
            // 잘못된 괄호식
            if (now == ')' || now == ']')
            {
                cout << 0;
                return 0;
            }
            // 열려있는 괄호 push
            st.push(now);
        }
        else
        {
            if (now == '(' || now == '[')
                st.push(now);
            else
            {
                // 닫는 괄호인 경우
                if (now == ')')
                {

                    if (s[i - 1] == '(')
                    {
                        int val = 2;
                        stack<char> temp;
                        st.pop();

                        // (의 개수
                        int a = 0;
                        // [의 개수
                        int b = 0;
                        while (!st.empty())
                        {
                            if (st.top() == '(')
                                a++;
                            else
                                b++;
                            temp.push(st.top());
                            st.pop();
                        }

                        if (a != 0)
                            val *= pow(2, a);
                        if (b != 0)
                            val *= pow(3, b);

                        answer += val;
                        while (!temp.empty())
                        {
                            st.push(temp.top());
                            temp.pop();
                        }
                    }
                    else
                    {

                        stack<char> temp;
                        while (!st.empty())
                        {
                            if (st.top() == '(')
                            {
                                st.pop();
                                break;
                            }

                            temp.push(st.top());
                            st.pop();
                        }

                        while (!temp.empty())
                        {
                            st.push(temp.top());
                            temp.pop();
                        }
                    }
                }

                if (now == ']')
                {

                    if (s[i - 1] == '[')
                    {
                        int val = 3;
                        stack<char> temp;
                        st.pop();

                        // (의 개수
                        int a = 0;
                        // [의 개수
                        int b = 0;
                        while (!st.empty())
                        {
                            if (st.top() == '(')
                                a++;
                            else
                                b++;
                            temp.push(st.top());
                            st.pop();
                        }

                        if (a != 0)
                            val *= pow(2, a);
                        if (b != 0)
                            val *= pow(3, b);

                        answer += val;
                        while (!temp.empty())
                        {
                            st.push(temp.top());
                            temp.pop();
                        }
                    }
                    else
                    {

                        stack<char> temp;
                        while (!st.empty())
                        {
                            if (st.top() == '[')
                            {
                                st.pop();
                                break;
                            }

                            temp.push(st.top());
                            st.pop();
                        }

                        while (!temp.empty())
                        {
                            st.push(temp.top());
                            temp.pop();
                        }
                    }
                }
            }
        }
    }

    if (!st.empty())
        cout << 0;
    else
        cout << answer;

    return 0;
}
