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
const int MAX = 100000;
const ll INF = 1LL << 60;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 足りない点数
    ll n, failed, ans, sum;
    cin >> n;
    // 余った点数
    vll a(n, 0), b(n, 0), passed;
    failed = 0, ans = 0, sum = 0;
    REP(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    REP(i, n)
    {
        cin >> b[i];
        sum -= b[i];
        if (a[i] < b[i]) // 不合格
            failed += b[i] - a[i];
        else // 合格
            passed.push_back(a[i] - b[i]);
    }
    // 不合格の個数=必ず変更する必要
    ans = n - passed.size();
    // aの総和<bの総和
    if (sum < 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    // 余りを降順ソート
    sort(passed.begin(), passed.end());
    while (passed.size() > 0)
    {
        if (failed <= 0)
            break;
        failed -= passed.back();
        // 末尾削除
        passed.pop_back();
        ans++;
    }

    if (failed > 0)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}