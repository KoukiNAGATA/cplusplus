#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int inf = 1000000007;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;

	cin >> a >> b >> c;
    if(a == b && a != c){
        cout << "Yes" << endl;
        return 0;
    }else if(a == c && a != b){
        cout << "Yes" << endl;
        return 0;
    }else if(b == c && a != b){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
	return 0;
}