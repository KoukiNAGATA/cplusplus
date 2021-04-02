#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll r = 0;
    ll b = 0;
    ll n = 0;
    cin >> n;
    char c;
    //charは1文字ずつ処理する。""で囲むと配列を表す。
    while (cin >> c)
    {
        if (c == 'R')
        {
            r++;
        }
        else
        {
            b++;
        }
    }

    if (r > b)
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else
    {
        cout << "No"
             << "\n";
        return 0;
    }
}