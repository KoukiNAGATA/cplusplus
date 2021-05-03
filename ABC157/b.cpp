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
    int n, tmp;
    vector<vector<bool>> flg(3, vector<bool>(3));
    vector<vector<int>> num(3, vector<int>(3));

    // 入力
    REP(i, 3)
    REP(j, 3)
    cin >> num[i][j];

    cin >> n;
    REP(i, n)
    {
        cin >> tmp;
        // 全探索。数字が一致すればフラグを立てる
        REP(i, 3)
        REP(j, 3)
        if (num[i][j] == tmp)
            flg[i][j] = true;
    }

    //ビンゴは8通り
    if (flg[0][0] && flg[0][1] && flg[0][2])
        cout << "Yes"
             << "\n";
    else if (flg[1][0] && flg[1][1] && flg[1][2])
        cout << "Yes"
             << "\n";
    else if (flg[2][0] && flg[2][1] && flg[2][2])
        cout << "Yes"
             << "\n";
    else if (flg[0][0] && flg[1][0] && flg[2][0])
        cout << "Yes"
             << "\n";
    else if (flg[0][1] && flg[1][1] && flg[2][1])
        cout << "Yes"
             << "\n";
    else if (flg[0][2] && flg[1][2] && flg[2][2])
        cout << "Yes"
             << "\n";
    else if (flg[0][0] && flg[1][1] && flg[2][2])
        cout << "Yes"
             << "\n";
    else if (flg[0][2] && flg[1][1] && flg[2][0])
        cout << "Yes"
             << "\n";
    else
        cout << "No"
             << "\n";
    return 0;
}