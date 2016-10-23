#include <iostream>

using namespace std;

int BinarySearch(int *A, int left, int right, int target) {
  int mid;
  // left <= right index 就繼續
  while (left <= right) {
    mid = (left + right) / 2;
    if (target == A[mid]) {
      return mid; // return 答案索引
    } else {
      if (target > A[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return -1;
}

int main() {

  int arr[10] = {14, 51, 92, 79, 45, 2, 75, 70, 93, 57};
  sort(arr, arr + 10);
  int index = BinarySearch(arr, 0, 9, 92);
  cout << "index: " << index << endl;

  return 0;
}
