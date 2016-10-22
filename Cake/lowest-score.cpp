#include <iostream>
using namespace std;

void lowest(int *p, int length) {
    int *class_a = new int[length];
    int *class_b = new int[length];
    int num_a = 0, num_b = 0;
    bool flag = true;
    for (int i = 0; i < length; i++)
    {
        if (flag)
        {
            class_a[num_a++] = p[i];
        }
        else
        {
            class_b[num_b++] = p[i];
        }
        if (flag && p[i] > p[i + 1])
        {
            flag = false;
        }
    }

    // 終點標記
    class_a[num_a] = 101;
    class_b[num_b] = 101;

    int low_a = 0, low_b = 0;
    for (int i = 0; i < 3; i++)
    {
        if (class_a[low_a] <= class_b[low_b] && i < num_a)
        {
            //cout << class_a[low_a++];
            low_a++;
            cout << "A";
        }
        else if(class_a[low_a] > class_b[low_b] && i < num_b)
        {
            //cout << class_b[low_b++];
            low_b++;
            cout << "B";
        }
    }
    cout << endl;
}

int main()
{
    int times;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        int num_people;
        cin >> num_people;
        int *people = new int[num_people];
        for (int i = 0; i < num_people; i++)
        {
            cin >> people[i];
        }
        lowest(people, num_people);
    }

    system("pause");
    return 0;
}
#include "stdafx.h"
#include <iostream>
using namespace std;

void lowest(int *p, int length) {
    int *class_a = new int[length];
    int *class_b = new int[length];
    int num_a = 0, num_b = 0;
    bool flag = true;
    for (int i = 0; i < length; i++)
    {
        if (flag)
        {
            class_a[num_a++] = p[i];
        }
        else
        {
            class_b[num_b++] = p[i];
        }
        if (flag && p[i] > p[i + 1])
        {
            flag = false;
        }
    }

    // 終點標記
    class_a[num_a] = 101;
    class_b[num_b] = 101;

    int low_a = 0, low_b = 0;
    for (int i = 0; i < 3; i++)
    {
        if (class_a[low_a] <= class_b[low_b] && i < num_a)
        {
            //cout << class_a[low_a++];
            low_a++;
            cout << "A";
        }
        else if(class_a[low_a] > class_b[low_b] && i < num_b)
        {
            //cout << class_b[low_b++];
            low_b++;
            cout << "B";
        }
    }
    cout << endl;
}

int main()
{
    int times;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        int num_people;
        cin >> num_people;
        int *people = new int[num_people];
        for (int i = 0; i < num_people; i++)
        {
            cin >> people[i];
        }
        lowest(people, num_people);
    }

    system("pause");
    return 0;
}
