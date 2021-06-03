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
const int INF = 1 << 30;
const int MAX = 100000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    //店数
    int n;
    cin >> n;
    // ((名前, スコア), 距離)のデータ
    vector<pair<pair<string, int>, int>> stores;
    REP(i, n)
    {
        string s;
        int p;
        cin >> s >> p;
        // 昇順ソートで合うようにスコアをマイナスで入れる
        stores.push_back(make_pair(make_pair(s, -p), i + 1));
    }
    sort(stores.begin(), stores.end());
    REP(i, n)
    cout << stores[i].second << "\n";
    return 0;
}