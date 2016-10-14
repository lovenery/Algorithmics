// UVa 10591 Happy Number
#include <iostream>
#include <time.h>
using namespace std;

char* isHappy(int n)
{
    int sum = 0;

    // 執行直到 n<=9
    while(true)
    {
        if(n<=9)
        {
            sum=n;
            break;
        }
        while(n!=0) // n一直除十 最後會等於0 跳出
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
//        cout<<sum<<",";
        n=sum;
        sum=0;
    }

    // 和是1就是快樂數!
    // 2~9只有7是快樂數
    if (sum==1 || sum==7)
    {
        return "Happy";
    }
    else
    {
        return "Not Happy";
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
        cout << isHappy(data[i]) << endl;
    }

//    double START,END;
//    START = clock();
//    some code
//    END = clock();
//    cout << endl << "進行運算所花費的時間：" << (END - START) << " ms" << endl;
//    cout << endl << "程式執行所花費：" << (double)clock()/CLOCKS_PER_SEC << " S";

    return 0;
}