// UVa 299 - Train Swapping
#include <iostream>

using namespace std;

void print_bubble_swap_times(int* a, int length) {
    int count = 0;
    bool flag = true;
    for (int i = length-1; i > 0 && flag; i--)
    {
        flag = false;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1]) {
                flag = true;
                swap(a[j], a[j + 1]);
                count++;
            }
        }
    }
    cout << "Optimal swapping takes " << count << " swaps." << endl;

    //for (int i = 0; i < length; i++)
    //{
    //  cout << a[i] << " ";
    //}
}

int main()
{

    // the number of input
    int num_i;
    cin >> num_i;

    int data[50];
    int length;
    for (int i = 0; i < num_i; i++)
    {
        cin >> length;
        for (int j = 0; j <length; j++)
        {
            cin >> data[j];
        }
        print_bubble_swap_times(data, length);
    }

    return 0;
}
