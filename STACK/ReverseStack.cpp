#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void insertBot(int data)
{
    int temp;
    if (st.empty())
    {
        st.push(data);
        return;
    }
    temp = st.top();
    st.pop();
    insertBot(data);
    st.push(temp);
}
void reverse()
{
    int data;
    if (st.empty())
        return;
    data = st.top();
    st.pop();
    reverse();
    insertBot(data);
}

int main()
{
    int n, i = 0, temp;
    cout << "ENTER no. of Ele  ";
    cin >> n;
    while (i < n)
    {
        cin >> temp;
        st.push(temp);
        i++;
    }
    reverse();
    while (!st.empty())
    {
        cout << st.top() << "  ";
        st.pop();
    }
    return 0;
}