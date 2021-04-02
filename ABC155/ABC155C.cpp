#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<std::string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end()); //辞書式にソート
    vector<int> dp(n, 0);
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
            if (dp[i] > max)
            {
                max = dp[i];
            }
        }
        else
        {
            dp[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == max)
        {
            cout << s[i] << "\n";
        }
    }
    return 0;
}