// alg week13 sequence
#include <iostream>

using namespace std;

int main() {
  int num = 1;
  cin >> num;

  for (int i = 0; i < num; i++) {
    int length = 4;
    cin >> length;

    int *data = new int[length];
    for (int i = 0; i < length; i++) {
      cin >> data[i];
    }

    bool flag = true;
    for (int i = 0; i < length; i++) {
      for (int j = i + 1; j < length; j++) {
        for (int k = i + 2; k < length; k++) {
          if (data[i] + data[j] == data[k]) {
            flag = false;
          }
        }
      }
    }

    if (flag) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }

  return 0;
}
