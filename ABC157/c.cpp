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
    int n, m, s, c, num, ans;

	cin >> n >> m;
    vector<int> a (n, -1);

    for(int i = 0; i < m; i++){
        cin >> s >> c;
        num = s-1;//桁数
        if(a[num] == -1 || a[num] == c){//元々値が入っていないor元々入っている値が同じ
            a[num] = c;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(n == 3){//n==3
        if(a[0] == 0){
            cout << -1 << endl;
            return 0;
        }else if(a[0] == -1 && a[1] == 0){
            cout << -1 << endl;
            return 0;
        }

        if(a[0] == -1) a[0] = 1;//3ケタで最小の数字は100番代
        if(a[1] == -1) a[1] = 0;
        if(a[2] == -1) a[2] = 0;
        
        ans = a[0]*100 + a[1]*10 + a[2];
        cout << ans << endl;
        return 0;

    }else if(n == 2){//n==2。必ず2ケタでなければならない！
        if(a[0] == 0){
            cout << -1 << endl;
            return 0;
        }

        if(a[0] == -1) a[0] = 1;//2ケタで最小の数字は10番代
        if(a[1] == -1) a[1] = 0;
        ans = a[0]*10 + a[1];
        cout << ans << endl;
        return 0;

    }else{//n==1
        if(a[0] == -1) a[0] = 0;
        ans = a[0];
        cout << ans << endl;
        return 0;
    }
}
