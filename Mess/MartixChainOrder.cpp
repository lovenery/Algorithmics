// 矩陣鏈乘積演算法 MartixChainOrder
#include <iostream>
using namespace std;

void PRINT_OPTIMAL_PARENS(int** s, int i, int j) {
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
        PRINT_OPTIMAL_PARENS(s, s[i][j] + 1, j);
        cout << ")";
    }
}
void debug(int** a) {
    int length = 6;
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixChainOrder(int* e, int n) {
    int **m;
    m = new int*[n + 1]; // 0~n, use 1~n
    for (int i = 0; i <= n; ++i) {
        m[i] = new int[n + 1];
    }
    // 初始化方便debug
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            m[i][j] = -1;
        }
    }
    // 給印用的
    int **OPTIMAL_PARENS;
    OPTIMAL_PARENS = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        OPTIMAL_PARENS[i] = new int[n + 1];
    }

    // 開始演算法
    // 1~n, 對角線都0
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    //debug(m);

    // d=1~n-1, 每一個橫排
    for (int d = 1; d <= n-1; d++)
    {
        // 1~n-d, 橫排中的格子
        for (int i = 1; i <= n-d; i++)
        {
            int j = i + d;
            m[i][j] = 2147483647;
            // i~j-1, 計算每個格子的最小值
            for (int k = i; k <= j-1; k++)
            {
                int tmp = m[i][k] + m[k + 1][j] + e[i-1] * e[k] * e[j];
                if (tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    OPTIMAL_PARENS[i][j] = k;
                }
            }
        }
    }
    //debug(m);
    PRINT_OPTIMAL_PARENS(OPTIMAL_PARENS, 1, n);
    cout << endl;
    cout << m[1][n]; // ans
}
int main()
{
    int num = 6; // 幾個矩陣
    //cin >> num;
    int *row_col = new int[num + 1]; // 幾個矩陣+1個數字要輸入
    int test_data[7] = { 30, 35, 15, 5, 10, 20, 25 };
    for (int i = 0; i < num + 1; i++)
    {
        row_col[i] = test_data[i];
        //cin >> row_col[i];
    }
    MatrixChainOrder(row_col, num);

    system("pause");
    return 0;
}

