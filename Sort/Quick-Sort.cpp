#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 中間當 Pivot
void quickSort_center(int *a,int left,int right)
{
    int i = left, j = right;
    int tmp; // for swaping
    int pivot = a[(left + right) / 2];

    /* partition */
    while (i <= j) // i>j stop
    {
        while (a[i] < pivot) // left partition,a[i]>=pivot,then stop
            i++;
        while (a[j] > pivot) // right partition,a[i]<=pivot,then stop
            j--;
        if (i <= j) // i>j can't swap
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */ // now i>j -> new partition: (left,j),(i,right)
    if (left < j)
        quickSort_center(a, left, j);
    if (i < right)
        quickSort_center(a, i, right);
}

// 以data[left]為Pivot，left相當於最左邊第一個元素
void quickSort_left(int data[], int left, int right){
    if(left < right){
        int i=left+1;
        int j=right;
        while(true){
            // 向右找大於Pivot的數值的位置
            // data[i] > data[left] stop
            while(i <= right){
                if(data[i] > data[left]) {
                    break;
                }
                i++;
            }

            // 向左找小於Pivot的數值的位置
            // data[j] < data[left] stop
            while(j > left){
                if(data[j] < data[left]){
                    break;
                }
                j--;
            }

            // 若i,j的位置交叉
            //     代表範圍內，Pivot右邊已無比Pivot小的數值
            //     代表範圍內，Pivot左邊已無比Pivot大的數值
            if(i > j){
                break;
            }

            // 將比Pivot大的數值換到右邊，比Pivot小的數值換到左邊
            swap(data[i], data[j]);
        }
        swap(data[left], data[j]);    // 將Pivot移到中間
        quickSort_left(data, left, j-1);    // 對左子串列進行快速排序
        quickSort_left(data, j+1, right);   // 對右子串列進行快速排序
    }
}

// 右邊當Pivot
void quickSort_right(int data[], int left, int right){
    if (left >= right){
        return;
    }
    int i = left, j = right-1;
    int pivot = right;

    while (i <= j){ // i>j stop

        while(i < right && data[i] <= data[pivot]){
//            if(data[i] > data[pivot]) {
//                break;
//            }
            i++;
        }

        while(j >= left && data[j] >= data[pivot]){
//            if(data[j] < data[pivot]){
//                break;
//            }
            j--;
        }

        if (i <= j) // if i>j can't swap
        {
            swap(data[i], data[j]);
        }
    }

    swap(data[pivot], data[i]);    // 將Pivot移到中間
    quickSort_right(data, left, i-1);    // 對左子串列進行快速排序
    quickSort_right(data, i+1, right);   // 對右子串列進行快速排序
}

void print(int data[], int length){
    for(int i=0; i<length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl << endl;
}

int main(){

    srand(time(NULL));
    int length = 17;
    int data[length];
    for(int i=0; i<length; i++)
    {
        data[i]=rand()%100+1;
    }
    print(data, length);


    quickSort_right(data,0,length-1);
    print(data, length);


    quickSort_left(data,0,length-1);
    print(data, length);


    quickSort_center(data,0,length-1);
    print(data, length);


    return 0;
}
