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
    ll n, q, t, a, b;
    string s;
    cin >> n >> s >> q;
    bool flg = false;
    REP(i, q)
    {
        cin >> t >> a >> b;
        --a;
        --b;
        if (t == 2)
            flg = !flg;
        else
        {
            if (flg)
            {
                if (a < n)
                    a += n;
                else
                    a -= n;
                if (b < n)
                    b += n;
                else
                    b -= n;
            }
            swap(s[a], s[b]);
        }
    }
    if (flg)
    {
        REP(i, n)
        {
            swap(s[i], s[i + n]);
        }
    }
    cout << s << "\n";
    return 0;
}