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

int n;
void dfs(string s, char mx){
    if(s.length() == n){
        printf("%s\n", s.c_str());//stringからchar型のポインタを取り出し
    } else {
        for(char c = 'a';c <= mx; c++){//char型はfor文を作れる！
            dfs(s + c, ((c == mx) ? (char)(mx + 1) : mx));//+1すると1つ次の文字を得られる。ここでmx+1するともう1つループが回る！
        }
    }
}

int main(void){
    cin >> n;
    dfs("", 'a');
    return 0;
}