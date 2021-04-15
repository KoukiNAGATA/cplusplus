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

    int n, q, l, r;
    string s;

    cin >> n >> q >> s;
    //i番目までの文字列にいくつACが含まれるかを、整数の配列として保存する
    vector<int> data(n + 1, 0);
    FOR(i, 1, n - 1)
    {
        if (s[i - 1] == 'A' && s[i] == 'C')
        {
            data[i] += 1;
        }
        data[i] += data[i - 1];
    }
    //n番目は次にCがないのでn-1番目と同じ
    data[n] += data[n - 1];

    REP(i, q)
    {
        //先に部分列の数を数えた配列を作った後で入力し、参照。そうすることでループを回す回数が1度で済む。
        cin >> l >> r;
        l--;
        r--;
        cout << data[r] - data[l] << "\n";
    }
    return 0;
}
