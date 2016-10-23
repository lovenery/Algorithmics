#include <iostream>

using namespace std;

void printArray(int *a, int length) {
  for (int i = 0; i < length; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void print2DArray(int **a, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < 10; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void radixSort(int *data, int length) {

  int count[length]; // 記錄每個桶子裝了幾個數值

  int **buckets = new int *[10]; // row 10個桶子代表0~9

  // 初始化桶子
  for (int i = 0; i < length; i++) {
    buckets[i] = new int[length]; // col 桶子的容量
    count[i] = 0;                 // 桶子一開始是空的
  }

  int MAXradix = 100;           // 基數的上限
  int dataIndex = 0, radix = 1; // radix = 1, 10, 100,...

  // 若基數沒有超過上限
  while (radix <= MAXradix) {
    // 分配每個數字要進哪個桶子
    for (int i = 0; i < length; i++) {
      int LSD = (data[i] / radix) % 10; // 計算資料該放哪一個桶子 0~9
      buckets[LSD][count[LSD]] = data[i]; // 資料放到桶子
      count[LSD]++;                       // 該桶子的數量加一
    }
    radix *= 10; // 更新基底：1->10, 10->100

    // 將桶子的資料合併, 放回去原本的陣列
    dataIndex = 0; // 原本陣列的Index
    for (int i = 0; i < 10; i++) {
      if (count[i] != 0) { // 如果桶子中有資料
        for (int j = 0; j < count[i]; j++) {
          data[dataIndex++] = buckets[i][j];
        }
      }
      count[i] = 0; // 歸零再給下一個while使用
    }
  }
}

int main() {

  int arr[12] = {111, 14, 51, 92, 79, 45, 2, 75, 70, 3, 57, 112};

  printArray(arr, 12);
  radixSort(arr, 12);
  printArray(arr, 12);

  return 0;
}
