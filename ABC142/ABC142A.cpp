#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    float ans;
    cin >> N;
    //ちゃんと初期化する
    if (N == 1)
    {
        ans = 1.0000000000;
    }
    else if (N % 2 == 0)
    {
        ans = 0.5000000000;
    }
    else
    {
        ans = (float)(N / 2 + 1) / N;
    }
    cout << ans << "\n";
    return 0;
}
