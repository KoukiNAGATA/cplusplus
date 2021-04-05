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
    ll n, k, r, s, p, tmp;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    ll ans = 0;
    char command;
    vector<char> commands;
    REP(i, t.size())
    {
        // 一旦貪欲に勝つ手を出す
        if (t[i] == 'r')
        {
            command = 'p';
            tmp = p;
        }
        else if (t[i] == 's')
        {
            command = 'r';
            tmp = r;
        }
        else if (t[i] == 'p')
        {
            command = 's';
            tmp = s;
        }

        // (k+1回目以降)k回前と同じでないかしらべる
        if ((i - k >= 0) && (commands[i - k] == command))
        {
            command = 'o';
            tmp = 0;
        }
        ans += tmp;
        commands.push_back(command);
    }
    cout << ans << "\n";
    return 0;
}