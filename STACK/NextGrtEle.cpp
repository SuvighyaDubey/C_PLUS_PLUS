#include <iostream>
#include <stack>
using namespace std;
void NextGreEle(int num[], int n)
{
    stack<int> s;
    int res[n];
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && (num[s.top()] < num[i]))
        {
            res[s.top()] = num[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        res[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " --> " << res[i] << endl;
    }
}
int main()
{
    int arr[] = {11, 13, 2, 21, 19, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    NextGreEle(arr, n);
    return 0;
}
