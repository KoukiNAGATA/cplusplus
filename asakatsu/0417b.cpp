#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans, n;
    ans = 0;
    vector<char> s;
    char tmp;
    while (cin >> tmp)
        s.push_back(tmp);
    n = s.size();

    //まず1文字消す
    s.pop_back();
    REP(i, n)
    {
        ll siz = s.size();
        if (siz % 2 == 0)
        { //長さが偶数
            bool flag = true;
            REP(j, siz / 2)
            {
                if (s[j] != s[j + siz / 2])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                ans = siz;
                break;
            }
        }
        s.pop_back();
    }

    cout << ans << "\n";
    return 0;
}