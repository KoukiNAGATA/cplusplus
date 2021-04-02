#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 1000000000

long long GCD(long long x, long long y)
{ //最大公約数
    //ユークリッド：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x % y ? GCD(y, x % y) : y;
}

long long LCM(long long x, long long y)
{ //最小公倍数
    return x * y / GCD(x, y);
}

int main()
{
    long long a, b;
    int ans = 1;
    cin >> a >> b;
    long long gcd = GCD(a, b);
    //GCDの約数のなかで素数であるものを探す
    for (int i = 2; i <= gcd; i++)
    { //gcdも変化していく
        if (gcd % i == 0)
        {
            ans++;
        }
        while (gcd % i == 0)
        { // 素数で割り切れなくなるまで割っていく
            gcd /= i;
        }
    }
    cout << ans << "\n";
    return 0;
}