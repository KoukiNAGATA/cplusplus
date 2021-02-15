#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

int main() {
    int n, max;
    int a[100001];
    int b[100001];
    int c[100001];
    int dp[100001][3];// [日数][前日の行動] 変数宣言の時点でのサイズは、1始まり。

	cin >> n;

    REP(i, n){
        cin >> a[i] >> b[i] >> c[i];
        dp[i][0] = dp[i][1] = dp[i][2] = 0;// 一旦0で埋めておく
    }
    // 初期値(1日目)を設定
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    dp[1][2] = c[0];

    if(n == 1){
        // n日目の3数を比べる
        max = std::max(dp[n][0], dp[n][1]);
        max = std::max(max, dp[n][2]);

        cout << max << endl;
        return 0;
    }

    FOR(i, 2, n){// 前日にした行いによってその日の状態が変わる。n日目まである。
        dp[i][0] = std::max(dp[i-1][1] + a[i-1], dp[i-1][2] + a[i-1]);
        dp[i][1] = std::max(dp[i-1][0] + b[i-1], dp[i-1][2] + b[i-1]);
        dp[i][2] = std::max(dp[i-1][0] + c[i-1], dp[i-1][1] + c[i-1]);
    }

    // n日目の3数を比べる
    max = std::max(dp[n][0], dp[n][1]);
    max = std::max(max, dp[n][2]);

	cout << max << endl;
	return 0;
}