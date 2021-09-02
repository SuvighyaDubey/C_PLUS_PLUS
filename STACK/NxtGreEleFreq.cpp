#include <iostream>
#include <stack>
using namespace std;
void NGF(int arr[], int n, int freq[])
{
    stack<int> s;
    int res[n];
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && (freq[s.top()] < freq[i]))
        {
            res[s.top()] = arr[i];
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
        cout << res[i] ;
    }
}
int main()
{
    int n;
    cout << "Enter lenght of inout array = ";
    cin >> n;
    int *arr = new int[n];
    int *temp = new int[100]{0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp[arr[i]]++;
    }
    int freq[n];
    for(int i=0;i<n;i++){
        freq[i]=temp[arr[i]];
    }
    NGF(arr, n, freq);
    return 0;
}