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
    int n;
    cin >> n;
    vector<vector<int>> ball(n + 1);
    // 色名の管理
    set<int> ctyp;
    int x, c;
    REP(i, n)
    {
        cin >> x >> c;
        ball[c].push_back(x);
        ctyp.insert(c);
    }
    // 色iまで回収し終えたあとに左・右端にいるスコアの最小値
    // 左端にいる場合のスコア、右端にいる場合のスコア
    ll lscore = 0, rscore = 0;
    // 0色回収後の色
    int lnew = 0, rnew = 0;
    for (auto c : ctyp)
    {
        sort(ball[c].begin(), ball[c].end());
        // 次の色の左端、右端の座標
        int l = ball[c][0], r = ball[c][ball[c].size() - 1];
        // lnew or rnewからrに移動して、rからlへ回収
        ll lmi = min(lscore + abs(r - lnew), rscore + abs(r - rnew)) + abs(r - l);
        // lnew or rnewからlに移動して、lからrへ回収
        ll rmi = min(lscore + abs(l - lnew), rscore + abs(l - rnew)) + abs(r - l);
        // 更新後のスコア
        lscore = lmi;
        rscore = rmi;
        // 操作後の座標
        lnew = l;
        rnew = r;
    }
    // 原点へ戻る
    cout << min(lscore + abs(lnew), rscore + abs(rnew)) << "\n";

    return 0;
}