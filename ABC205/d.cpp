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
const int MAX = 100000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力
    ll n, q;
    cin >> n >> q;
    vll a(n), k(q);
    REP(i, n)
    cin >> a[i];
    REP(i, q)
    cin >> k[i];

    // クエリ処理
    REP(i, q)
    {
        ll l = k[i];
        ll prev = 0;
        while (true)
        {
            // l以下のaの個数
            auto itr_a = upper_bound(a.begin(), a.end(), l) - a.begin();
            // l - l以下のaの個数 == k[i]になるまで続ける
            if (l - itr_a == k[i])
                break;
            else
            {
                l += (itr_a - prev);
                prev = itr_a;
            }
        }
        cout << l << "\n";
    }
    return 0;
}