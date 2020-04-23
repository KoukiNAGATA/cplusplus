#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1000000000

int GCD(int x, int y) {
    //ユークリッド：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x%y ? GCD(y, x%y) : y;
}

int main() {
    int N;
    int ans = MAX;
    cin >> N;
    vector<int> Mon(N);
    for(int i = 0; i < N; i++){
        cin >> Mon[i];
    }
    int tmp = Mon[0];
    for(int j = 1; j < N; j++){
            if(tmp > Mon[j]){
                tmp = GCD(tmp, Mon[j]);
                if(ans > tmp){
                    ans = tmp;
                }
            }else if(Mon[j] > tmp){
                tmp = GCD(Mon[j], tmp);
                if(ans > tmp){
                    ans = tmp;
                }
            }
            if(ans == 1){
                cout << ans << endl;
                return 0;
            }
        }
    cout << ans << endl;
    return 0;
}