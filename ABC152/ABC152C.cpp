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
    int n;
    int cnt = 0;
    int min =inf;

	cin >> n;

    vector<int> tmp(n, 0);
    for(int i = 0; i < n; i++){
        cin >> tmp[i];
    }

    for(int i = 0; i < n; i++){
        if(tmp[i] <= min){//最小値がでた場合
            min = tmp[i];
            cnt++;
        }
    }

    cout << cnt << endl;
	return 0;
}