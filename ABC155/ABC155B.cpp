#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int inf = 1000000007;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, a;

	cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a % 2 == 0 && (a % 3 != 0 && a % 5 != 0)){
            cout << "DENIED" << endl;
	        return 0;
        }
    } 
    cout << "APPROVED" << endl;
	return 0;
}