#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;
const ll  inf = 1000000007;
const int MAX_N = 110;
const int MAX_V = 100010;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    ll W;//下のwと重複してしまうので大文字
    ll w[MAX_N], v[MAX_N];
    //0オリジンに揃えよう！
    cin >> n >> W;
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
    }

    ll dp[MAX_N][MAX_V];//N<=100, v_i<= 10^3
    for(int i = 0; i < MAX_N; ++i){//配列の宣言では個数を宣言するので、0オリジンならばMAX_Nを含んではいけない
        for(int j = 0; j < MAX_V; ++j){
            dp[i][j] = inf; //初期化。Mの最小値を求めるdpなのでinf
        }
    }


    //DP
    dp[0][0] = 0; //初期条件。dpではいきなり1個ある状態から考え始めるので、ループに入る前に初期化！
    for(int i = 0; i < n; ++i){//荷物の番目を進めていく。荷物0個の場合があるから0〜nやで！
        for(int sum_v = 0; sum_v < MAX_V; ++sum_v){//荷物の重さ上限を上げていく。価値の総和がsum_vとなるときの重さの最小値を求めるDPをしている
            if(sum_v - v[i] >= 0){//v[i]がsum_v内に収まる場合、i番目の品物を選ぶ
                dp[i+1][sum_v] = min(dp[i+1][sum_v], w[i] + dp[i][sum_v - v[i]]);//まだv_iが入るキャパがあるナップサックに荷物を入れて重さを比較する
            }else{
                dp[i+1][sum_v] = min(dp[i+1][sum_v], dp[i][sum_v]);//1個前までのsum_vの方が小さければiは選ばない
            }
        }
    }

    //最適値の出力
    ll res = 0;
    for (int sum_v = 0; sum_v < MAX_V; ++sum_v) {
        if (dp[n][sum_v] <= W){//<=Wを満たしていれば、sum_vはループで単調増加するからそこだけ見れば良い
            res = sum_v;
        }
    }
    cout << res << endl;
    return 0;
}