#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 0;//気温の和
    int ans, temperature;//答えを出力する変数ansと、気温の入力を受け付ける変数temperature
    int min_temperature = 100;//最低気温
    int max_temperature = 0;//最高気温
    for(int i = 0; i < 7; i++){
        cin >> temperature;
        sum += temperature;
        min_temperature = min(min_temperature, temperature);//最低気温の更新
        max_temperature = max(max_temperature, temperature);//最高気温の更新
    }
    //最高気温と最低気温を引く。
    sum -= min_temperature;
    sum -= max_temperature;
    ans = sum / 5;//最高気温と最低気温を引いて5で割る。
    cout << ans <<"\n";
	return 0;
}