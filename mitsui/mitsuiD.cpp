#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int cntLucky(int s)
{
}

int main()
{
    int n, s;
    cin >> n >> s;

    int cnt = 1;
    //被りない場合を計算しておく
    for (int i = n; i > 0; --i)
    {
        cnt = cnt * i;
    }
    for (int i = n - 3; i > 0; --i)
    { //n>4
        cnt = cnt / i;
    }
    cnt = cnt / 6; //3!の分

    //ここから下で被りを数える

    cout << cnt << "\n";
    return 0;
}
