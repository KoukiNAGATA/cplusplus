#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
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
    int n, k, m, tmp;
    int sum = 0;
    cin >> n >> k >> m;

    REP(i, n - 1)
    {
        cin >> tmp;
        sum += tmp;
    }

    if (sum >= n * m) //既に超えている
        cout << 0 << "\n";
    else if (sum + k >= n * m) //超えることができる
        cout << n * m - sum << "\n";
    else
        cout << -1 << "\n";

    return 0;
}