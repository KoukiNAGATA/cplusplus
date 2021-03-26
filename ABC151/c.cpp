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
    int n, m;
    int cnt_ac = 0;
    int cnt_wa = 0;
    cin >> n >> m;

    // 正解フラグ
    vector<bool> flag(n + 1, false);
    // 不正解数を貯めておく
    vector<int> tmp_wa(n + 1, 0);

    // クエリ処理
    REP(i, m)
    {
        int num;
        string res;
        cin >> num >> res;
        // 未正解の問題
        if (!flag[num])
        {
            if (res == "AC")
            {
                cnt_ac++;
                flag[num] = true;
                cnt_wa += tmp_wa[num];
            }
            else
                tmp_wa[num]++;
        }
    }

    cout << cnt_ac << " " << cnt_wa << endl;

    return 0;
}