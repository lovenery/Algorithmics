//#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int sum = 0;
int fuck_min = 2147483647;
// 排列組合 參考: https://home.gamer.com.tw/creationDetail.php?sn=2113843
void perm(int *ch, int a, int b, int first, int target, int N, int* matrix)
{
    if (a == b)
    {
        if (ch[0] == first) {
            for (int i = 0; i<N; i++) {
                //cout << ch[i];
                // 加對角線
                sum += matrix[ch[i] + N*ch[i]];
                // 如果到目標了
                if (ch[i] == target)
                {
                    break;
                }
                // 線斷了
                if (matrix[ch[i] * N + ch[i + 1]] < 0)
                {
                    sum = 2147483647;
                    break;
                }
                // 在最後一個時,不超出邊界
                if (i+1 < N)
                {
                    sum += matrix[ch[i]*N + ch[i + 1]];
                }
            }
            // 存最小值
            if (sum < fuck_min)
            {
                fuck_min = sum;
            }
            //cout << sum << endl;
            // 給下一輪使用
            sum = 0;
        }
    }
    else {
        for (int j = a; j<N; j++)
        {
            swap(ch[a], ch[j]);
            perm(ch, a + 1, b, first, target, N, matrix);
            swap(ch[a], ch[j]);
        }
    }
}

int main()
{
    // 點
    int N = 4;
    cin >> N;

    // 邊
    int M = 6;
    cin >> M;

    // 欲知點數
    int K = 3;
    cin >> K;

    // 輸入點成本
    int* point = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> point[i];
    }

    // 輸入邊成本
    int* edge = new int[M * 3];
    for (int i = 0; i < M*3; i+=3)
    {
        cin >> edge[i] >> edge[i + 1] >> edge[i + 2];
    }

    // 相對矩陣法
    // 初始化
    int* matrix = new int[N*N];
    for (int i = 0; i < N*N; i++)
    {
        matrix[i] = -1;
    }
    // 對角
    for (int i = 0; i < N; i++)
    {
        matrix[i + N*i] = point[i];
    }
    for (int i = 0; i < M * 3; i += 3)
    {
        matrix[(edge[i] - 1) + N*(edge[i + 1] - 1)] = edge[i + 2];
        matrix[(edge[i + 1] - 1) + N*(edge[i] - 1)] = edge[i + 2];
    }
    // 印出矩陣
    //for (int i = 0; i<N; i++)
    //{
    //  for (int j = 0; j<N; j++)
    //  {
    //      cout << setw(3) << matrix[i * N + j] << " ";
    //  }
    //  cout << endl;
    //}
    //cout << endl;

    // 輸入欲知點
    int* know = new int[K * 2];
    for (int i = 0; i < K*2; i+=2)
    {
        cin >> know[i] >> know[i + 1];
    }

    // 0,1,2...N-1
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }

    // 解所有欲知點
    for (int i = 0; i < K * 2; i += 2)
    {
        perm(arr, 0, N - 1, know[i] - 1, know[i + 1] - 1, N, matrix);
        cout << fuck_min << endl;
        fuck_min = 2147483647;
    }

    //system("pause");
    return 0;
}

/*
Input
4
6
3
5
8
7
3
1 2 13
1 3 20
1 4 4
2 3 9
2 4 5
3 4 7
1 3
2 4
1 2
*/

/*
Output
26
16
25
*/
