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
    ll n;
    cin >> n;
    int ans = 0;
    // 半分全列挙
    FOR(post, 1, 1000000)
    {
        ll pre = post;
        string s = to_string(post);
        // 桁数だけずらす
        int digits = s.length();
        REP(i, digits)
        pre *= 10;

        ll x = pre + post;

        if (x <= n)
            ans++;
        else
            break;
    }
    cout << ans << "\n";
    return 0;
}