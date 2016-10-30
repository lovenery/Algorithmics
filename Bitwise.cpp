#include <iostream>

using namespace std;

int main() {
  cout << "AND Operator：" << endl;
  cout << "0 AND 0 = " << (0 & 0) << endl;
  cout << "0 AND 1 = " << (0 & 1) << endl;
  cout << "1 AND 0 = " << (1 & 0) << endl;
  cout << "1 AND 1 = " << (1 & 1) << endl;
  cout << endl;

  cout << "OR Operator：" << endl;
  cout << "0 OR 0 = " << (0 | 0) << endl;
  cout << "0 OR 1 = " << (0 | 1) << endl;
  cout << "1 OR 0 = " << (1 | 0) << endl;
  cout << "1 OR 1 = " << (1 | 1) << endl;
  cout << endl;

  cout << "XOR Operator：" << endl;
  cout << "0 XOR 0 = " << (0 ^ 0) << endl;
  cout << "0 XOR 1 = " << (0 ^ 1) << endl;
  cout << "1 XOR 0 = " << (1 ^ 0) << endl;
  cout << "1 XOR 1 = " << (1 ^ 1) << endl;
  cout << "9 XOR 1 = " << (9 ^ 1) << endl; // 1001 XOR 0001 = 1000
  cout << endl;

  cout << "NOT Operator：" << endl;
  cout << "NOT 0 = " << (!0) << endl;
  cout << "NOT 1 = " << (!1) << endl;
  cout << endl;

  cout << "補數：" << endl;
  cout << "~ 0 = " << (~0) << endl; // ~0000 = 1111(-1)
  cout << "~ 1 = " << (~1) << endl; // ~0001 = 1110(-2)
  cout << endl;

  cout << "判斷是否奇數(和1做and)：" << endl;
  cout << "21&1 ?" << (21 & 1 ? 'Y' : 'N') << endl;
  cout << endl;

  char num = 64;
  cout << "ASCII 小老鼠：" << num << endl;
  cout << "~64 = " << static_cast<int>(~num) << endl;

  return 0;
}
