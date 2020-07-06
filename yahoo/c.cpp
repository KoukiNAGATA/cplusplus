#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define inf 1000000007

int main() {
    long long n, h, r, d, h_tmp, c_tmp;//ジャンプ台の地点とコストを受け付ける仮変数
    cin >> n >> h >> r;
    d = 0;//ジャンプ台の飛距離の初期値
    vector<pair<long long, long long>> jump_boards;//ジャンプ台の高さ、コストの配列
    vector<long long> dp(n+10, inf);//あるジャンプ台までの最低スコアを更新していくdpで解く。初期値をinfとする。

    for(int i = 0; i < n; i++){//ジャンプ台の入力
        cin >> h_tmp >> c_tmp;
        jump_boards.push_back(h_tmp, c_tmp);
    }

    dp[0] = 0;//初期値
    dp[1] = jump_boards[1].first * r;//1つ目は比較なく決まる
    d = jump_boards[1].first;

    for(int i = 2; i < n; i++){
        for(int j = 1; j < i; j++){//iのジャンプ台に行くのにjのジャンプ台を使った方がコストが低いか調べる
            dp[i] = min(dp[i], dp[i - j] + jump_boards[j].second + (jump_boards[i].first - jump_boards[i-j].first) * r);
        }
    }

    cout << dp[n-1] <<"\n";//
	return 0;
}