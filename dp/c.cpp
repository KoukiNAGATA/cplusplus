#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;

int main() {
    int n, max;
    int a[100000];
    int b[100000];
    int c[100000];
    int dp[100000][3];//[日数][前日の行動] 変数宣言の時点でのサイズは、1始まり。

	cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        dp[i][0] = dp[i][1] = dp[i][2] = 0;//一旦0で埋めておく
    }
    //初期値を設定
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    dp[1][2] = c[0];

    for(int i = 2; i <= n; i++){//前日にした行いによってその日の状態が変わる。n日目まである。
        dp[i][0] = std::max(dp[i-1][1] + a[i-1], dp[i-1][2] + a[i-1]);
        dp[i][1] = std::max(dp[i-1][0] + b[i-1], dp[i-1][2] + b[i-1]);
        dp[i][2] = std::max(dp[i-1][0] + c[i-1], dp[i-1][1] + c[i-1]);
    }

    max = std::max(dp[n][0], dp[n][1]);//3数を比べる
    max = std::max(max, dp[n][2]);

	cout << max << endl;
	return 0;
}