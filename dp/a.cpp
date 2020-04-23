#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int h[100000];
    int dp[100000];

	cin >> n;

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    dp[0] = 0;//初期値
    dp[1] = abs(h[1] - h[0]);//1つ目は比較なく決まる

    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));//２つ前から飛ぶ場合と1つ前から飛ぶ場合を比較し続ける
    }

	cout << dp[n-1] << endl;
	return 0;
}