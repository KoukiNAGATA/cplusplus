// 先頭と末尾の操作がO(1)の両端キュー(deque)
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
    string s;
    // 両端キュー
    deque<char> t;
    cin >> s;
    bool isFlip = false;
    int n = s.length();
    int sr = 0, sl = 0;
    char tmp;
    REP(i, n)
    {
        tmp = s[i];
        if (tmp == 'R')
        {
            isFlip = !isFlip;
            continue;
        }
        else
        {
            if (isFlip)
                t.push_front(tmp);
            else
                t.push_back(tmp);
        }
    }
    if (isFlip)
        reverse(t.begin(), t.end());
    string ans;
    // 2文字消すを1文字消すor1文字足すに読み替える
    for (char &c : t)
    {
        if (ans.size() && ans.back() == c)
            ans.pop_back();
        else
            ans.push_back(c);
    }
    cout << ans << "\n";
    return 0;
}