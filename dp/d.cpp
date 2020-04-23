#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;
const int inf = 1000000007;

int main()
{
    int n;
    ll W;//下のwと重複してしまうので大文字
    ll w[110], v[110];
    cin >> n >> W;
    for(int i = 1;i <= n;i++){
        cin >> w[i] >> v[i];
    }
    ll dp[110][100010];

    for(int i = 0;i <= n;i++){//荷物の番目を進めていく。荷物0この場合があるから0〜nやで！
        for(int j = 0;j <= W;j++){//荷物の重さ上限を上げていく
            if(i == 0||j == 0){
                dp[i][j] = 0;//初期値。荷物0個の場合と、重さ0の場合は0
            }else if(w[i] <= j){
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);//まだw[i]が入るキャパがあるナップサックに荷物を入れて比較する
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}
