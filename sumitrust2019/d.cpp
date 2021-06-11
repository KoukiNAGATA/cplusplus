#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const ll INF = 1LL << 60;
const int MAX = 200000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    int cnt = 0;
    cin >> n >> s;
    // "000"〜"999"について作れるか各桁を調べる
    REP(i, 1000)
    {
        // [百の位, 十の位, 一の位]の配列
        int c[3] = {i / 100, (i / 10) % 10, i % 10};
        int f = 0;
        REP(j, n)
        {
            // nを上の桁からc[f]に一致するか見て、一致すればfを進める
            if (s[j] - '0' == c[f])
                ++f;
            // 3桁ともあった
            if (f == 3)
                break;
        }
        if (f == 3)
            ++cnt;
    }
    cout << cnt << "\n";
}