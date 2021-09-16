#include <bits/stdc++.h>
using namespace std;
stack<char> st;
void printst()
{
    if (st.empty())
        return;
    char temp = st.top();
    st.pop();
    printst();
    cout << temp;
}
void resolve(string s)
{
    st.push(s[0]);
    int i = 1;
    while (i < s.length())
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty() && (st.top() == s[i]))
            {
                st.pop();
                i++;
            }
            st.push(s[i]);
            i++;
        }
    }
    printst();
}
int main()
{
    string s;
    cout << "enter string ";
    cin >> s;
    resolve(s);
    return 0;
}