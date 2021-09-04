#include <iostream>
#include <stack>
using namespace std;
#define N 8
bool Matrix[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0}};
bool knows(int a, int b)
{
    return Matrix[a][b];
}
int findCeleb(int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B) && !knows(B, A))
        {
            s.push(B);
        }
        else if (!knows(A, B) && knows(B, A))
        {
            s.push(A);
        }
    }
    if (s.empty())
        return -1;

    int C = s.top();
    s.pop();
    for (int i = 0; i < n; i++)
    {
        if (i != C && !knows(i, C) && knows(C, i))
            return -1;
    }
    return C;
}
int main()
{
    int n = 4;
    int id = findCeleb(n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}