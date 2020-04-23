#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
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

int main()
{
    string s, t, ans;
    cin >> s >> t;
    ll n = s.length();
    ll m = t.length();
    vvll LCS(n+1, vll(m+1));
    //まず最長共通部分長を求める
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(s[i-1] == t[j-1]){//sとtは0オリジン
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }else{
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    //最長共通部分を求める。後ろから埋めていく。
    while(n > 0 and m > 0) {
        if(s[n - 1] == t[m - 1]) {//0オリジンなので0〜n-1にしか文字が入ってない
            ans = s[n - 1] + ans;
    	    n = n - 1, m = m - 1;
        } else if(LCS[n - 1][m] > LCS[n][m - 1]) {//長い方を減らしていけばいずれ共通の文字に辿り着く
      	    n = n - 1;
        } else {
    	    m = m - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
