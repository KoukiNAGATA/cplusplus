#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
 
const int N = 1.5e6 + 10;
 
int que[N], a[N], bucket[N];
 
int main(){
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ans = 0;

	FOR(i, 1, n){
		cin >> a[i];
        // バケットを埋める
		bucket[a[i]] ++;

		if (i == m){ // a_mより手前のm個分について、バケットに要素があるかを見ていき、mem(a_1, a_2, ..., a_m)を求める。
			while (bucket[ans]) ans++;
		}else if(i > m){ // m個分からはみ出た一個をバケットから取り出し、そのバケットが空になるか調べ、min(ans, mem(a_(1+i), a_(2+i), ..., a_(m+i)))を求める
			bucket[a[i - m]] --;
			if (!bucket[a[i - m]]) ans =  min(ans, a[i - m]);
        }
    }
	cout << ans << endl;
	return 0;
}