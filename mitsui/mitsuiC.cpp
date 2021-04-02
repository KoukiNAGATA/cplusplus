#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    cin >> x;
    //2000以上は全部組み合わせがある。
    if (x >= 2000)
    {
        cout << 1 << "\n";
        return 0;
    }
    //100未満は無理！
    if (x < 100)
    {
        cout << 0 << "\n";
        return 0;
    }
    //十の位以下については、5*cntの分までならいくらでも対応可能。
    int cnt = 0;
    while (x >= 100)
    {
        x = x - 100;
        cnt++;
    }
    int m = cnt * 5;
    if (x <= m)
    {
        cout << 1 << "\n";
        return 0;
    }
    else
    {
        cout << 0 << "\n";
        return 0;
    }
}
