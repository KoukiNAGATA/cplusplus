#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using p = pair<int, int>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    //まとめて宣言すると初期化されるのは右端のみ→別々で宣言！
    ll ans = 0;
    ll cnt_r = 0;
    ll cnt_g = 0;
    ll cnt_b = 0;
    vector<char> s(n);
    char tmp;

    REP(i, n)
    {
        cin >> tmp;
        s[i] = tmp;
        if (tmp == 'R')
        {
            cnt_r++;
        }
        else if (tmp == 'G')
        {
            cnt_g++;
        }
        else
        {
            cnt_b++;
        }
    }

    ans += cnt_r * cnt_g * cnt_b;

    REP(i, n - 2)
    {
        FORR(j, n - 1, i + 2)
        {
            if ((j + i) % 2 == 0)
            {
                if (s[i] != s[(j + i) / 2] && s[(j + i) / 2] != s[j] && s[j] != s[i])
                { //rgb等間隔でRGBそろったものを引く
                    ans--;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}