#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1LL << 60
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

int n;
vector<ll> a;

ll orxor(int bit)
{
    ll res = 0;
    // 分割用配列とフラグ
    vector<int> tmp;
    int flag = 0;
    tmp.push_back(0);
    // OR
    REP(i, n)
    {
        if (bit & 1 << i && tmp[flag] != 0)
        { //  そのbitが1ならば、かつ空の区間でないならば
            flag++;
            tmp.push_back(0);
        }
        tmp[flag] = tmp[flag] | a[i];
    }
    // XOR
    for (auto i : tmp)
    {
        res ^= i;
    }
    return res;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    ll ans = inf;
    REP(i, n)
    {
        cin >> a[i];
    }
    // 逆から区切っていく
    reverse(a.begin(), a.end());

    // 区間を全探索
    REP(bit, 1 << n)
    {
        ans = min(ans, orxor(bit));
    }
    cout << ans << "\n";
    return 0;
}