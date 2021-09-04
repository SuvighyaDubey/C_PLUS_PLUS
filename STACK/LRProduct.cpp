#include <bits/stdc++.h>
using namespace std;
int *calc_left(int a[], int n)
{
    stack<int> s;
    s.push(n - 1);
    int *left = new int[n];
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            left[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        left[s.top()] = 0;
        s.pop();
    }
    return left;
}
int *calc_right(int a[], int n)
{
    stack<int> s;
    s.push(0);
    int *right = new int[n];
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            right[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        right[s.top()] = 0;
        s.pop();
    }
    return right;
}
int main()
{
    int n;
    cout << "Enter size of array = ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *left = calc_left(arr, n);
    int *right = calc_right(arr, n);
    cout << endl
         << "left array" << endl;
    for (int i = 0; i < n; i++)
        cout << left[i] << " ";
    cout << endl
         << "right array" << endl;
    for (int i = 0; i < n; i++)
        cout << right[i] << " ";
    int MAX = left[0] * right[0];
    for (int i = 1; i < n; i++)
    {
        int temp = left[i] * right[i];
        if (MAX < temp)
        {
            MAX = temp;
        }
    }
    cout << "LRProduct = " << MAX;
    return 0;
}