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
    ll n, tmp;
    ll s = 0;
    cin >> n;
    vll box(n + 10, 0);
    vll ball(n, 0);
    REP(i, n)
    {
        cin >> tmp;
        ball[i] = tmp;
        box[tmp]++;
    }

    //すべてのボールのペアの出し方の和を先に格納
    REP(i, n + 1)
    {
        if (box[i] > 1)
        {
            s += (box[i] * (box[i] - 1)) / 2;
        }
    }

    //kの分だけ差し替えて出力
    REP(i, n)
    {
        tmp = ball[i];
        if (box[tmp] > 2)
            cout << s - (box[tmp] * (box[tmp] - 1)) / 2 + ((box[tmp] - 1) * (box[tmp] - 2)) / 2 << "\n";
        else if (box[tmp] == 2)
            cout << s - (box[tmp] * (box[tmp] - 1)) / 2 << "\n";
        else
            cout << s << "\n";
    }

    return 0;
}