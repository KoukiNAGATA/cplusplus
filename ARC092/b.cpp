// std::mapを使う問題
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
    int n, m;
    string tmp;
    int ans = 0;
    map<string, int> card;
    cin >> n;
    // 青いカード
    REP(i, n)
    {
        cin >> tmp;
        card[tmp]++;
    }
    cin >> m;
    // 赤いカード
    REP(i, m)
    {
        cin >> tmp;
        card[tmp]--;
    }

    for (const auto &x : card)
    {
        ans = max(x.second, ans);
    }

    cout << ans << "\n";
    return 0;
}