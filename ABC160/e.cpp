#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
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
    ll X, Y, a, b, c, ans, tmp;
    cin >> X >> Y >> a >> b >> c;
    ans = 0;
    vll p, q, r;
    //一旦元の色で配列に入れてソート
    REP(i, a)
    {
        cin >> tmp;
        p.push_back(tmp);
    }
    sort(p.begin(), p.end());
    REP(i, b)
    {
        cin >> tmp;
        q.push_back(tmp);
    }
    sort(q.begin(), q.end());
    REP(i, c)
    {
        cin >> tmp;
        r.push_back(tmp);
    }

    REP(i, X)
    { //xケだけ取り出す
        tmp = p.back();
        r.push_back(tmp);
        p.pop_back();
    }
    REP(i, Y)
    { //yケだけ取り出す
        tmp = q.back();
        r.push_back(tmp);
        q.pop_back();
    }
    sort(r.begin(), r.end());
    REP(i, X + Y)
    {
        ans += r.back();
        r.pop_back();
    }
    cout << ans << "\n";
    return 0;
}