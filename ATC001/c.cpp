// FFT。atcoderライブラリ使用。
#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1LL << 60;
const int MAX = 100000;
const int MOD = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vll a(n), b(n);
    REP(i, n)
    cin >> a[i] >> b[i];

    vll c = atcoder::convolution_ll(a, b);

    cout << 0 << "\n";
    REP(i, 2 * n - 1)
    cout << c[i] << "\n";

    return 0;
}