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
    double a, b, x;
    cin >> a >> b >> x;
    // 平面幾何に落とし込む。
    x /= a;
    // 小数点
    cout << fixed << setprecision(10);
    if (x > a * b / 2)
        cout << atan2((a * b - x) * 2, a * a) * 180 / M_PI << "\n";
    else
        cout << atan2(b * b, x * 2) * 180 / M_PI << "\n";
}