#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, x, y;
    // 自分ふくむ
    int ans = 1;
    cin >> h >> w >> x >> y;
    x--;
    y--;
    vector<string> v(h); // 行ごとの配列
    REP(i, h)
    cin >> v[i];
    // 上
    int i = x;
    while (i > 0)
    {
        if (v[i - 1][y] == '.')
        {
            ans++;
            i--;
        }
        else
            break;
    }
    // 下
    i = x;
    while (i < h - 1)
    {
        if (v[i + 1][y] == '.')
        {
            ans++;
            i++;
        }
        else
            break;
    }
    // 左
    i = y;
    while (i > 0)
    {
        if (v[x][i - 1] == '.')
        {
            ans++;
            i--;
        }
        else
            break;
    }
    // 右
    i = y;
    while (i < w - 1)
    {
        if (v[x][i + 1] == '.')
        {
            ans++;
            i++;
        }
        else
            break;
    }
    cout << ans << "\n";
}