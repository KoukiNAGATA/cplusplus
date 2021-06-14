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
    ll n, C;
    cin >> n >> C;
    vector<P> event;
    //ai日目からbi日目まで使うci円のサービスを、ai−1日目とai日目の間にci円上がり、bi日目とbi+1日目の間にci円下がるに置き換え
    REP(i, n)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        event.emplace_back(a, c);
        event.emplace_back(b + 1, -c);
    }
    sort(event.begin(), event.end());
    // 1日あたりの費用、現在見ている日にち
    ll ans = 0, fee = 0, t = 0;
    for (auto p : event)
    {
        if (p.first != t)
        { // 違う日ならこれまでの日の料金を掛け合わせる。Cの方が小さければ使う。
            ans += min(C, fee) * (p.first - t);
            t = p.first;
        }
        fee += p.second;
    }
    cout << ans << endl;
    return 0;
}