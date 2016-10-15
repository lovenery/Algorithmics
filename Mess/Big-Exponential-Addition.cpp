#include <iostream>
#include <string.h>
#include <math.h>

#define LEN 1506

using namespace std;

void Add(int a[], int b[], int c[])
{
    // 先每一位都加起來
    for (int i = 0; i < LEN; i++) {
        c[i] = a[i] + b[i];
    }

    // 超過10的就進位, LEN-1最高位不進位
    for (int i = 0; i<LEN - 1; i++) {
        // 當這一位大於10
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10; // 上一位(更大的那位)加上 這一位除十
            c[i] = c[i] % 10; // 這一位變成除十的餘數
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

void init(int n[], int p)
{
    // 初始化 n[] = 0
    for (int i = 0; i < LEN; i++) {
        n[i] = 0;
    }

    // 最大2^9=512 三位數
    int s[3] = {0};
    s[0] = p % 10;
    s[1] = (p % 100 - s[0]) / 10;
    s[2] = (p % 1000 - s[0] - s[1]) / 100;

    // 倒著放回n[]
    for (int i = 0; i < 3; i++) {
        n[i] = s[i];
    }

}

void mul_1024(int n[]) {

    // 初始化
    int result[LEN];
    for (int i = 0; i < LEN ; i++) {
        result[i] = 0;
    }

    // 開始乘
    int tmp;
    for (int i = 0; i<4; i++) {
        if (i == 0)
        {
            tmp = 4;
        }
        if (i == 1)
        {
            tmp = 2;
        }
        if (i == 2)
        {
            continue;
        }
        if (i == 3)
        {
            tmp = 1;
        }
        // 減三是怕爆
        for (int j = 0; j < LEN - 3; j++) {
            result[i + j] += n[j] * tmp;
            if (result[i + j] >= 10) {
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] = result[i + j] % 10;
            }
        }
    }

    // 乘完放回原陣列
    for (int i = 0; i < LEN; i++) {
        n[i] = result[i];
    }

}

void exp2(int n[], int power) {

    // 初始化 2的9次方以下
    int left = pow(2, power % 10);
    init(n, left);

    // 要乘幾次1024
    int length = power / 10;
    for (int i = 0; i < length; i++) {
        mul_1024(n);
    }
}

int main()
{
    int num_i, m, n;
    cin >> num_i;

    for (int i = 0; i < num_i; i++)
    {
        cin >> m >> n;
        int first_exp[LEN], second_exp[LEN], ans[LEN];
        exp2(first_exp, m);
        exp2(second_exp, n);
        Add(first_exp, second_exp, ans);
        Print(ans);
    }

    cin.get();
    return 0;
}

/*
2^m + 2^n

SAMPLE INPUT
3
12 13
20 14
140 115

SAMPLE OUTPUT
12288
1064960
1393796616446538814624603420284493227884544
*/
