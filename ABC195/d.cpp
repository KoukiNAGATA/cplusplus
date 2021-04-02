// pairの配列を使った実装
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<int>;
using vvll = vector<vector<int>>;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

//pairの第2引数でソート
typedef std::pair<int, int> ipair;
//昇順
bool lessPair(const ipair &l, const ipair &r) { return l.second < r.second; }
//降順
bool greaterPair(const ipair &l, const ipair &r) { return l.second > r.second; }

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, q;
    int ans = 0;
    int tmp1, tmp2;
    cin >> n >> m >> q;
    vector<ipair> item;
    vector<int> x;
    // 大きさと価値のペアの入力
    REP(i, n)
    {
        cin >> tmp1 >> tmp2;
        item.push_back(ipair(tmp1, tmp2));
    }
    // 価値の降順ソート
    sort(item.begin(), item.end(), greaterPair);
    // 箱の入力
    REP(i, m)
    {
        cin >> tmp1;
        x.push_back(tmp1);
    }
    REP(i, q)
    {
        // 初期化
        ans = 0;
        vector<int> flag(n, 0); // 入れた荷物フラグ
        vector<int> tmp_x = x;
        cin >> tmp1 >> tmp2;
        FOR(j, tmp1 - 1, tmp2 - 1)
        tmp_x[j] = 0;                     // 使えない箱は抜くのではなく0にするとO(1)
        sort(tmp_x.begin(), tmp_x.end()); // 小さい順
        for (int j : tmp_x)
        { // mケの箱を小さい順に
            REP(k, n)
            { // nケの荷物を価値の高い順に
                if (j >= item[k].first && flag[k] == 0)
                { //箱の大きさが荷物の大きさ以上かつ、まだ入れられていない荷物
                    ans += item[k].second;
                    flag[k] = 1; // もう荷物を入れた
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}