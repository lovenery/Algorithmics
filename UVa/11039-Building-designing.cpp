// UVa 11039 - Building designing
// 更聰明的方法 : http://blog.csdn.net/yucan1219/article/details/23655173
#include <iostream>
#include <algorithm>
using namespace std;

void building(int *b, int length) {
    // splice to two array
    int *blue = new int[length];
    int *red = new int[length];
    int num_blue = 0, num_red = 0;
    for (int i = 0; i < length; i++)
    {
        if (b[i] > 0)
        {
            blue[num_blue++] = b[i];
        }
        else if (b[i] < 0)
        {
            red[num_red++] = b[i];
        }
    }

    // sort
    sort(blue, blue + num_blue);
    reverse(blue, blue + num_blue); // 8,7,6,5...
    sort(red, red + num_red); // -8,-7,-6...

    // result of the building
    int *result = new int[length + 1];
    result[0] = 1000000;
    int ans1, ans2;

    // ans1, blue first
    int index_blue = 0, index_red = 0;
    int i = 0;
    while (1)
    {
        // blue[index_blue] < result[i]
        while (blue[index_blue] >= abs(result[i]) && index_blue < num_blue)
        {
            index_blue++;
        }
        if (blue[index_blue] < abs(result[i]) && index_blue < num_blue)
        {
            result[++i] = blue[index_blue++];
        }
        else
        {
            break;
        }

        // abs(red[index_red]) < result[i]
        while (abs(red[index_red]) >= result[i] && index_red < num_red)
        {
            index_red++;
        }
        if (abs(red[index_red]) < result[i] && index_red < num_red)
        {
            result[++i] = red[index_red++];
        }
        else
        {
            break;
        }
    }
    ans1 = i;

    // ans2, red first
    index_blue = 0, index_red = 0;
    i = 0;
    while (1)
    {
        // abs(red[index_red]) < result[i]
        while (abs(red[index_red]) >= result[i] && index_red < num_red)
        {
            index_red++;
        }
        if (abs(red[index_red]) < result[i] && index_red < num_red)
        {
            result[++i] = red[index_red++];
        }
        else
        {
            break;
        }

        // blue[index_blue] < result[i]
        while (blue[index_blue] >= abs(result[i]) && index_blue < num_blue)
        {
            index_blue++;
        }
        if (blue[index_blue] < abs(result[i]) && index_blue < num_blue)
        {
            result[++i] = blue[index_blue++];
        }
        else
        {
            break;
        }
    }
    ans2 = i;

    // output real ans
    if (ans1 > ans2)
    {
        cout << ans1 << endl;
    }
    else
    {
        cout << ans2 << endl;
    }
}

int main()
{
    int times;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        int num_build;
        cin >> num_build;
        int *build = new int[num_build];
        for (int i = 0; i < num_build; i++)
        {
            cin >> build[i];
        }
        building(build, num_build);
    }

    system("pause");
    return 0;
}
