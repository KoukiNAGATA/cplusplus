#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
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

//反転しているときは逆側に挿入すればよい。O(b+(a.size()/2))
int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a, d;
    ll b, c;
    bool rev = false;//反転しているか
    cin >> a >> b;
    REP(i, b){
        cin >> c;
        if(c == 1){//反転
            rev = !rev;
        }else{
            cin >> c >> d;
            if((c == 1 && !rev) || (c == 2 && rev)){//先頭
                a.insert(0, d);//先頭に入れる操作は計算量が悪い。
            }else{//後ろ
                a.append(d); 
            }
        }
    }
    //O(a.size()/2)は大きいので1度だけに。
    if(rev){
        reverse(a.begin(), a.end());
    }

    cout << a << endl;
	return 0;
}