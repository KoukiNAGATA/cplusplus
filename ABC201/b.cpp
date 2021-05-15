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

//pairの第2引数でソート
typedef std::pair<string, int> ipair;
//昇順
bool lessPair(const ipair &l, const ipair &r) { return l.second < r.second; }
//降順
bool greaterPair(const ipair &l, const ipair &r) { return l.second > r.second; }

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n;
    vector<ipair> m;
    string s;
    REP(i, n)
    {
        cin >> s >> t;
        m.push_back(make_pair(s, t));
    }
    sort(m.begin(), m.end(), greaterPair);

    cout << m[1].first << "\n";
    return 0;
}