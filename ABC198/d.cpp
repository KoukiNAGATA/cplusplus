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
    // 入力
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    // アルファベットそれぞれの文字数を数える
    vector<int> alphabet(26, 0);
    REP(i, s1.size())
    alphabet[s1[i] - 'a']++;
    REP(i, s2.size())
    alphabet[s2[i] - 'a']++;
    REP(i, s3.size())
    alphabet[s3[i] - 'a']++;

    // 存在したアルファベットについて、0から番号を振っていく
    int n = 0;
    REP(i, 26)
    {
        if (alphabet[i] > 0)
        {
            alphabet[i] = n;
            n++;
        }
    }

    // 11文字以上は解なし
    if (n > 10)
    {
        cout << "UNSOLVABLE"
             << "\n";
        return 0;
    }
    // 0から9までを全探索→10!通り
    vector<int> v(10);
    REP(i, 10)
    v[i] = i;
    do
    {
        // 先頭の文字が0のときはスキップ
        if (v[alphabet[s1[0] - 'a']] == 0)
            continue;
        if (v[alphabet[s2[0] - 'a']] == 0)
            continue;
        if (v[alphabet[s3[0] - 'a']] == 0)
            continue;
        // 文字列を今回の順列に変換
        ll n1 = 0;
        ll n2 = 0;
        ll n3 = 0;
        REP(i, s1.size())
        {
            n1 *= 10;
            n1 += v[alphabet[s1[i] - 'a']];
        }
        REP(i, s2.size())
        {
            n2 *= 10;
            n2 += v[alphabet[s2[i] - 'a']];
        }
        REP(i, s3.size())
        {
            n3 *= 10;
            n3 += v[alphabet[s3[i] - 'a']];
        }
        // 解が見つかる
        if (n1 + n2 == n3)
        {
            cout << n1 << "\n";
            cout << n2 << "\n";
            cout << n3 << "\n";
            return 0;
        }
    } while (next_permutation(v.begin(), v.end())); // 順列を辞書順に全探索

    // 解なし
    cout << "UNSOLVABLE"
         << "\n";
    return 0;
}