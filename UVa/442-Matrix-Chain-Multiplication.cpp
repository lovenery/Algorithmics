// UVa 442 Matrix Chain Multiplication
// 參考自: http://hanting1225.blogspot.tw/2015/08/uva-442-matrix-chain-multiplication.html
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

struct Matrix
{
    int row, col;
    int times; // 乘起來的結果
    Matrix(int r = 0, int c = 0, int t = 0) :row(r), col(c), times(t) {} // 建構子
    Matrix operator*(Matrix &m) // operator overloading
    {
        int t = (col == m.row ? row*col*m.col : -1); // 判斷是否可乘，負數表示不行
        return Matrix(row, m.col, t); // 回傳乘完後的結果
    }
};
int main()
{
    // input個數
    int N;
    cin >> N;

    // input
    char ch;
    int r, c; // row, col
    map<char, Matrix> Map;
    Map.clear();
    for (int i = 0; i<N; i++)
    {
        cin >> ch >> r >> c;
        Map[ch] = Matrix(r, c);
    }

    // 解題
    stack<Matrix> stk;
    string str;
    cin.ignore();
    while (getline(cin, str))
    {
        // stack初始化
        while (stk.size())
        {
            stk.pop();
        }

        // 檢查格式, 影響最後輸入error或答案
        bool valid = true;

        // 和
        int sum = 0;

        // 掃過每一個輸入字元
        for (int i = 0; i<str.size() && valid; i++)
        {
            // 如果是右括號, 從stack中pop兩個出來做乘法
            if (str[i] == ')')
            {
                // 如果當前是右括號且stack大小小於2, error
                if (stk.size()<2)
                {
                    valid = false;
                }
                else
                {
                    Matrix t1 = stk.top();
                    stk.pop();
                    Matrix t2 = stk.top();
                    stk.pop();
                    Matrix result(t2*t1);
                    // 乘完看是不是 -1
                    if (result.times<0)
                    {
                        valid = false;
                    }
                    else
                    {
                        sum += result.times;
                        stk.push(result);
                    }
                }
            }
            // 如果是字母, push進stack
            else if (str[i] != '(')
            {
                Matrix tmp = Map[str[i]];
                stk.push(tmp);
            }
        }

        // 輸出答案
        if (valid)
        {
            cout << sum << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    return 0;
}
