#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

#define REPs(i, n) for(int i = 0; i <= n; i++)

int main(){
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, p, ap;
    cin >> a >> p;
    ap = a*3+p;

    cout << ap/2 << endl;
    return 0;
}