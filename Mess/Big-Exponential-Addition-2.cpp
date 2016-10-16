// ref:
// http://it-easy.tw/c-super-large-power/
// http://dhcp.tcgs.tc.edu.tw/c/p018.htm

#include<iostream>
using namespace std;

#define LEN 1506

void Print(int n[])
{
    int i;

    // 從陣列最後面找到第一個不為零的數 = i
    for (i = LEN - 1; i > 0; i--)
    {
        if (n[i] != 0)
        {
            break;
        }
    }

    // 由右往左依序印出來
    for (; i >= 0; i--)
    {
        cout << n[i];
    }
    cout << endl;
}

void Add(int a[], int b[], int c[])
{
    // 先每一位都加起來
    for (int i = 0; i < LEN; i++)
    {
        c[i] = a[i] + b[i];
    }

    // 超過10的就進位, LEN-1最高位不進位
    for (int i = 0; i<LEN - 1; i++)
    {
        // 當這一位大於10
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10; // 上一位(更大的那位)加上 這一位除十
            c[i] = c[i] % 10; // 這一位變成除十的餘數
        }
    }
}

void cal_exp2(int arr[], int power)
{
    int n,m,v,s; //n是底數；m是指數；v是進位暫存變數；s用來記錄整數位數
    // 原
    //cout << "請輸入二整數n,m，本程式將計算n^m: ";
    //cin >> n >> m;
    n = 2;
    // 原
    //cout << "請輸入整數m，本程式將計算2^m: ";
    //cin >> m;
    m = power;
    //
    int x[LEN]= {0}; // 計算用
    v=0; // 清空v的值
    s=1; // 不管怎麼樣，s必會大於等於1，因為整數一定有位數
    x[0]=1; // 先讓最早要乘的這格陣列值等於1
    // 要乘m次 所以迴圈1~m
    for(int a=1; a<=m; a++)
    {
        // 每一整數位數都乘 n, 跑0 ~ s-1次(1~s次)
        for(int i=0; i<s; i++)
        {
            x[i]=x[i]*n+v; // 各個位數運算式，v是有進位時要加上去的
            v=x[i]/10; // v若大於0，則需進位
            x[i]=x[i]%10; // 每格陣列存一位數
            if(v!=0&&i+1==s) // 判斷位數是否+1
            {
                s++; //記錄整數位數
            }
        }
    }

    // 反向輸出答案
//    cout << "值：" ;
//    for(int b=s-1; b>=0; b--) //反向輸出
//    {
//        cout << x[b];
//    }
//    cout << endl;
//    cout << "共" << s << "個位數" << endl;

    // 答案複製回傳進來的陣列備用
    for(int i = 0; i < LEN; i++)
    {
        arr[i] = x[i];
    }

}

int main()
{
    int number_of_input;
    cin >> number_of_input;

    int m,n;
    for(int i = 0; i < number_of_input; i++)
    {
        cin >> m >> n;

        int a1[LEN] = {0};
        int a2[LEN] = {0};
        int ans[LEN];

        cal_exp2(a1, m);
        cal_exp2(a2, n);
        // ans = a1 + a2
        Add(a1, a2, ans);
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
