// UVa 583 Prime Factors
#include <iostream>

using namespace std;

int main()
{

    // input
    int input;
    cin >> input;
    cout << input << "=";

    int power;
    for (int i = 2; i <= input; i++)
    {
        power = 0;
        while (input%i == 0) // if input%i==0, i is a factor
        {
            power++;
            input /= i; // input = input / factor
            // input%i != 0, break while and print
            if (input%i != 0) {
                if (power == 1) {
                    cout << i;
                }
                if (power > 1)
                {
                    cout << i << "^" << power;
                }
                // check if the last
                if (input != 1) {
                    cout << "*";
                }
            }
        }
    }

    system("pause");
    return 0;
}

// 短除法
//for (int i = 2; i <= input; i++)
//{
//  while (input%i == 0)
//  {
//      cout << i << "*";
//      input /= i;
//  }
//}