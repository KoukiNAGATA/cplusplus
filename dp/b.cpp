#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;

int main() {
    int n, k;
    int h[100000];
    int dp[100000];

	cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> h[i];
        dp[i] = inf;//一旦無限大で埋めておく
    }

    dp[0] = 0;//初期値
    dp[1] = abs(h[1] - h[0]);//1つ目は比較なく決まる

    for(int i = 2; i < n; i++){
        int K = min(i, k);
        
        for(int j = 1; j <= K; j++){
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }

	cout << dp[n-1] << endl;
	return 0;
}