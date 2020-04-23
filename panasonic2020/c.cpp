#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<math.h>
#include<float.h>
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
using p = pair<int, int>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    long double a, b, c;
    cin >> a >> b >> c;
    long double aa = sqrtl(a);
    long double bb = sqrtl(b);
    long double cc = sqrtl(c);
    long double eps = 1.0E-14;//誤差。この大きさだとうまくいく。
    if(aa + bb + eps < cc){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
	return 0;
}