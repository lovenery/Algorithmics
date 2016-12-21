// alg week11
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Matrix
{
    int name; // 節點名稱
    int stage;
    char one, two, three; // 可擴張的節點名稱
    int edge1, edge2, edge3; // 到可擴張節點的成本
    int value; // 評估函數之值
    int history; // 歷史紀錄 預設都是0
    Matrix( char n = '0',
            int s = -1,
            char o = '0', int e1 = 0,
            char t = '0', int e2 = 0,
            char e = '0', int e3 = 0,
            int v = 2147483647 , int h = 0)
        :name(n), stage(s), one(o), edge1(e1), two(t), edge2(e2), three(e), edge3(e3), value(v), history(h) {};
};

// 最小的放上面 priority queue最上面
struct compare {
    bool operator()(Matrix l, Matrix r) {
        return (l.value > r.value);
    }
};

int main()
{
    map<char, Matrix> Map;
    Map.clear();
    string arr = "SABCDEFGHIT";
    int tmp1, tmp2, tmp3;
    // stage 1
    for (int i = 0; i <= 0; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        Map[arr[i]] = Matrix(arr[i], 1 ,'A', tmp1, 'B', tmp2, 'C', tmp3);
    }
    // stage 2
    for (int i = 1; i <= 3; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        Map[arr[i]] = Matrix(arr[i], 2, 'D', tmp1, 'E', tmp2, 'F', tmp3);
    }
    // stage 3
    for (int i = 4; i <= 6; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        Map[arr[i]] = Matrix(arr[i], 3, 'G', tmp1, 'H', tmp2, 'I', tmp3);
    }
    // stage 4
    for (int i = 7; i <= 9; i++)
    {
        cin >> tmp1;
        Map[arr[i]] = Matrix(arr[i], 4 ,'T', tmp1);
    }
    // stage 5
    for (int i = 10; i <= 10; i++)
    {
        Map[arr[i]] = Matrix(arr[i], 5);
    }

    // 輸入想要的stage
    int stage = 3;
    cin >> stage;

    // debug
    //for (int i = 0; i < arr.size(); i++)
    //{
    //  cout << arr[i] << " ";
    //  cout << Map[arr[i]].one << Map[arr[i]].edge1;
    //  cout << Map[arr[i]].two << Map[arr[i]].edge2;
    //  cout << Map[arr[i]].three << Map[arr[i]].edge3;
    //  cout << endl;
    //}

    priority_queue<Matrix, vector<Matrix>, compare> q;
    q.push(Map['S']);
    
    bool visited = false;
    while (true)
    {
        // 擴展
        Matrix tmp = q.top();
        q.pop();
        char one = tmp.one;
        char two = tmp.two;
        char three = tmp.three;

        // 第一個節點
        if (one != '0')
        {
            // 此節點的擴展誰比較小
            /////
            int tmp1 = 2147483647, tmp2 = 2147483647, tmp3 = 2147483647;
            if (Map[one].edge1 != 0)
            {
                tmp1 = Map[one].edge1;
            }
            if (Map[one].edge2 != 0)
            {
                tmp2 = Map[one].edge2;
            }
            if (Map[one].edge3 != 0)
            {
                tmp3 = Map[one].edge3;
            }
            int real_min = min(min(tmp1, tmp2), tmp3);
            if (Map[one].edge1 == 0 && Map[one].edge2 == 0 && Map[one].edge3 == 0)
            {
                real_min = 0;
            }
            /////

            // 歷史紀錄
            Matrix clone = Map[one]; // 複製此節點
            clone.history += Map[tmp.name].edge1;
            clone.history += tmp.history;
            
            // 評估函數
            int value = clone.history + real_min;
            if (Map[one].value >= value)
            {
                q.push(clone);
                Map[one].value = value;
            }

            // 結束條件
            if (one == 'T')
            {
                visited = true;
                break;
            }
        }
        if (two != '0')
        {
            int tmp1 = 2147483647, tmp2 = 2147483647, tmp3 = 2147483647;
            if (Map[two].edge1 != 0)
            {
                tmp1 = Map[two].edge1;
            }
            if (Map[two].edge2 != 0)
            {
                tmp2 = Map[two].edge2;
            }
            if (Map[two].edge3 != 0)
            {
                tmp3 = Map[two].edge3;
            }
            int real_min = min(min(tmp1, tmp2), tmp3);
            if (Map[two].edge1 == 0 && Map[two].edge2 == 0 && Map[two].edge3 == 0)
            {
                real_min = 0;
            }
            Matrix clone = Map[two];
            clone.history += Map[tmp.name].edge2;
            clone.history += tmp.history;
            int value = clone.history + real_min;
            if (Map[two].value >= value)
            {
                Map[two].value = value;
                q.push(clone);
            }
        }
        if (three != '0')
        {
            int tmp1 = 2147483647, tmp2 = 2147483647, tmp3 = 2147483647;
            if (Map[three].edge1 != 0)
            {
                tmp1 = Map[three].edge1;
            }
            if (Map[three].edge2 != 0)
            {
                tmp2 = Map[three].edge2;
            }
            if (Map[three].edge3 != 0)
            {
                tmp3 = Map[three].edge3;
            }
            int real_min = min(min(tmp1, tmp2), tmp3);
            if (Map[three].edge1 == 0 && Map[three].edge2 == 0 && Map[three].edge3 == 0)
            {
                real_min = 0;
            }
            Matrix clone = Map[three];
            clone.history += Map[tmp.name].edge3;
            clone.history += tmp.history;
            int value = clone.history + real_min;
            if (Map[three].value >= value)
            {
                Map[three].value = value;
                q.push(clone);
            }
        }
    }

    // 全部跑完後 印出結果
    if (stage == 2)
    {
        cout << min(min(Map['A'].value, Map['B'].value), Map['C'].value);
    }
    if (stage == 3)
    {
        cout << min(min(Map['D'].value, Map['E'].value), Map['F'].value);
    }
    if (stage == 4)
    {
        cout << min(min(Map['G'].value, Map['H'].value), Map['I'].value);
    }
    if (stage == 5)
    {
        cout << Map['T'].value;
    }
    
    //system("pause");
    return 0;
}

/*
Sample input
1
2
3
6
5
4
7
8
9
12
11
10
13
14
15
18
17
16
19
20
21
24
23
22
3

Sample output
20 ps:(1+6+13)
*/
