#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
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

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    //そのまま割ると割り切れない場合は1回少なくなってしまう。1回多くはならないギリギリ=(ダメージ-1)を足す。
    ll x = (a+d-1)/d;
    ll y = (c+b-1)/b;
    cout<<(x>=y?"Yes":"No")<<"\n";
	return 0;
}