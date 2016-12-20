// alg week11
#include <iostream>
using namespace std;

int main()
{
    int num_i = 1;
    cin >> num_i;
    for (int i = 0; i < num_i; i++)
    {
        int input = 9000;
        cin >> input;
        int sum = 0;
        int index = 1;
        for (index = 1; sum <= input; index++)
        {
            sum += index;
        }
        cout << sum - input << " " << index - 1 << endl;
    }

    system("pause");
    return 0;
}
/*
Sample input
2
6
10

Sample output
4 4
5 5
*/
