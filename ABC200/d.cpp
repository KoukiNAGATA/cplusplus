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

void output(vector<int> &a)
{
    // x, yを出力
    cout << a.size();
    // 配列の中身を出力
    for (auto &nx : a)
    {
        cout << ' ' << nx;
    }
    cout << '\n';
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n)
    cin >> a[i];
    vector<vector<int>> bk(200, vector<int>(0));

    // 先頭からmin(n, 8)要素について鳩の巣原理よりbit全探索
    int cnt = min(n, 8);
    // i = 0(何も選ばない)は含めない
    for (int i = 1; i < (1 << cnt); i++)
    {
        // 和を200で割った余りsig
        int sig = 0;
        vector<int> s;
        for (int j = 0; j < cnt; j++)
        {
            if (i & (1 << j))
            {
                s.push_back(j + 1);
                sig += a[j];
                sig %= 200;
            }
        }
        // sigが一致する組み合わせが既に存在
        if (bk[sig].size() != 0)
        {
            cout << "Yes\n";
            output(bk[sig]);
            output(s);
            return 0;
        }
        else
            bk[sig] = s;
    }
    cout << "No\n";
    return 0;
}
