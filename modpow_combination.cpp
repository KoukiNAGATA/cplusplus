#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
#define mod 998244353//今回のでかい素数
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

//mod...オーバーフローしないようにその都度割っていく！
//階乗などを配列で持っておくことで計算量を減らす！

ll n;
ll fact[2*MAX+10];//階乗(factorial)
ll invfact[2*MAX+10];//階乗の逆元

ll modpow(ll A, ll N){//二分累乗法により、Nを2の累乗の和に分解してO(logN)で求める
    ll res = 1;
    while(N > 0) {
        if(N & 1) res = res * A % mod;
        A = A * A % mod;
        N >>= 1;
    }
    return res;
}

ll combination(ll A,ll B){//combination(O(1))
    if(A < B) return 0;
    if(A < 0 || B < 0) return 0;
	return fact[A]*invfact[A-B]%mod*invfact[B]%mod;
}

int main(){//階乗と逆元のテーブル作成
    cin>>n;
    fact[0] = 1;//0!
	FOR(i, 1, n) fact[i] = fact[i-1]*i%mod;//fact[i] : i!の配列(factorial)

    invfact[n] = modpow(fact[n], mod-2);//フェルマーの小定理よりaの逆元はa^(mod-2)
    FORR(i, n-1, 0) invfact[i]=invfact[i+1]*(i+1)%mod;//(i+1)!の逆元にi+1かけてるだけ
}