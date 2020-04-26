#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include <cstdlib>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int ans = 0;
    int siz;
    string s;
    cin >> s;
    siz = s.size();
    vector<vector<int>> dp(siz, vector<int>(siz, inf));
    //1文字目を初期化
    //dpでi~j桁目の2019で割った余りを求めていく
    REP(i, siz){
        dp[i][i] = (int)(s[i] - '0');//i桁目を代入
        FOR(j, i+1, siz){
            dp[i][j] = (dp[i][j-1]*10 + (int)(s[j] - '0'))%2019;
            if(dp[i][j] == 0) ans ++;
        }
    }

    cout << ans << endl;
    return 0;
}