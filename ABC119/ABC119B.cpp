#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int N;
    double S = 0.0;
    cin >> N;
    std::vector<double> x(N, 0.0);
    std::vector<string> u(N);
    int i;
    for(i = 0; i < N; i++){
        cin >> x[i];
        cin >> u[i];
        if(u[i] == "JPY"){
            S += x[i];
        }else{
            x[i] = x[i]*380000.0;
            S += x[i];
        }
    }

    cout << S << endl;
    return 0;
}