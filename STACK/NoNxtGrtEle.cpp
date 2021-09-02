#include <bits/stdc++.h>
#include <stack>
using namespace std;
vector<int> no_NGN(int arr[], int n)
{
    vector<int> nxt;
    stack<int> s;
    nxt.push_back(0);
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= arr[s.top()])
            s.pop();
        if (s.empty())
            nxt.push_back(0);
        else
            nxt.push_back(nxt[n - s.top() - 1] + 1);
        s.push(i);
    }
    reverse(nxt.begin(), nxt.end());
    return nxt;
}
int main()
{
    int a[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> nxt = no_NGN(a, n);
    cout << nxt[3] << endl
         << nxt[6] << endl
         << nxt[1] << endl;
    // count(a, dp, n);
    // cout << ansQuery(dp, 0) << endl;
    // cout << ansQuery(dp, 6) << endl;
    return 0;
}
// void fillNext(int next[], int a[], int n)
// {
//     stack<int> s;
//     s.push(0);
//     for (int i = 1; i < n; i++)
//     {
//         while (!s.empty())
//         {
//             int cur = s.top();
//             if (a[cur] < a[i])
//             {
//                 next[cur] = i;
//                 s.pop();
//             }
//             else
//                 break;
//         }
//         s.push(i);
//     }
//     while (!s.empty())
//     {
//         int cur = s.top();
//         next[cur] = -1;
//         s.pop();
//     }
// }

// void count(int a[], int dp[], int n)
// {
//     int next[n];
//     memset(next, 0, sizeof(next));
//     fillNext(next, a, n);
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (next[i] == -1)
//         {
//             dp[i] = 0;
//         }
//         else
//         {
//             dp[i] = 1 + dp[next[i]];
//         }
//     }
// }
// int ansQuery(int dp[], int index)
// {
//     return dp[index];
// }
//
