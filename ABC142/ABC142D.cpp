#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
using ll=long long;

ll GCD(ll x, ll y) {//最大公約数
    //ユークリッド：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x%y ? GCD(y, x%y) : y;
}

ll LCM(ll x, ll y) {//最小公倍数
    return x * y / GCD(x, y);
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b;
    int ans = 1;
    cin >> a >> b;

    ll gcd = GCD(a, b);
    //GCDの約数のなかで素数であるものを探す
    if(gcd > 1){
            for(ll i = 2; i*i <= gcd; i++){//gcdも変化していく
                if (gcd % i == 0) {
                    ans ++;
                    while (gcd % i == 0) { // 素数で割り切れなくなるまで割っていく
                        gcd /= i;
                    }
                }
            }
        }

    if(gcd > 1)ans ++; //i < gcd(iより大きい素数の積)ならループは続くし、i > gcd(iより小さい素数)なら後は1つの素数でgcdを割ったら終わり。1足すのと同じ

    cout << ans <<endl;
    return 0;
}