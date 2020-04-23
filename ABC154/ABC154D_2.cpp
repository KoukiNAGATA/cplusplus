#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int n, k, ans, tmp;
	cin >> n >> k;
    vector<int> v(n, 0);

    for(int i = 0; i < n; i++)cin >> v[i];

    //初期化
    tmp = 0;
    for(int i = 0;i < k; i++)tmp += (v[i]+1);
    ans = tmp;//配列0番目〜k-1番目までの和が初期値
    for(int i = k; i < n; i++){//kから初めていくとインデックスがきれい
        tmp = tmp + (1+v[i]) - (1+v[i-k]);//隣接する和は累積和の引き算
        ans = max(ans, tmp);
    }

    if(ans%2){//ここで2で割ってしまえば整数の問題として扱える
        cout<<ans/2<<".5"<<endl;
    }else{ 
        cout<<ans/2<<endl;
    }
	return 0;
}