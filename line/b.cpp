#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<pair<int, int>> goods[n];//商品情報
    //商品情報の入力
    for(int i = 0;i < n;i++){
        cin >> tmp;
        goods[i].first = tmp;
        if((string)tmp.size() == 12){//通常商品
            cin >> tmp;
            goods[i].second = tmp;
        }else{//量り売り商品
            goods[i].second = 0;
        }
    }

    //会計情報の入力
    string num;//ポイントカード番号
    vector <int> cards;//ポイントカードの配列
    int price = 0;
    bool flg1 = 0;//staff call 1
    bool flg2 = 0;//staff call 2
    bool is_card = 0;//カードがあるか
    while(getline(cin, num)){//startの行の入力がある限り
        if (num.size() > 6){
            num = num.substr(6);// start 以降の文字を取る
            cards.push_back((int)num);
        }
        for(int i = 0; i < n; i++){
            cin >> tmp;//番号の入力
            if((string)tmp.size() == 13){
                //価格をそのままpriceに
                //チェックサムを確認し、間違っていればflg2 = 1
            }else if((string)tmp.size() == 15){
                //価格を%割引してpriceに
                //価格がもとより大きいまたは0円以下ならばflg1 = 1
                //チェックサムを確認し、間違っていればflg2 = 1
            }else if((string)tmp.size() == 18){
                //価格を円割引してpriceに
                //価格がもとより大きいまたは0円以下ならばflg1 = 1
                //チェックサムを確認し、間違っていればflg2 = 1
            }else{
                flg2 = 1;
            }

            //出力
            if(flg1 && flg2){
                cout << "staff call: 1 2" <<"\n";
                return 0;
            }else if(flg1){
                cout << "staff call: 1" <<"\n";
                return 0;
            }else if(flg2){
                cout << "staff call: 2" <<"\n";
                return 0;
            }else{//エラーなし
                if(is_card){
                    //カードがある場合、カードを使う。ポイントをまず使い切り、残った代金を出力、1パーセントをポイントに加算
                }else{
                    //カードがない場合、現金をそのまま出力。
                }
            }
        }
        getline(cin, num);//endの分
    }
	return 0;
}