// UVa 11462 Age Sort
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num_i;
    while (true)
    {

        // 輸入 幾個人
        cin>>num_i;
        if (num_i==0)
        {
            break;
        }

        // 輸入 數量
        int *data = new int[num_i];
        for (int i = 0; i < num_i ; i++)
        {
            cin>>data[i];
        }

        // 排序
        sort(data, data+num_i);

        // 印
        for (int i = 0; i < num_i ; i++ )
        {
            if( i > 0 )
            {
                cout<<" ";
            }
            cout<<data[i];
        }
        cout<<endl;

        delete[] data;
    }

    return 0;
}