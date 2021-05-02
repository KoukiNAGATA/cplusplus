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
const int MAX = 100000;
const int MOD = 1000000007;

// Max*1.01倍ケ
int n, x[3030][5];

// A, B, C, D, E各要素がlimを超えていればフラグ立てる
int getMask(int i, int lim)
{
    int res = 0;
    REP(j, 5)
    if (lim <= x[i][j])
        res += 1 << j;
    return res;
}

// lim以上のscoreとなる組み合わせがあるか
bool check(int lim)
{
    // 初期化
    vector<int> cnt(1 << 5, 0);

    REP(i, n)
    cnt[getMask(i, lim)]++;

    REP(msk1, 1 << 5)
    REP(msk2, 1 << 5)
    REP(msk3, 1 << 5)
    {
        // Max→orとる。A, B, C, D, Eすべてフラグが立つ組み合わせのとき、そのmskを満たす3名が存在するかどうか
        if ((msk1 | msk2 | msk3) == (1 << 5) - 1 && 0 < cnt[msk1] && 0 < cnt[msk2] && 0 < cnt[msk3])
            return true;
    }

    return false;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    // 入力
    REP(i, n)
    REP(j, 5)
    cin >> x[i][j];

    // 二分探索(lまでok)
    int l = 0, r = 1e9 + 10;
    while (l + 1 < r)
    {
        int md = (l + r) / 2;
        if (check(md))
            l = md;
        else
            r = md;
    }
    cout << l << "\n";
    return 0;
}