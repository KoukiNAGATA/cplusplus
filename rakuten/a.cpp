#include<iostream>
#include<vector>
const int inf = 1000000007;//仮の最大値

int solution(std::vector<int> &a) {
    int answer = inf;//答え
    int num_a = a.size();//木の本数
    int num_change = 0;//仮の木の高さの変更回数
    for(int i = 1; i < num_a; i++){//2本目からn本目が高い->低い->高い...の順になる場合の最小の木の変更数
        if(i % 2 != 0){//偶数本目で、かつとなりの木より高い場合
            if(i == num_a-1){//端
                if(a[i] > a[i-1]){
                    num_change ++;
                }
            }else{//それ以外
                if(a[i] > a[i-1] || a[i] > a[i+1]){
                    num_change ++;
                }
            }
        }
    }
    answer = std::min(answer, num_change);//最小値の更新

    num_change = 0;//仮の木の高さの変更回数
    for(int i = 1; i < num_a; i++){//2本目からn本目が低い->高い->低い...の順になる場合の最小の木の変更数
        if(i % 2 == 0 && a[i] > a[i-1]){//奇数本目で、かつとなりの木より高い場合
            if(i == 0){//端
                if(a[i] > a[i+1]){
                    num_change ++;
                }
            }else if(i == num_a-1){//端
                if(a[i] > a[i-1]){
                    num_change ++;
                }
            }else{//それ以外
                if(a[i] > a[i-1] || a[i] > a[i+1]){
                    num_change ++;
                }
            }
        }
    }
    answer = std::min(answer, num_change);//最小値の更新

    std::cout << answer <<"\n";
	return 0;
}