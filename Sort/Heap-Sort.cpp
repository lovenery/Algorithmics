#include <iostream>

using namespace std;

void heap(int *a, int root, int length) {
  int leftChildIndex = root * 2 + 1;  // root的左下元素
  int rightChildIndex = root * 2 + 2; // root的右下元素
  int maxNode = -1;

  // 找出最大的節點是root還是樹枝
  maxNode = root;
  if (leftChildIndex < length && a[leftChildIndex] > a[root]) {
    maxNode = leftChildIndex;
  }
  if (rightChildIndex < length && a[rightChildIndex] > a[maxNode]) {
    maxNode = rightChildIndex;
  }

  // 如果最大值不是root,交換root跟元素得值,並遞迴向下做heap
  if (maxNode != root) {
    swap(a[root], a[maxNode]);
    heap(a, maxNode, length);
  }
}

void heapSort(int *a, int length) {
  cout << "初始陣列: ";
  for (int i = 0; i < length; i++) {
    cout << a[i] << " ";
  }

  // 二元樹有floor(n/2)個節點
  // 由最後面的節點做堆積, -1是因為頂端的index是0
  // if length = 10 , i = 4,3,2,1,0
  for (int i = length / 2 - 1; i >= 0; i--) {
    heap(a, i, length);
  }

  cout << endl << "最大堆積: ";
  for (int i = 0; i < length; i++) {
    cout << a[i] << " ";
  }

  // 排序
  // length越來越短, -1是因為頂端的index是0
  for (int i = length - 1; i > 0; i--) {
    swap(a[0], a[i]); // 將最大值換到最後面
    heap(a, 0, i);    // 再做堆積
  }

  cout << endl << "堆積排序: ";
  for (int i = 0; i < length; i++) {
    cout << a[i] << " ";
  }
}

int main() {

  int arr[10] = {14, 51, 92, 79, 45, 2, 75, 70, 3, 57};

  heapSort(arr, 10);

  return 0;
}

// Sample Output
// 初始陣列: 14 51 92 79 45 2 75 70 3 57
// 最大堆積: 92 79 75 70 57 2 14 51 3 45
// 堆積排序: 2 3 14 45 51 57 70 75 79 92
