// alg week8 最小編輯成本 MEC 
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

void MEC(string s1, string s2) {

    int m = s1.size();
    int n = s2.size();

    int **D = new int*[m + 1];
    for (int i = 0; i < m+1; i++)
    {
        D[i] = new int[n + 1];
    }

    // 初始化
    int cost1 = 2; // Deletion
    int cost2 = 3; // Insertion
    int cost3 = 4; // Substitution
    for (int i = 0; i <= m; i++)
    {
        D[i][0] = i * cost1;
    }
    for (int j = 0; j <= n; j++)
    {
        D[0][j]= j * cost2;
    }

    // 演算法
    for (int  i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                D[i][j] = D[i - 1][j - 1];
            }
            else
            {
                D[i][j] = min(min(D[i - 1][j] + cost1, D[i][j - 1] + cost2), D[i - 1][j - 1] + cost3);
            }
        }
    }

    // debug
    for (int i = m; i >= 0; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << setw(2) << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << D[m][n] << endl;
};
int main()
{
    int num_i = 1;
    //cin >> num_i;
    //cin.ignore();
    for (int i = 0; i < num_i; i++)
    {
        string s1 = "HABCDACE";
        string s2 = "DABCDACE";
        //getline(cin, s1);
        //getline(cin, s2);
        MEC(s1, s2);
    }

    system("pause");
    return 0;
}

/*
Sample input
2
HABCDACE
DABCDACE
QWERTY
HWTDDGKY

Sample output
4
20
*/
