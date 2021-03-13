#include <bits/stdc++.h>
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
using Graph = vector<vector<int>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t, n, a, b, c, d, ans, tmp, x, re;
    cin >> t;
    REP(i, t){
        cin >> n >> a >> b >> c >> d;
        ans = d*(n+1);
        tmp = d;//初期化。x=1にするのにかかる。

        //c
        x = n;
        tmp = d;
        while(x > 4){
            re = min(x % 5, 5 - x % 5);
            if( re == x % 5){
                x = (x-re)/5;
            }else{
                x = (x+re)/5;
            }
            tmp += d*re + c;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        x = n;
        tmp = d;
        re = min(x % 3, 3 - x % 3);
        if( re == x % 3){
                x = (x-re)/3;
        }else{
            x = (x+re)/3;
        }
        tmp += d*re + b;
        while(x > 4){
            re = min(x % 5, 5 - x % 5);
            if( re == x % 5){
                x = (x-re)/5;
            }else{
                x = (x+re)/5;
            }
            tmp += d*re + c;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        x = n;
        tmp = d;
        re = x % 2;
        x = (x-re)/2;
        tmp += d*re + a;
        while(x > 4){
            re = min(x % 5, 5 - x % 5);
            if( re == x % 5){
                x = (x-re)/5;
            }else{
                x = (x+re)/5;
            }
            tmp += d*re + c;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        //b
        x = n;
        tmp = d;
        re = min(x % 5, 5 - x % 5);
        if( re == x % 5){
            x = (x-re)/5;
        }else{
            x = (x+re)/5;
        }
        tmp += d*re + c;
        while(x > 2){
            re = min(x % 3, 3 - x % 3);
            if( re == x % 3){
                x = (x-re)/3;
            }else{
                x = (x+re)/3;
            }
            tmp += d*re + b;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        x = n;
        tmp = d;
        while(x > 2){
            re = min(x % 3, 3 - x % 3);
            if( re == x % 3){
                x = (x-re)/3;
            }else{
                x = (x+re)/3;
            }
            tmp += d*re + b;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        x = n;
        tmp = d;
        re = x % 2;
        x = (x-re)/2;
        tmp += d*re + a;
        while(x > 2){
            re = min(x % 3, 3 - x % 3);
            if( re == x % 3){
                x = (x-re)/3;
            }else{
                x = (x+re)/3;
            }
            tmp += d*re + b;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        //a
        x = n;
        tmp = d;
        re = min(x % 5, 5 - x % 5);
        if( re == x % 5){
            x = (x-re)/5;
        }else{
            x = (x+re)/5;
        }
        tmp += d*re + c;
        while(x >= 1){
            re = x % 2;
            x = (x-re)/2;
            tmp += d*re + a;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        x = n;
        tmp = d;
        re = min(x % 3, 3 - x % 3);
        if( re == x % 3){
                x = (x-re)/3;
        }else{
            x = (x+re)/3;
        }
        tmp += d*re + b;
        while(x >= 1){
            re = x % 2;
            x = (x-re)/2;
            tmp += d*re + a;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        x = n;
        tmp = d;
        while(x >= 1){
            re = x % 2;
            x = (x-re)/2;
            tmp += d*re + a;
        }
        tmp += d*(x - 1);
        ans = min(ans, tmp);

        cout << ans << endl;
    }
    return 0;
}