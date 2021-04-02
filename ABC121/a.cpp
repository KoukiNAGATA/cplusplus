#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    //ちゃんと初期化する
    int tmp = h * W + w * H - h * w;
    cout << H * W - tmp << "\n";
    return 0;
}
