#include <bits/stdc++.h>
using namespace std;
void fillNextGrElArr(int *a, int n, int *next)
{
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            next[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        next[s.top()] = -1;
        s.pop();
    }
}
int main()
{
    int a[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int next[n];
    fillNextGrElArr(a, n, next);
    for (int i = 0; i < n; i++)
        cout << a[next[i]] << " ";
    return 0;
}