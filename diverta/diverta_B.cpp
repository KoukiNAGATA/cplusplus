#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

#define REPs(i, n) for (int i = 0; i <= n; i++)

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int cnt = 0;
    int R = n / r;
    int G = n / g;
    int B = n / b;

    //まずrを固定して、その中でgを固定。その中でbを動かしてnが作れたら増やす
    REPs(i, R)
    {
        if (n == r * i)
        {
            cnt++;
            break;
        }
        REPs(j, G)
        {
            if (n == r * i + g * j)
            {
                cnt++;
                break;
            }
            REPs(k, B)
            {
                if (n == r * i + g * j + b * k)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}