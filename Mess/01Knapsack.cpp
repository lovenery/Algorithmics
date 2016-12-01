// alg week8 0/1背包問題
#include <iostream>
#include <algorithm>
using namespace std;

void knapsack(int W, int* weight, int* value) {
    // table
    int **V;
    V = new int*[5 + 1];
    for (int i = 0; i <= 5 + 1; ++i) {
        V[i] = new int[W + 1];
    }
    // 記住哪個元素放進背包
    //int **keep;
    //keep = new int*[5 + 1];
    //for (int i = 0; i <= 5 + 1; ++i) {
    //  keep[i] = new int[W + 1];
    //}

    // 初始化
    for (int w = 0; w <= W; w++)
    {
        V[0][w] = 0;
    }

    // write table
    for (int i = 1; i <= 5; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // 沒記住時的if
            if (weight[i] <= w)
            {
                V[i][w] = max(V[i - 1][w], value[i] + V[i - 1][w - weight[i]]);
            }
            // 有記住時的if
            //if (weight[i] <= w && value[i] + V[i - 1][w - weight[i]] > V[i - 1][w])
            //{
            //  V[i][w] = max(V[i - 1][w], value[i] + V[i - 1][w - weight[i]]);
            //  keep[i][w] = 1;
            //}
            else
            {
                V[i][w] = V[i - 1][w];
                //keep[i][w] = 0;
            }
        }
    }

    // 印出記住
    //int K = W;
    //for (int i = 5; i >= 1; i--)
    //{
    //  if (keep[i][K] == 1)
    //  {
    //      cout << "第i個物品放入背包: " << i << endl;
    //      K -= weight[i];
    //  }
    //}

    cout << "背包總價值為: " << V[5][W] << endl;
}

int main()
{
    int num_i = 1;
    //cin >> num_i;
    for (int i = 0; i < num_i; i++)
    {
        // 固定5個物品
        int W = 10;
        int weight[6] = { -1, 3, 1, 4, 2, 5 }; // [0] 不用
        int value[6] = { -1, 7, 10, 9, 4, 8 }; // [0] 不用
        //cin >> W;
        //for (int i = 1; i <= 5; i++)
        //{
        //  cin >> weight[i];
        //}
        //for (int i = 1; i <= 5; i++)
        //{
        //  cin >> value[i];
        //}
        knapsack(W, weight, value);
    }

    system("pause");
    return 0;
}

/*
Sample input
3
10
3 1 4 2 5
7 10 9 4 8
17
7 4 8 7 12
3 2 1 4 7
38
12 7 32 5 21
8 5 19 8 14

Sample output
30
9
30
*/
