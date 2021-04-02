#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    if (n >= m)
    {
        for (int i = 0; i < n; i++)
        {
            ans = ans * 10 + m;
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            ans = ans * 10 + n;
        }
    }
    cout << ans << "\n";
    return 0;
}
