#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tmp;
    vector<vector<bool>> flg(3, vector<bool>(3));
    vector<vector<int>> num(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> num[i][j];
        }
    }
    while (cin >> tmp)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (num[i][j] == tmp)
                {
                    flg[i][j] = true;
                }
            }
        }
    }

    //ビンゴなんてたかが8通り
    if (flg[0][0] == true && flg[0][1] && flg[0][2])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[1][0] && flg[1][1] && flg[1][2])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[2][0] && flg[2][1] && flg[2][2])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[0][0] && flg[1][0] && flg[2][0])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[0][1] && flg[1][1] && flg[2][1])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[0][2] && flg[1][2] && flg[2][2])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[0][0] && flg[1][1] && flg[2][2])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (flg[0][2] && flg[1][1] && flg[2][0])
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    cout << "No"
         << "\n";
    return 0;
}