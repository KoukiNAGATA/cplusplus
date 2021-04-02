#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

pair<ll, ll> a[2005]; //pairの配列の宣言
ll d[2005][2005];     //dp

int main()
{
    ll n, ans = 0; //まとめて初期化
    cin >> n;

    FOR(i, 1, n)
    {                      //1オリジン
        cin >> a[i].first; //嬉しさ
        a[i].second = i;   //場所
    }

    //1からn番目までを嬉しさについて降順に
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);

    FOR(i, 1, n)
    { //嬉しさ大きい方から動かす。左からjで、右からxで埋めていく。
        FOR(j, 0, i)
        {                                                            //jかxにpを動かして最大値を更新する。
            ll x = n + 1 - (i - j), v = a[i].first, p = a[i].second; //x:右の端までの距離。v:嬉しさ。p:場所。まとめて宣言。

            if (j == 0 && x < n + 1)
            {                                           //左の端にいる→x側に移動
                d[j][x] = d[j][x + 1] + abs(x - p) * v; //dp[j][x]:左からjケ、右からxケ埋まっている状態での嬉しさの最大値。
            }
            else if (j > 0 && x == n + 1)
            {                                           //右の端にいる→j側に移動
                d[j][x] = d[j - 1][x] + abs(j - p) * v; //dp[j][x]:左からjケ、右からxケ埋まっている状態での嬉しさの最大値。
            }
            else
            {
                d[j][x] = max(d[j][x + 1] + abs(x - p) * v, d[j - 1][x] + abs(j - p) * v); //dp[j][x]:左からjケ、右からxケ埋まっている状態での嬉しさの最大値。
            }
            ans = max(ans, d[j][x]);
        }
    }
    cout << ans << "\n";
}