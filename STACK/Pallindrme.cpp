#include <bits/stdc++.h>
using namespace std;
int check(string s)
{
    stack<char> st;
    int i = 0;
    while (s[i] != 'X')
    {
        st.push(s[i]);
        i++;
    }
    i++;
    while (!st.empty())
    {
        if (st.top() == s[i])
        {
            i++;
            st.pop();
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s;
    cout << "ENTER STRING TO CHECK PALLINDROME";
    cin >> s;
    int test = check(s);
    if (test)
        cout << "is pallindrome";
    else
        cout << "is not";
    return 0;
}