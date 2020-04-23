#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int cnt_ac = 0;
  	int cnt_wa = 0;

	cin >> n >> m;

    vector<bool> dp(n, false);
    vector<int> tmp(n, 0);
    int num;
    std::string res;

    for(int i = 0; i < m; i++){
        cin >> num >> res;
        if(res == "AC"){
            if(dp[num] == false){
                cnt_ac++;
                dp[num] = true;
                cnt_wa += tmp[num];
            }
        }else{
            if(dp[num] == false){
                tmp[num]++;
            }
        }
    }

    cout << cnt_ac << " " << cnt_wa << endl;

	return 0;
}