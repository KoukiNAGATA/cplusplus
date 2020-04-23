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
    int n, k, tmp;
    int l = 0;
    bool flag = true;
	cin >> n >> k;
    vector<int> a;
    vector<int> a1;//負の数
    vector<int> a2;//自然数
    vector<int> tans;//一旦積を格納
    vector<int> ans;
    vector<int> ans1;//負の数
    vector<int> ans2;//自然数
    //辞書式にソート
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp >= 0){
            a2.push_back(tmp);
        }else{
            a1.push_back(tmp);
        }
    }
    sort(a1.begin(), a1.end(),std::greater<int>());
    for(int i : a1)a.push_back(a1[i]);
    sort(a2.begin(), a2.end());
    for(int i : a2)a.push_back(a2[i]);
    a.erase(unique(a.begin(), a.end()), a.end());//重複の削除
    int v = *unique(a.begin(), a.end());

    for(int i = 0; i < n; ++i){
        if(a[i] < 0 && flag){
            for(int j = v-i; j >= 0; --j){
                if(a[j] >= 0){
                    tans[l] = a[i] * a[j];
                    l++;
                    if(l > k+99){
                        flag = false;
                        break;
                    }
                }
            }
        }else if(flag){
            for(int j = i+1; j < n; ++j){
                tans[l] = a[i]*a[j];
                l++;
                if(l > k+99){
                        flag = false;
                        break;
                    }
            }
        }
    }
    //辞書式にソート
    for(int i : a){
        if(a[i] >= 0){
            ans2.push_back(a[i]);
        }else{
            ans1.push_back(a[i]);
        }
    }
    sort(ans1.begin(), ans1.end(),std::greater<int>());
    sort(ans2.begin(), ans2.end());
    for(int i : ans1)ans.push_back(ans1[i]);
    for(int i : ans2)ans.push_back(ans2[i]);
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());//重複の削除
    cout << ans[k-1] << endl;
	return 0;
}