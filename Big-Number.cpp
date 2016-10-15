// 大數問題
// ref:
// http://dhcp.tcgs.tc.edu.tw/c/p018.htm
// http://acm.nudt.edu.cn/~twcourse/BigNumber.html

#include <iostream>
#include <string.h>

// 位數
#define LEN 100

using namespace std;

void Input(int n[])
{
    // 初始化 n[] = 0
    for (int i = 0; i < LEN; i++) {
        n[i] = 0;
    }

    // 輸入string
    char s[LEN];
//  cin.getline(s, LEN);
    cin >> s;

    // 取得字串長度
    int l = strlen(s);

    // reverse反轉 倒著放回n[]
    for (int i = 0; i < l; i++) {
        n[i] = s[l - i - 1] - '0';
    }

}

void Add(int a[], int b[], int c[])
{
    // 先每一位都加起來
    for (int i = 0; i < LEN; i++) {
        c[i] = a[i] + b[i];
    }

    // 超過10的就進位, 最後一位不進位
    for (int i = 0; i<LEN - 1; i++) {
        // 當這一位大於10
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10; // 上一位(更大的那位)加上 這一位除十
            c[i] = c[i] % 10; // 這一位變成除十的餘數
        }
    }
}
void Mul(int a[], int b[], int c[])
{
    // 初始化答案
    for (int i = 0; i < LEN * 2; i++) {
        c[i] = 0;
    }

    // 乘法
    for (int i = 0; i<LEN; i++) {
        for (int j = 0; j<LEN; j++) {
            c[i + j] += a[j] * b[i];
            // 進位
            if (c[i + j] >= 10) {
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] = c[i + j] % 10;
            }
        }
    }
}

void Print(int n[])
{
    int i;

    // 從陣列最後面找到第一個不為零的數 = i
    for (i = LEN - 1; i > 0; i--) {
        if (n[i] != 0) {
            break;
        }
    }

    // 由右往左依序印出來
    for (; i >= 0; i--) {
        cout << n[i];
    }
    cout << endl;
}
void Print2(int n[])
{
    int i;

    // 從陣列最後面找到第一個不為零的數 = i
    for (i = LEN*2 - 1; i > 0; i--) {
        if (n[i] != 0) {
            break;
        }
    }

    // 由右往左依序印出來
    for (; i >= 0; i--) {
        cout << n[i];
    }
    cout << endl;
}


int main()
{
    int a[LEN], b[LEN], c[LEN*2];
    Input(a);
    Input(b);

    // a + b = c
    Add(a, b, c);
    Print(c);

    // a * b = c
    Mul(a, b, c);
    Print2(c);

    cin.get();
    return 0;
}

