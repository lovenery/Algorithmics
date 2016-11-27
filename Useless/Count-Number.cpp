// 數數字 Alg week7
#include <iostream>
#include <math.h>
using namespace std;

void countNumber(double input, int num) {
    double pre_edge = input;
    int ceil_edge = (int)ceil(pre_edge / 2);
    int edge = (int)pre_edge;

    // array:edge*edge
    int **array = new int*[edge];
    for (int i = 0; i < edge; i++) {
        array[i] = new int[edge];
    }

    // 填滿二維陣列
    for (int times = 0; times < ceil_edge; times++) // times: 數字兼次數
    {
        // 填滿一個正方形
        for (int i = times; i < edge - times; i++)
        {
            for (int j = times; j < edge - times; j++)
            {
                array[i][j] = times + 1;
            }
        }
    }

    int count = 0;
    // 列與和
    for (int i = 0; i < edge * 2; i++)
    {
        // 窮舉
        for (int k = 0; k <= i; k++)
        {
            for (int l = 0; l <= i; l++)
            {
                if (k + l == i && (i & 1) && k < edge && l < edge) // 和等於i && 奇數 && 不超出最大index
                {
                    //cout << l << "," << k << " ";
                    if (++count == num)
                    {
                        cout << array[l][k] << endl;
                    }
                }
                else if (k + l == i && !(i & 1) && k < edge && l < edge) // 和等於i && 偶數 && 不超出最大index
                {
                    //cout << k << "," << l << " ";
                    if (++count == num)
                    {
                        cout << array[k][l] << endl;
                    }
                }
            }
        }
        //cout << endl;
    }
}

int main()
{
    int num_i = 1;
    double edge = 7;
    int num = 11;
    cin >> num_i;
    for (int i = 0; i < num_i; i++)
    {
        cin >> edge;
        cin >> num;
        countNumber(edge, num);
    }

    system("pause");
    return 0;
}

/*
Sample input
3
7 11
3 5
4 9

Sample output
1
2
2
*/
