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

bool isLun(ll num)
{
    ll tmp = 0;
    if (num <= 10)
        return true; //1桁はルンルン数
    while (num > 10)
    {
        tmp = num / 10;
        if (abs((num % 10) - (tmp % 10)) > 1)
            return false;
        num = tmp;
    }

    return true;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k;
    ll tmp = 1;
    cin >> k;
    vll lun(k, 0);
    lun[0] = 1; //初期化
    FOR(i, 1, k)
    { //ルンルン数を先に格納しておく
        FOR(j, tmp, 100)
        {
            if (isLun(lun[i - 1] + tmp))
            {
                lun[i] = lun[i - 1] + tmp;
                break;
            }
            tmp *= 10;
        }
        tmp = 1;
    }
    cout << lun[k - 1] << "\n";
    return 0;
}