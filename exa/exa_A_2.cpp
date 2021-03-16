#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main(){
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll l, m, n;
    cin >> l >> m >> n;
    if(m==l&&l==n&&n==m){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }
}