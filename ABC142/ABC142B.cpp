#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	int N, K, L;
    int ans = 0;
    cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> L;
        if(L >= K){
            ans ++;
        }
	}
    cout << ans << endl;
}
