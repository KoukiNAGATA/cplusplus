#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    std::sort(a.begin(), a.end()); //ソートして隣と同じかどうか見る

    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cout << "NO"
                 << "\n";
            return 0;
        }
    }
    cout << "YES"
         << "\n";
    return 0;
}