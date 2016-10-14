// UVa 612 DNA Sorting
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void print_number_sort(string a[], int row, int col) {
    char line[50]; // a row
    int count_line[50]; // count for every row
    int count = 0;

    // foreach every row
    for (int i = 0; i < row; i++)
    {
        strcpy(line, a[i].c_str());

        // counting
        for (int k = 0; k < col - 1; k++)
        {
            for (int l = k; l < col; l++)
            {
                if (line[k] > line[l]) {
                    count++;
                }
            }
        }

        //cout << line[j] - '0' << " ";
        count_line[i] = count;
        count = 0; // 為下回合
    }
    
    // bubble sort
    for (int i = row - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (count_line[j] > count_line[j + 1])
            {
                swap(count_line[j], count_line[j + 1]);
                swap(a[j], a[j + 1]);
            }
        }
    }

    // print result
    for (int i = 0; i < row; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}

int main()
{

    // the number of input
    int num_i;
    cin >> num_i;

    int col, row;
    string data[100];
    for (int i = 0; i < num_i; i++)
    {
        cin >> col >> row;
        //cin.ignore();

        for (int j = 0; j < row; j++)
        {
            //getline(cin, data[j]);
            getline(cin >> std::ws, data[j]); // ">> std::ws" == "cin.ignore();"
        }

        print_number_sort(data, row, col);

    }


    cin.get();
    return 0;
}