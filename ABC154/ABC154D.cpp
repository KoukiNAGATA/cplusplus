#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<float> v(n + k + 10, 0.0);
    vector<float> s(n + k + 10, 0.0);
    vector<float> dp(n + k + 10, 0.0);

    float tmp;
    for (int i = 1; i <= n; i++)
    { //1オリジン
        cin >> tmp;
        v[i] = (1.0 + tmp) / 2.0;
    }

    //初期化
    v[0] = 0.0;
    if (k > 1)
    {
        for (int i = 1; i < k; i++)
        { //0番目からk-1番目までの和
            s[0] += v[i];
        }
    }
    else
    {
        s[0] = 0.0;
    }
    dp[0] = s[0];

    for (int i = 1; i <= n; i++)
    {                                              //余分に回して0を入れる
        s[i] = s[i - 1] - v[i - 1] + v[i + k - 1]; //n+10の範囲を超えてる可能性があるので余裕もって配列を作る
        if (s[i] > dp[i - 1])
        { //最大値を更新
            dp[i] = s[i];
        }
        else
        { //更新しなかった
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}