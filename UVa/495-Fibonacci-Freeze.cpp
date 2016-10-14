// UVa 495 Fibonacci Freeze
#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        int a = 1;
        int b = 1;
        int c = 0;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main()
{
    // the number of input
    int num_i;
    cin >> num_i;

    // input data
    int *data = new int[num_i];
    for (int i = 0; i < num_i; i++)
    {
        cin >> data[i];
    }

    // print ans
    for (int i = 0; i < num_i; i++)
    {
        cout<<fibonacci(data[i])<<endl;
    }

    system("pause");
    return 0;
}