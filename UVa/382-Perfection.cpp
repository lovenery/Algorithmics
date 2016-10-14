// UVa 382 Perfection
#include <iostream>

using namespace std;

void printPerfect(int n)
{
    int sum = 0;
    for (int i=1 ; i<n ; i++ )
    {
        if(n%i==0)
        {
            sum += i;
        }
    }
    if(n == sum)
    {
        cout<<n<<" ";
    }
}

int main()
{
    // 輸入 幾個數字
    int num_i; // number of input
    cin>>num_i;

    // 輸入 數字
    int *data = new int[num_i];
    for(int i = 0; i < num_i ; i++)
    {
        cin>>data[i];
    }

    // 處理
    for (int i = 0 ; i < num_i ; i++)
    {
        printPerfect(data[i]);
    }

    return 0;
}