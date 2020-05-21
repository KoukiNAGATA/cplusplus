#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char del) {//文字列をある文字で分割する
    int first = 0;
    int last = str.find_first_of(del);
    vector<string> result;
 
    while (first < str.size()) {
        string subStr(str, first, last - first);
 
        result.push_back(subStr);
 
        first = last + 1;
        last = str.find_first_of(del, first);
 
        if (last == string::npos) {
            last = str.size();
        }
    }
 
    return result;
}

int main() {
    int daysInYear, daysInMonth, daysInWeek;
    string date;
    cin >> daysInYear >> daysInMonth >> daysInWeek >> date;
    int year, month, day;//入力された年、月、日
    int days = 0;//これまでの日数の合計
    int remainder = 0;//日数を曜日で割った余り
    char ans = 'A';//答えの曜日
    char del = '-';//日付を分割する文字

    vector<string> tmp = split(date, del);//分割した文字列を格納
    year = atoi(tmp[0].c_str());//StringtoInt
    month = atoi(tmp[1].c_str());
    day = atoi(tmp[2].c_str());

    if(month > daysInYear/daysInMonth+1 || day > daysInMonth){//例外処理
        cout << -1 <<"\n";
        return 0;
    }

    days += day + month*daysInMonth;//月日はそのまま経過日数として入れてよい
    days += daysInYear*year;//余り以外の日数
    days += ((daysInYear%daysInMonth)*year)/daysInMonth;//(余った日数*年数)/一月の日数
    remainder = days % daysInWeek;
    if(remainder == 0){//0になってしまうので週の日数分足す
        ans += daysInWeek-1;//1月1日が基準なので1引く
    }else{
        ans += remainder-1;//1月1日が基準なので1引く
    }
    cout << ans <<"\n";
    return 0;
}
