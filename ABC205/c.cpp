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

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c;
    cin >> a >> b >> c;

    if (c % 2)
    {
        if (a < 0 && b < 0)
        {
            if (a < b)
                cout << '<' << "\n";
            else if (a == b)
                cout << '=' << "\n";
            else
                cout << '>' << "\n";
        }
        else if (a < 0)
        {
            cout << '<' << "\n";
        }
        else if (b < 0)
        {
            cout << '>' << "\n";
        }
        else
        {
            if (a < b)
                cout << '<' << "\n";
            else if (a == b)
                cout << '=' << "\n";
            else
                cout << '>' << "\n";
        }
    }
    else
    { // 偶数乗はそのまま
        if (abs(a) < abs(b))
            cout << '<' << "\n";
        else if (abs(a) == abs(b))
            cout << '=' << "\n";
        else
            cout << '>' << "\n";
    }
    return 0;
}