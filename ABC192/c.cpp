// int to stringの練習
#include <bits/stdc++.h>
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
using Graph = vector<vector<int>>;

string f(string ans){
    sort(ans.begin(), ans.end(), greater<int>());
    int ma = atoi(ans.c_str());
    sort(ans.begin(), ans.end());
    int mi = atoi(ans.c_str());
    return to_string(ma - mi);
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string ans = to_string(n);
    REP(i, k){
        ans = f(ans);
    }
    cout << ans <<"\n";
	return 0;
}