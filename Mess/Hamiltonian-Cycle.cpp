// alg week10 
// ref: http://www.sanfoundry.com/cpp-program-find-hamiltonian-cycle/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void printSolution(int path[], int length)
{
    cout << "Solution Exists: Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < length; i++)
        cout << path[i] << "  ";
    cout << path[0] << endl;
}

/*
* check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle
*/
bool isSafe(int v, bool **graph, int path[], int pos)
{
    // 這個邊沒有連接
    if (graph[path[pos - 1]][v] == 0)
        return false;
    // 這個點已經走過了
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

/* solve hamiltonian cycle problem */
bool hamCycleUtil(bool **graph, int path[], int pos, int length)
{
    // 當遞迴到最後一點時, 檢查是否正確
    if (pos == length)
    {
        if (graph[path[pos - 1]][path[0]] == 1) // 檢查最後一點是否跟開頭一樣
            return true;
        else
            return false;
    }

    // 從第一個點到最後一個遞迴窮舉, 直到走完為止
    for (int v = 1; v < length; v++)
    {
        if (isSafe(v, graph, path, pos)) // 檢查是否可走
        {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, length) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

/* solves the Hamiltonian Cycle problem using Backtracking.*/
bool hamCycle(bool **graph, int length)
{
    int *path = new int[length]; // 記錄走過的點之名字
    // 初始化
    for (int i = 0; i < length; i++) {
        path[i] = -1;
    }
    path[0] = 0; // 第一個走的是 0
    // 因為第一個走的是0, 所以從第二個點(1)開始走, 最後會回傳bool判斷有無解
    if (hamCycleUtil(graph, path, 1, length) == false)
    {
        //cout << "\nSolution does not exist" << endl;
        cout << "False" << endl;
        return false;
    }
    //printSolution(path, length);
    cout << "True" << endl;
    return true;
}

int main()
{
    int num_i = 1;
    cin >> num_i;
    for (int i = 0; i < num_i; i++)
    {
        int edges = 6;
        cin >> edges;

        // init declare
        bool **graph = new bool*[edges];
        for (int i = 0; i < edges; i++)
        {
            graph[i] = new bool[edges];
        }
        // init to 0
        for (int i = 0; i < edges; i++)
        {
            for (int j = 0; j < edges; j++)
            {
                graph[i][j] = false;
            }
        }

        cin.ignore();
        int maxPoint = 0;
        for (int i = 0; i < edges; i++)
        {
            std::string input = "(1,4)";
            getline(cin, input);
            std::istringstream ss(input.substr(1, input.size() - 2)); // 去頭去尾
            std::string token = "";
            int row, col;
            // get row
            if (std::getline(ss, token, ','))
            {
                std::stringstream to_int(token);
                to_int >> row;
            }
            // get col
            if (std::getline(ss, token, ','))
            {
                std::stringstream to_int(token);
                to_int >> col;
            }
            graph[row - 1][col - 1] = true;
            graph[col - 1][row - 1] = true;

            // 最大的點, 當陣列要跑幾次
            maxPoint = max(maxPoint, row);
            maxPoint = max(maxPoint, col);
        }

        // debug
        //for (int i = 0; i < edges; i++)
        //{
        //  for (int j = 0; j < edges; j++)
        //  {
        //      cout << graph[i][j] << " ";
        //  }
        //  cout << endl;
        //}

        hamCycle(graph, maxPoint);
    }

    system("pause");
    return 0;
}

/*
Sample input
2
6
(1,4)
(1,5)
(2,3)
(2,5)
(3,4)
(3,5)
6
(1,2)
(2,3)
(3,4)
(3,6)
(4,5)
(5,6)

Sample output
True
False
*/
