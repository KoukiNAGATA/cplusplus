#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
#include <math.h>

bool isPrime(ll num)//素数かどうかを判定する。
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    long double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, ans, tmp_a, tmp_b;
    vll similar(99999, 0);
    cin >> n;
    //先にiまでにいくつあるかの配列を全部出す
    similar[3] = 1;//初期化
    FOR(i, 4, 100000){
        if(isPrime(i) && isPrime((i + 1)/2)){
            similar[i] = similar[i - 1] + 1;
        }else{
            similar[i] = similar[i - 1];
        }
    }
    REP(i, n){
        ans = 0;
        cin >> tmp_a >> tmp_b;
        ans = similar[tmp_b] - similar[tmp_a - 1];//累積和の考え。
        printf("%d\n", ans);//行数多いので高速化。
    }
	return 0;
}
