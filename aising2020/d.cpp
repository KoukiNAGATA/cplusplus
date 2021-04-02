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

ll n;

ll numBit(ll bit, ll n)
{ //1の個数を返す
    ll num = 0;
    REP(i, n)
    if (bit & 1 << i) num++;
    return num;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans, tmp, num_flip, base;
    bool isone;
    tmp = 0;
    string s, s_new;
    cin >> n >> s;
    s_new = s;
    vll templa(n, 0); //nまでの1の本数
    REP(i, n)
    { //xの1の本数
        if (s[i] == '1')
            tmp++;
    }
    FOR(i, 1, n)
    templa[i] = numBit(i, n);

    REP(i, n)
    {
        ans = 1;
        base = 1;
        num_flip = 0;
        s_new = s;
        s_new = s;
        if (s_new[i] == '0')
        {
            s_new[i] = '1';
            isone = true;
        }
        else
        {
            s_new[i] = '0';
            isone = false;
        }
        while (s_new.size() > 0)
        { //10進数変換
            if (s_new[s_new.size() - 1] == '1')
                num_flip = num_flip + base;
            s_new.pop_back();
            base = base * 2;
        }
        if (isone)
        { //変換後、1が1個多い
            num_flip = num_flip % (tmp + 1);
        }
        else
        {
            num_flip = num_flip % (tmp - 1);
        }
        while (num_flip > 0)
        {
            num_flip = num_flip % templa[num_flip];
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}