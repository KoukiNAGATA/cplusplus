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
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (auto &i : a)
        cin >> i;
    int half = 1 << (n - 1);
    // 最大の要素のイテレータを返すmax_element
    auto winner = max_element(a.begin(), a.end()) - a.begin();
    // winnerが半分未満なら半分以上のブロック、そうでないなら半分未満のブロックを見る
    auto start = winner < half ? a.begin() + half : a.begin();
    // 1オリジン
    cout << (int)(max_element(start, start + half) - a.begin() + 1) << "\n";
    return 0;
}
