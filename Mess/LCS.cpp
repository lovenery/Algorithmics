#include <iostream>
#include <string> // getline
using namespace std;

void print_LCS(int i, int j, string s1, int** dir) {
    // 第一個或第二個 sequence 為空的的時候就可停止了
    if (i == 0 || j == 0) return;

    if (dir[i][j] == 3)
    {
        print_LCS(i - 1, j - 1, s1, dir);
        cout << s1[i - 1];  // 印出 LCS 的元素
    }
    else if (dir[i][j] == 2)
        print_LCS(i - 1, j, s1, dir);
    else if (dir[i][j] == 1)
        print_LCS(i, j - 1, s1, dir);
}

void LCS(string s1, string s2, int** array , int** dir) {
    // 左 = 1
    // 上 = 2
    // 左上 = 3
    for (string::size_type i = 1; i <= s1.size(); i++) {
        for (string::size_type j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
            {
                array[i][j] = array[i - 1][j - 1] + 1;
                dir[i][j] = 3;
            }
            else
            {
                // 左較大 指左
                if (array[i - 1][j] < array[i][j - 1])
                {
                    array[i][j] = array[i][j - 1];
                    dir[i][j] = 1;
                }
                // 上較大 指上
                else
                {
                    array[i][j] = array[i - 1][j];
                    dir[i][j] = 2;
                }
            }
        }
    }

    // Debug
    //for (int i = 0; i <= s1.size(); i++)
    //{
    //  for (int j = 0; j <= s2.size(); j++)
    //  {
    //      cout << array[i][j] << " ";
    //  }
    //  cout << endl;
    //}
    cout << array[s1.size()][s2.size()] << endl;
}

int main()
{
    int num_input = 1;
    cin >> num_input;
    // prototype : istream& ignore (streamsize n = 1, int delim = EOF);
    cin.ignore(); // 會去掉最後面1個字元\n 
    for (int i = 0; i < num_input; i++)
    {
        string s1 = "1123123";
        string s2 = "111233";
        getline(cin, s1); // istream& getline (istream& is, string& str);
        getline(cin, s2);

        // pointer 2d array ref : http://www.cplusplus.com/forum/articles/7459/
        // 存數字
        int **p2DArray;
        p2DArray = new int*[s1.size() + 1];
        for (int i = 0; i <= s1.size(); ++i) {
            p2DArray[i] = new int[s2.size() + 1];
        }
        // 存方向
        int **direction;
        direction = new int*[s1.size() + 1];
        for (int i = 0; i <= s1.size(); ++i) {
            direction[i] = new int[s2.size() + 1];
        }

        // 初始化 最左最上等於0
        for (int i = 0; i <= s1.size(); i++)
        {
            p2DArray[i][0] = 0;
        }
        for (int i = 0; i <= s2.size(); i++)
        {
            p2DArray[0][i] = 0;
        }

        // 解題
        LCS(s1, s2, p2DArray, direction);
        print_LCS(s1.size(), s2.size(), s1, direction);

        // Free Memory
        for (int i = 0; i <= s1.size(); ++i) {
            delete[] p2DArray[i];
        }
        delete[] p2DArray;
        for (int i = 0; i <= s1.size(); ++i) {
            delete[] direction[i];
        }
        delete[] direction;

    }

    system("pause");
    return 0;
}
