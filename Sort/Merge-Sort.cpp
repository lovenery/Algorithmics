#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Merge(int *A, int p, int q, int r)
{
    int n1 = q - p + 1; // p ~ q 長度
    int n2 = r - q; // q+1 ~ r 長度
    
    // 存左邊跟右邊
    int *L = new int[n1 + 1];
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    int *R = new int[n2 + 1];
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[(q + 1) + i];
    }

    // 終點標記, 為了其中一邊如果全部做完後, 剩下的那邊直接放
    L[n1] = 2147483647;
    R[n2] = 2147483647;

    // 合併: L跟R中較小的放到A
    int L_index = 0;
    int R_index = 0;
    // 跑p ~ r
    for (int i = p; i <= r; i++)
    {
        // 左邊數列小於等於右邊數列
        if (L[L_index] <= R[R_index])
        {
            A[i] = L[L_index];
            L_index++;
        }
        // 左邊數列大於右邊數列
        else
        {
            A[i] = R[R_index];
            R_index++;
        }
    }
    //return A;
}

void MergeSort(int *A, int p, int r)
{
    // p=r表示陣列只有一個元素
    if (p == r)
    {
        return;
    }

    int q = (p + r) / 2; // 分成 p~q 及 q+1~r
    MergeSort(A, p, q);
    MergeSort(A, q + 1, r);
    Merge(A, p, q, r);

    //return A;
}

void print(int data[], int length)
{
    for (int i = 0; i<length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    srand(time(NULL));
    #define LEN 17
    int length = LEN;
    int data[LEN];
    for (int i = 0; i<length; i++)
    {
        data[i] = rand() % 100 + 1;
    }
    print(data, length);


    MergeSort(data, 0, length - 1);
    print(data, length);


    cin.get();
    return 0;
}
