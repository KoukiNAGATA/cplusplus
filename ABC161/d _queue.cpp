#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
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

/*キューの使い方はこれを見る*/
int main()
{
    ll k;
    cin >> k;
    queue<ll> que;
    FOR(i, 1, 9)
    que.push(i); //1〜9を先に格納
    REP(i, k - 1)
    {                       //k-1番目までを捨てる操作
        ll s = que.front(); //先頭にアクセス
        que.pop();          //先頭を削除
        for (int j = -1; j <= 1; ++j)
        {
            ll add = (s % 10) + j;
            if (add >= 0 && add <= 9)
                que.push(s * 10 + add); //後ろに追加
        }
    }
    cout << que.front() << "\n"; //先頭がk番目
}