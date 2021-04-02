#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define INF 1LL << 60
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

double a, b, c;
double f(double t)
{
    return a * t + b * sin(c * t * M_PI);
}

int main()
{
    cin >> a >> b >> c;

    // tの定義域
    double l = 0.0, r = 1000.0;

    REP(i, 1000)
    { // 二分探索
        double mid = (l + r) / 2.0;
        if (f(mid) < 100.0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    // 小数点以下の長さを指定
    cout << fixed << setprecision(10) << l << "\n";
}
