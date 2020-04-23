#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m, tmp, ans;
    ans = 0;

	cin >> n >> k >> m;

    for(int i = 0; i < n-1; i++){
        cin >> tmp;
        ans += tmp;
    }

    int a = 0;
    if(ans >= n * m){
        cout << a << endl;
        return 0;
    }else if(ans + k >= n * m){
        int a = n * m - ans;
        cout << a << endl;
        return 0;
    }else{
        cout << -1 << endl;
        return 0;
    }

	return 0;
}