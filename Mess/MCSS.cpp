// Maximum Subarray, Maximum Contiguous Subsequence Sum (MCSS)
// 最大連續子序列 (非空)
#include <iostream>
using namespace std;

// 窮舉
void mcss1(int *s, int length) {
    int sum = 0;
    int msl = 0, msr = 0;
    // 產生所有可能子序列 0~n-1
    for (int i = 0; i < length; i++)
    {
        // 產生所有可能子序列 0~n-1
        for (int j = 0; j < length; j++)
        {
            int temp = 0;
            // 計算所有可能子序列的和 i~j
            for (int k = i; k <= j; k++)
            {
                temp += s[k];
                if (temp > sum)
                {
                    sum = temp;
                    msl = i;
                    msr = j;
                }
            }
        }
    }
    cout << sum;
}

// 窮舉2
void mcss2(int *s, int length) {
    int sum = 0;
    int msl = 0, msr = 0;
    // 子序列的開頭 s[i]
    for (int i = 0; i < length; i++)
    {
        int temp = 0;
        // 子序列的開頭 s[j], s[i]+...+s[j]
        for (int j = i; j < length; j++)
        {
            temp += s[j];
            if (temp > sum)
            {
                sum = temp;
                msl = i;
                msr = j;
            }
        }
    }
    cout << sum;
}

// divide and conquer
int mcss(int *s, int left, int right) {

    // 結束條件
    if (left == right)
    {
        return left;
    }

    // middle
    int mid = (left + right) / 2;

    // 取得左邊最大和 max sum for left
    int msl = mcss(s, left, mid);

    // 取得右邊最大和 max sum  for right
    int msr = mcss(s, mid + 1, right);

    // 中間到左
    // max sum for boundary to left
    int mbl = 0;
    int temp = 0;
    for (int i = mid; i >= left; i--)
    {
        temp += s[i];
        if (temp > mbl)
        {
            mbl = temp;
        }
    }

    // 中間到右
    // max sum for boundary to right
    int mbr = 0;
    temp = 0;
    for (int i = mid+1; i <= right; i++)
    {
        temp += s[i];
        if (temp > mbr)
        {
            mbr = temp;
        }
    }

    // 看是 左邊 右邊 橫跨 哪個大
    //return max(msl, msr, mbl + mbr);
    if (msl > msr && msl > mbl + mbr)
    {
        return msl;
    }
    else if (msr > msl && msr > mbl + mbr)
    {
        return msr;
    }
    else
    {
        return mbl + mbr;
    }
}

/*
M[1] = A[1]
M[2] = Max (A[2], A[1] + A[2]) = Max (A[2], A[2] + M[1])
M[3] = Max (A[3], A[2] + A[3], A[1] + A[2] + A[3]) =
       Max (A[3], A[3] + Max (A[2], A[1] + A[2])) =
       Max (A[3], A[3] + M[2])

M[j] = Max (A[j], A[j] + M[j-1])
*/
void mcss_dynamic(int* A, int n) {
    // index 0 ~ n-1
    int *M = new int[n];
    int *b = new int[n];

    M[0] = A[0]; // 結尾是第一個元素
    int max = M[0]; // 目前最大值

    b[0] = 0; // 紀錄第一個元素index
    int k = 0; // 紀錄結尾index

    // 每個字都掃過一次, j=當前結尾
    for (int j = 1; j < n; j++)
    {
        // M[j] = Max (A[j], A[j] + M[j-1])
        if (M[j-1] > 0) // M[j-1] + A[j] > A[j] 等同 M[j-1] > 0
        {
            // 繼續延長序列
            M[j] = M[j-1] + A[j];
            b[j] = b[j-1]; // 把開頭值繼續放到這個結尾
        }
        // M[j-1] + A[j] <= A[j]
        else
        {
            // 新的序列開頭在位置j
            M[j] = A[j];
            b[j] = j;
        }

        // 更新最大值和紀錄結尾
        if (M[j] > max)
        {
            max = M[j];
            k = j;
        }
    }

    cout <<  "MCSS value = " << max << " starts at " << b[k] << " ends at " << k;
}

int main()
{

    int num = 1; // run times
    int sequence[10] = { 13, -11, -3, 9, -19, -5, 19, -12 ,20, 5 };
    // {19,-12,20,5} = 32

//    cin >> num;
    for (int n = 0; n < num; n++)
    {
        cout << "MCSS 請輸入十個數字: " << endl;
        for (int i = 0; i < 10; i++)
        {
            cin >> sequence[i];
        }
        //mcss1(sequence, 10);
        //mcss2(sequence, 10);
        //cout << mcss(sequence, 0, 9) << endl;
        mcss_dynamic(sequence, 10);
    }

    //system("pause");
    return 0;
}
